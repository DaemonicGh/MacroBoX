/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:13:32 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:11:51 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/types/mbx_s_mbx.h"
#include "../../includes/modules/mbx_color.h"

void	mbx_set_region_pixel_xy(t_mbxregion *region,
	int x, int y, t_mbxcolor col)
{
	if (x < 0 || x >= region->width
		|| y < 0 || y >= region->height)
		return ;
	if (col.a == 255)
		region->canvas[y * region->width + x] = col;
	else
		region->canvas[y * region->width + x]
			= color_blend(region->canvas[y * region->width + x], col);
}

void	mbx_set_region_pixel(t_mbxregion *region, t_vec2i pos, t_mbxcolor col)
{
	mbx_set_region_pixel_xy(region, pos.x, pos.y, col);
}

void	mbx_set_pixel(t_mbx *mbx, t_vec2i pos, t_mbxcolor col)
{
	mbx_set_region_pixel_xy(&mbx->viewport, pos.x, pos.y, col);
}

void	mbx_set_pixel_xy(t_mbx *mbx, int x, int y, t_mbxcolor col)
{
	mbx_set_region_pixel_xy(&mbx->viewport, x, y, col);
}
