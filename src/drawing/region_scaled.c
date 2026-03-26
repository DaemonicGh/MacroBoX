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

#include <stdlib.h>

#include "veclc.h"
#include "modules/mbx_drawing.h"
#include "modules/mbx_utils.h"

static void	set_subregion_scaled(t_mbx_region *restrict region,
	t_mbx_region *restrict src, t_vec2ix3 bounds, t_vec2 scale)
{
	const t_vec2i	scale_up = vec2i(trunc_up(scale.x), trunc_up(scale.y));
	t_vec2			xy;
	t_vec2i			uv;
	int				i;

	xy.y = bounds.p1.y;
	uv.y = bounds.p2.y;
	i = bounds.p2.y * src->size.x + bounds.p2.x;
	while (uv.y < bounds.p3.y)
	{
		xy.x = bounds.p1.x;
		uv.x = bounds.p2.x;
		while (uv.x < bounds.p3.x)
		{
			mbx_set_rect(region, vec2_to_vec2i(xy), scale_up,
				mbx_get_pixel_unsafe_i(src, i));
			xy.x += scale.x;
			uv.x++;
			i++;
		}
		xy.y += scale.y;
		uv.y++;
		i += src->size.x - (bounds.p3.x - bounds.p2.x);
	}
}

static t_vec2i	set_invertable_pos(t_vec2ix3 *pos_uv_wh, t_vec2 *scale)
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

static t_vec2i	get_xy_min(
	t_vec2i pos, t_vec2i size, t_vec2 scale, t_vec2 ascale)
{
	t_vec2i	xy_min;

	xy_min = pos;
	if (pos.x < -ascale.x)
		xy_min.x = fmod(pos.x, scale.x);
	else if (pos.x > size.x + ascale.x)
		xy_min.x = size.x + fmod(pos.x - size.x, scale.x);
	if (pos.y < -ascale.y)
		xy_min.y = fmod(pos.y, scale.y);
	else if (pos.y > size.y + ascale.y)
		xy_min.y = size.y + fmod(pos.y - size.y, scale.y);
	return (xy_min);
}

void	mbx_set_region_scaled(t_mbx_region *restrict region,
	t_mbx_region *restrict src, t_vec2i pos, t_vec2 scale)
{
	const t_vec2	ascale = vec2_abs(scale);
	t_vec2ix3		bounds;

	if (scale.x == 0 || scale.y == 0)
		return ;
	bounds.p1 = get_xy_min(pos, region->size, scale, ascale);
	bounds.p2 = vec2i(
			abs(bounds.p1.x - pos.x) / ascale.x,
			abs(bounds.p1.y - pos.y) / ascale.y);
	bounds.p3 = vec2i(
			(clamp(pos.x + src->size.x * scale.x,
					-ascale.x, region->size.x + ascale.x)
				- pos.x) / scale.x,
			(clamp(pos.y + src->size.y * scale.y,
					-ascale.y, region->size.y + ascale.y)
				- pos.y) / scale.y);
	set_subregion_scaled(region, src, bounds, scale);
}

void	mbx_set_subregion_scaled(t_mbx_region *restrict region,
	t_mbx_region *restrict src, t_vec2ix3 pos_uv_wh, t_vec2 scale)
{
	const t_vec2	ascale = vec2_abs(scale);
	t_vec2ix3		bounds;
	t_vec2i			pos;

	if (scale.x == 0 || scale.y == 0)
		return ;
	pos = set_invertable_pos(&pos_uv_wh, &scale);
	bounds.p1 = get_xy_min(pos, region->size, scale, ascale);
	bounds.p2 = vec2i_add(pos_uv_wh.p2, vec2i(
				abs(bounds.p1.x - pos.x) / ascale.x,
				abs(bounds.p1.y - pos.y) / ascale.y));
	bounds.p3 = vec2i_add(pos_uv_wh.p2, vec2i(
				(clamp(pos.x + abs(pos_uv_wh.p3.x) * scale.x,
						-ascale.x, region->size.x + ascale.x)
					- pos.x) / scale.x,
				(clamp(pos.y + abs(pos_uv_wh.p3.y) * scale.y,
						-ascale.y, region->size.y + ascale.y)
					- pos.y) / scale.y));
	set_subregion_scaled(region, src, bounds, scale);
}
