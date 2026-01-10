/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:13:32 by daemo             #+#    #+#             */
/*   Updated: 2026/01/09 23:20:18 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

void	mbx_set_region_pixel_xy(t_mbxregion *region,
	int x, int y, mlx_color color)
{
	if (x < 0 || x >= region->width
		|| y < 0 || y >= region->height)
		return ;
	region->canvas[y * region->width + x]
		= color_blend(region->canvas[y * region->width + x], color);
}

void	mbx_set_region_pixel(t_mbxregion *region, t_vec2i pos, mlx_color color)
{
	mbx_set_region_pixel_xy(region, pos.x, pos.y, color);
}

void	mbx_set_pixel(t_mbx *mbx, t_vec2i pos, mlx_color color)
{
	mbx_set_region_pixel_xy(&mbx->viewport, pos.x, pos.y, color);
}

void	mbx_set_pixel_xy(t_mbx *mbx, int x, int y, mlx_color color)
{
	mbx_set_region_pixel_xy(&mbx->viewport, x, y, color);
}
