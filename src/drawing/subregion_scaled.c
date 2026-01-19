/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subregion_scaled.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:41:38 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 14:31:03 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/mbx_drawing.h"
#include "../../includes/modules/mbx_color.h"
#include "../../includes/modules/mbx_math.h"
#include "../../VecLibC/includes/modules/veclc_vec2.h"

static void	set_subregion_int_scaled(t_mbxregion *region, t_mbxregion *src,
	t_vec2ix3 posuvwh, t_vec2i scale)
{
	const t_vec2ix2	bounds = vec2ix2_xy(
			max(0, posuvwh.p2.x), max(0, posuvwh.p2.y),
			clamp(posuvwh.p2.x + posuvwh.p3.x, -1, src->size.x),
			clamp(posuvwh.p2.y + posuvwh.p3.y, -1, src->size.y));
	const t_vec2i	dir = vec2i(fsignf(scale.x), fsignf(scale.y));
	int				x;
	int				y;

	x = bounds.p1.x;
	while (x != bounds.p2.x)
	{
		y = bounds.p1.y;
		while (y != bounds.p2.y)
		{
			mbx_set_region_rect(region, vec2i(
					posuvwh.p1.x + (x - posuvwh.p2.x) * scale.x,
					posuvwh.p1.y + (y - posuvwh.p2.y) * scale.y), scale,
				mbx_get_region_pixel_xy(src, x, y));
			y += dir.y;
		}
		x += dir.x;
	}
}

static void	set_subregion_float_scaled(t_mbxregion *region, t_mbxregion *src,
	t_vec2ix3 posuvwh, t_vec2 scale)
{
	const t_vec2ix2	bounds = vec2ix2_xy(
			max(0, posuvwh.p1.x), max(0, posuvwh.p1.y),
			clamp(posuvwh.p1.x + posuvwh.p3.x * scale.x, -1, region->size.x),
			clamp(posuvwh.p1.y + posuvwh.p3.y * scale.y, -1, region->size.y));
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
					src, (x - posuvwh.p1.x) / scale.x + posuvwh.p2.x,
					(y - posuvwh.p1.y) / scale.y + posuvwh.p2.y));
			y += dir.y;
		}
		x += dir.x;
	}
}

void	mbx_set_region_subregion_scaled(t_mbxregion *region, t_mbxregion *src,
	t_vec2ix3 posuvwh, t_vec2 scale)
{
	if (scale.x == 0 || scale.y == 0)
		return ;
	if (is_integer(scale.x) && is_integer(scale.y))
		set_subregion_int_scaled(region, src, posuvwh, vec2_to_vec2i(scale));
	else
		set_subregion_float_scaled(region, src, posuvwh, scale);
}

void	mbx_set_subregion_scaled(t_mbx *mbx, t_mbxregion *region,
	t_vec2ix3 posuvwh, t_vec2 scale)
{
	mbx_set_region_subregion_scaled(&mbx->viewport, region, posuvwh, scale);
}
