/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   region_scaled.c                                    :+:      :+:    :+:   */
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
	t_mbx_region *restrict src, t_vec2ix3 start_end_uv, t_vec2 scale)
{
	const t_vec2i	xy_scale_up = vec2i(ceil(scale.x), ceil(scale.y));
	t_vec2			xy;
	int				row;
	int				i;

	xy.y = start_end_uv.p1.y;
	row = start_end_uv.p3.y * src->size.x;
	while (xy.y < start_end_uv.p2.y)
	{
		xy.x = start_end_uv.p1.x;
		i = row + start_end_uv.p3.x;
		while (xy.x < start_end_uv.p2.x)
		{
			mbx_set_rect(region, vec2_to_vec2i(xy), xy_scale_up,
				mbx_get_pixel_unsafe_i(src, i));
			xy.x += scale.x;
			i++;
		}
		xy.y += scale.y;
		row += src->size.x;
	}
}

static void	set_subregion_downscaled(t_mbx_region *restrict region,
	t_mbx_region *restrict src, t_vec2ix2 start_end, t_vec2x2 uv_scale)
{
	t_vec2i		xy;
	double		row;
	double		i;

	xy.y = start_end.p1.y;
	row = uv_scale.p1.y;
	while (xy.y < start_end.p2.y)
	{
		xy.x = start_end.p1.x;
		i = (int)row * src->size.x + uv_scale.p1.x;
		while (xy.x < start_end.p2.x)
		{
			mbx_set_pixel_unsafe(region, xy,
				mbx_get_pixel_unsafe_i(src, i));
			xy.x++;
			i += uv_scale.p2.x;
		}
		xy.y++;
		row += uv_scale.p2.y;
	}
}

static t_vec2i	invert_scale_pos(t_vec2ix3 *pos_uv_wh, t_vec2 *scale)
{
	t_vec2i	pos;

	pos = pos_uv_wh->p1;
	if (pos_uv_wh->p3.x < 0)
	{
		pos.x -= pos_uv_wh->p3.x * scale->x;
		scale->x = -scale->x;
	}
	if (pos_uv_wh->p3.y < 0)
	{
		pos.y -= pos_uv_wh->p3.y * scale->y;
		scale->y = -scale->y;
	}
	return (pos);
}

void	mbx_set_subregion_scaled(t_mbx_region *restrict region,
	t_mbx_region *restrict src, t_vec2ix3 pos_uv_wh, t_vec2 scale)
{
	const t_vec2i	pos = invert_scale_pos(&pos_uv_wh, &scale);
	const t_vec2ix2	start_end = vec2ix2(
			vec2i_clamp(pos, vec2i_zero(), region->size),
			vec2i_clamp(
				vec2i_add(pos, vec2i_mult_vd(vec2i_abs(pos_uv_wh.p3), scale)),
				vec2i_neg(vec2_to_vec2i(scale)), region->size));
	const t_vec2	uv = vec2(
			pos_uv_wh.p2.x + fabs((pos.x - start_end.p1.x) / scale.x),
			pos_uv_wh.p2.y + fabs((pos.y - start_end.p1.y) / scale.y));

	if (scale.x == 0 || scale.y == 0)
		return ;
	if (max(abs((int)scale.x), abs((int)scale.y)) > 1)
		set_subregion_upscaled(region, src, vec2ix3(
				vec2i_sub(start_end.p1, vec2_to_vec2i(vec2_mult(vec2_sub(
								uv, vec2((int)uv.x, (int)uv.y)), scale))),
				start_end.p2, vec2_to_vec2i(uv)), scale);
	else
		set_subregion_downscaled(region, src, start_end,
			vec2x2(uv, vec2_div_rd(1.0, scale)));
}

void	mbx_set_region_scaled(t_mbx_region *restrict region,
	t_mbx_region *restrict src, t_vec2i pos, t_vec2 scale)
{
	mbx_set_subregion_scaled(region, src,
		vec2ix3(pos, vec2i_zero(), src->size),
		scale);
}
