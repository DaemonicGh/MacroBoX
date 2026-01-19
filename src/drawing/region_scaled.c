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
#include "../../includes/modules/mbx_drawing.h"
#include "../../includes/modules/mbx_color.h"
#include "../../includes/modules/mbx_math.h"
#include "../../VecLibC/includes/modules/veclc_vec2.h"
#include "../../VecLibC/includes/modules/veclc_vec2i.h"

static void	set_region_int_scaled(t_mbxregion *region, t_mbxregion *src,
	t_vec2i pos, t_vec2i scale)
{
	const t_vec2ix2	bounds = vec2ix2_xy(
			max(0, -pos.x / abs(scale.x)), max(0, -pos.y / abs(scale.y)),
			min(src->size.x, (region->size.x - pos.x) / abs(scale.x) + 1),
			min(src->size.y, (region->size.y - pos.y) / abs(scale.y) + 1));
	int				x;
	int				y;

	x = bounds.p1.x;
	while (x < bounds.p2.x)
	{
		y = bounds.p1.y;
		while (y < bounds.p2.y)
		{
			mbx_set_region_rect(region, vec2i(
					pos.x + x * scale.x, pos.y + y * scale.y), scale,
				mbx_get_region_pixel_xy(src, x, y));
			y++;
		}
		x++;
	}
}

static void	set_region_float_scaled(t_mbxregion *region, t_mbxregion *src,
	t_vec2i pos, t_vec2 scale)
{
	const t_vec2ix2	bounds = vec2ix2_xy(
			max(0, pos.x), max(0, pos.y),
			clamp(pos.x + src->size.x * scale.x, -1, region->size.x),
			clamp(pos.y + src->size.y * scale.y, -1, region->size.y));
	const t_vec2i	dir = vec2i(fsignf(scale.x), fsignf(scale.y));
	int				x;
	int				y;

	x = bounds.p1.x;
	while (x != bounds.p2.x)
	{
		y = bounds.p1.y;
		while (y != bounds.p2.y)
		{
			mbx_set_region_pixel_unsafe_xy(region, x, y,
				mbx_get_region_pixel_xy(
					src, (x - pos.x) / scale.x, (y - pos.y) / scale.y));
			y += dir.y;
		}
		x += dir.x;
	}
}

void	mbx_set_region_region_scaled(t_mbxregion *region, t_mbxregion *src,
	t_vec2i pos, t_vec2 scale)
{
	if (scale.x == 0 || scale.y == 0)
		return ;
	if (is_integer(scale.x) && is_integer(scale.y))
		set_region_int_scaled(region, src, pos, vec2_to_vec2i(scale));
	else
		set_region_float_scaled(region, src, pos, scale);
}

void	mbx_set_region_scaled(t_mbx *mbx, t_mbxregion *region,
	t_vec2i pos, t_vec2 scale)
{
	mbx_set_region_region_scaled(&mbx->viewport, region, pos, scale);
}
