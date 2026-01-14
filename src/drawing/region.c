/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   region.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:46:33 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:08:59 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/mbx_drawing.h"

void	mbx_set_region_region(t_mbxregion *dest, t_vec2i pos, t_mbxregion *src)
{
	int	x;
	int	y;

	x = 0;
	while (x < src->width)
	{
		y = 0;
		while (y < src->height)
		{
			mbx_set_region_pixel_xy(dest, pos.x + x, pos.y + y,
				mbx_get_region_pixel_xy(src, x, y));
			y++;
		}
		x++;
	}
}

void	mbx_set_region_subregion(t_mbxregion *dest,
	t_vec2i pos, t_vec2ix2 uvwh, t_mbxregion *src)
{
	int	x;
	int	y;

	x = 0;
	while (x < uvwh.p2.x)
	{
		y = 0;
		while (y < uvwh.p2.y)
		{
			mbx_set_region_pixel_xy(dest, pos.x + x, pos.y + y,
				mbx_get_region_pixel_xy(src, uvwh.p1.x + x, uvwh.p1.y + y));
			y++;
		}
		x++;
	}
}

void	mbx_set_region(t_mbx *mbx, t_vec2i pos, t_mbxregion *region)
{
	mbx_set_region_region(&mbx->viewport, pos, region);
}

void	mbx_set_subregion(t_mbx *mbx,
	t_vec2i pos, t_vec2ix2 uvwh, t_mbxregion *region)
{
	mbx_set_region_subregion(&mbx->viewport, pos, uvwh, region);
}
