/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   region_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 00:38:02 by rprieur           #+#    #+#             */
/*   Updated: 2026/06/17 00:38:02 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_drawing.h"
#include "modules/mbx_utils.h"

static void	set_subregion_transformed(t_mbx_region *restrict region,
	t_mbx_region *restrict src, const t_vec2i bounds[5], t_vec2x2 step)
{
	t_vec2i			xy;
	t_vec2			row;
	t_vec2			uv;

	row.x = bounds[2].x * step.p1.x + bounds[2].y * step.p2.x;
	row.y = bounds[2].x * step.p1.y + bounds[2].y * step.p2.y;
	xy.y = bounds[0].y;
	while (xy.y < bounds[1].y)
	{
		uv = row;
		xy.x = bounds[0].x;
		while (xy.x < bounds[1].x)
		{
			if (uv.x >= bounds[3].x && uv.x < bounds[4].x
				&& uv.y >= bounds[3].y && uv.y < bounds[4].y)
				mbx_set_pixel_unsafe(region, xy,
					mbx_get_pixel_unsafe(src, vec2i_vd(uv)));
			uv = vec2_add(uv, step.p1);
			xy.x++;
		}
		row = vec2_add(row, step.p2);
		xy.y++;
	}
}

static t_vec2ix2	get_bound_indices(t_vec2x2 transform)
{
	t_vec2ix2		bounds;

	bounds = vec2ix2_xy(0b00, 0b00, 0b11, 0b11);
	if (transform.p1.x < 0)
	{
		bounds.p1.x ^= 0b01;
		bounds.p2.x ^= 0b01;
	}
	if (transform.p1.y < 0)
	{
		bounds.p1.y ^= 0b01;
		bounds.p2.y ^= 0b01;
	}
	if (transform.p2.x < 0)
	{
		bounds.p1.x ^= 0b10;
		bounds.p2.x ^= 0b10;
	}
	if (transform.p2.y < 0)
	{
		bounds.p1.y ^= 0b10;
		bounds.p2.y ^= 0b10;
	}
	return (bounds);
}

static	t_vec2ix3	get_bounds(t_mbx_region *restrict region,
	t_vec2ix3 pos_uv_wh, t_vec2x2 transform)
{
	const t_vec2ix2	idx = get_bound_indices(transform);
	t_vec2ix4		points;
	t_vec2ix3		bounds;

	points.p1 = vec2i_zero();
	points.p2 = vec2i_vd(vec2_mult_d(transform.p1, pos_uv_wh.p3.x));
	points.p3 = vec2i_vd(vec2_mult_d(transform.p2, pos_uv_wh.p3.y));
	points.p4 = vec2i_add(points.p2, points.p3);
	bounds.p1.x = pos_uv_wh.p1.x + points.v[idx.p1.x].x;
	bounds.p1.y = pos_uv_wh.p1.y + points.v[idx.p1.y].y;
	bounds.p3.x = points.v[idx.p1.x].x - min(bounds.p1.x, 0);
	bounds.p3.y = points.v[idx.p1.y].y - min(bounds.p1.y, 0);
	bounds.p1.x = max(bounds.p1.x - pos_uv_wh.p2.x, 0);
	bounds.p1.y = max(bounds.p1.y - pos_uv_wh.p2.y, 0);
	bounds.p2.x = min(pos_uv_wh.p1.x + points.v[idx.p2.x].x, region->size.x);
	bounds.p2.y = min(pos_uv_wh.p1.y + points.v[idx.p2.y].y, region->size.y);
	return (bounds);
}

static void	fix_negative_wh(t_vec2ix3 *pos_uv_wh, t_vec2x2 *transform)
{
	if (pos_uv_wh->p3.x < 0)
	{
		pos_uv_wh->p3.x = -pos_uv_wh->p3.x;
		pos_uv_wh->p1 = vec2i_add(pos_uv_wh->p1,
				vec2i_vd(vec2_mult_d(transform->p1, pos_uv_wh->p3.x)));
		transform->p1 = vec2_neg(transform->p1);
	}
	if (pos_uv_wh->p3.y < 0)
	{
		pos_uv_wh->p3.y = -pos_uv_wh->p3.y;
		pos_uv_wh->p1 = vec2i_add(pos_uv_wh->p1,
				vec2i_vd(vec2_mult_d(transform->p2, pos_uv_wh->p3.y)));
		transform->p2 = vec2_neg(transform->p2);
	}
}

void	mbx_set_subregion_transformed(t_mbx_region *restrict region,
	t_mbx_region *restrict src, t_vec2ix3 pos_uv_wh, t_vec2x2 transform)
{
	double		det;
	t_vec2x2	step;
	t_vec2ix3	comp_bounds;
	t_vec2i		bounds[5];

	fix_negative_wh(&pos_uv_wh, &transform);
	det = transform.p1.x * transform.p2.y - transform.p1.y * transform.p2.x;
	step.p1 = vec2_div_d(vec2(transform.p2.y, -transform.p1.y), det);
	step.p2 = vec2_div_d(vec2(-transform.p2.x, transform.p1.x), det);
	comp_bounds = get_bounds(region, pos_uv_wh, transform);
	bounds[0] = comp_bounds.p1;
	bounds[1] = comp_bounds.p2;
	bounds[2] = comp_bounds.p3;
	bounds[3] = pos_uv_wh.p2;
	bounds[4] = vec2i_add(pos_uv_wh.p2, pos_uv_wh.p3);
	set_subregion_transformed(region, src, bounds, step);
}
