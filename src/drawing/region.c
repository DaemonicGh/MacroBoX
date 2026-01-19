/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   region.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:46:33 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 14:43:50 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/mbx_drawing.h"
#include "../../includes/modules/mbx_color.h"
#include "../../includes/modules/mbx_math.h"

void	mbx_set_region_region(t_mbxregion *region, t_mbxregion *src,
	t_vec2i pos)
{
	const t_vec2ix2	bounds = vec2ix2_xy(
			max(0, pos.x), max(0, pos.y),
			min(region->size.x, pos.x + src->size.x),
			min(region->size.y, pos.y + src->size.y));
	int				x;
	int				y;

	x = bounds.p1.x;
	while (x < bounds.p2.x)
	{
		y = bounds.p1.y;
		while (y < bounds.p2.y)
		{
			mbx_set_region_pixel_unsafe_xy(region, x, y,
				mbx_get_region_pixel_xy(
					src, pos.x - x, pos.y - y));
			y++;
		}
		x++;
	}
}

void	mbx_set_region_subregion(t_mbxregion *region, t_mbxregion *src,
	t_vec2i pos, t_vec2ix2 uvwh)
{
	const t_vec2ix2	bounds = vec2ix2_xy(
			max(0, pos.x), max(0, pos.y),
			min(region->size.x, pos.x + uvwh.p2.x),
			min(region->size.y, pos.y + uvwh.p2.y));
	int				x;
	int				y;

	x = bounds.p1.x;
	while (x < bounds.p2.x)
	{
		y = bounds.p1.y;
		while (y < bounds.p2.y)
		{
			mbx_set_region_pixel_unsafe_xy(region, x, y,
				mbx_get_region_pixel_xy(
					src, pos.x - uvwh.p1.x + x, pos.y - uvwh.p1.y + y));
			y++;
		}
		x++;
	}
}

void	mbx_set_region(t_mbx *mbx, t_mbxregion *region, t_vec2i pos)
{
	mbx_set_region_region(&mbx->viewport, region, pos);
}

void	mbx_set_subregion(t_mbx *mbx, t_mbxregion *region,
	t_vec2i pos, t_vec2ix2 uvwh)
{
	mbx_set_region_subregion(&mbx->viewport, region, pos, uvwh);
}
