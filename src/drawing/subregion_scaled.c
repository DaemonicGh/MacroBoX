/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subregion_scaled.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:41:38 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 14:30:08 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_drawing.h"
#include "modules/mbx_utils.h"

static void	set_subregion_upscaled(t_mbx_region *restrict region,
	t_mbx_region *restrict src, t_vec2ix4 bounds, t_vec2 scale)
{
	const t_vec2i	scale_up = vec2i(trunc_up(scale.x), trunc_up(scale.y));
	const int		incr_y = bounds.p4.y * src->size.x;
	t_vec2			xy;
	t_vec2i			uv;

	xy.y = bounds.p1.y;
	uv.y = bounds.p3.y * src->size.x;
	while (xy.y < bounds.p2.y)
	{
		xy.x = bounds.p1.x;
		uv.x = uv.y + bounds.p3.x;
		while (xy.x < bounds.p2.x)
		{
			mbx_set_rect(region, vec2i_vd(xy), scale_up,
				mbx_get_pixel_unsafe_i(src, uv.x));
			xy.x += scale.x;
			uv.x += bounds.p4.x;
		}
		xy.y += scale.y;
		uv.y += incr_y;
	}
}

static void	set_subregion_downscaled(t_mbx_region *restrict region,
	t_mbx_region *restrict src, t_vec2ix3 bounds, t_vec2x2 uv_scale)
{
	const t_vec2	rscale = vec2_div(vec2_vi(bounds.p3), uv_scale.p2);
	t_vec2i			xy;
	t_vec2			uv;

	xy.y = bounds.p1.y;
	uv.y = uv_scale.p1.y;
	while (xy.y < bounds.p2.y)
	{
		xy.x = bounds.p1.x;
		uv.x = (int)uv.y * src->size.x + uv_scale.p1.x;
		while (xy.x < bounds.p2.x)
		{
			mbx_set_pixel_unsafe(region, xy,
				mbx_get_pixel_unsafe_i(src, uv.x));
			xy.x ++;
			uv.x += rscale.x;
		}
		xy.y ++;
		uv.y += rscale.y;
	}
}

static void	clear_size_scale(t_vec2ix3 *pos_uv_wh, t_vec2 *scale)
{
	if (scale->x < 0)
	{
		pos_uv_wh->p1.x += abs(pos_uv_wh->p3.x) * scale->x;
		pos_uv_wh->p3.x = -pos_uv_wh->p3.x;
		scale->x = -scale->x;
	}
	if (scale->y < 0)
	{
		pos_uv_wh->p1.y += abs(pos_uv_wh->p3.y) * scale->y;
		pos_uv_wh->p3.y = -pos_uv_wh->p3.y;
		scale->y = -scale->y;
	}
	if (pos_uv_wh->p3.x < 0)
	{
		pos_uv_wh->p1.x -= pos_uv_wh->p3.x * scale->x;
		pos_uv_wh->p2.x -= pos_uv_wh->p3.x + 1;
	}
	if (pos_uv_wh->p3.y < 0)
	{
		pos_uv_wh->p1.y -= pos_uv_wh->p3.y * scale->y;
		pos_uv_wh->p2.y -= pos_uv_wh->p3.y + 1;
	}
}

static t_vec2i	set_limits(
	t_vec2ix2 *lim, t_vec2ix3 pos_uv_wh, t_vec2 scale)
{
	t_vec2i		start;

	*lim = vec2ix2(pos_uv_wh.p1, pos_uv_wh.p1);
	if (pos_uv_wh.p3.x < 0)
		lim->p1.x += pos_uv_wh.p3.x * scale.x;
	else
		lim->p2.x += pos_uv_wh.p3.x * scale.x;
	if (pos_uv_wh.p3.y < 0)
		lim->p1.y += pos_uv_wh.p3.y * scale.y;
	else
		lim->p2.y += pos_uv_wh.p3.y * scale.y;
	if (scale.x <= 1 || scale.y <= 1)
		return (vec2i(max(lim->p1.x, 0), max(lim->p1.y, 0)));
	start = lim->p1;
	if (start.x < -scale.x)
		start.x = fmod(start.x, scale.x);
	if (start.y < -scale.y)
		start.y = fmod(start.y, scale.y);
	return (start);
}

void	mbx_set_subregion_scaled(t_mbx_region *restrict region,
	t_mbx_region *restrict src, t_vec2ix3 pos_uv_wh, t_vec2 scale)
{
	t_vec2ix2		lim;
	t_vec2i			start;
	t_vec2i			end;
	t_vec2i			iter;
	t_vec2			uv;

	if (scale.x == 0 || scale.y == 0)
		return ;
	clear_size_scale(&pos_uv_wh, &scale);
	start = set_limits(&lim, pos_uv_wh, scale);
	end = vec2i(
			min(lim.p2.x, region->size.x),
			min(lim.p2.y, region->size.y));
	iter = vec2i_sign(pos_uv_wh.p3);
	uv = vec2_add(vec2_vi(pos_uv_wh.p2),
			vec2_div(vec2_vi(vec2i_mult(vec2i_sub(start, lim.p1),
						iter)), scale));
	if (scale.x <= 1 || scale.y <= 1)
		set_subregion_downscaled(region, src,
			vec2ix3(start, end, iter), vec2x2(uv, scale));
	else
		set_subregion_upscaled(region, src,
			vec2ix4(start, end, vec2i_vd(uv), iter), scale);
}
