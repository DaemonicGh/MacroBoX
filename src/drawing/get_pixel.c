/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 02:42:49 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/09 03:49:19 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

mlx_color	mbx_get_region_pixel_xy(t_mbxregion *region, int x, int y)
{
	if (x < 0 || x >= region->width || y < 0 || y >= region->height)
		return (color(0));
	return (region->canvas[y * region->width + x]);
}

mlx_color	mbx_get_region_pixel(t_mbxregion *region, t_vec2i pos)
{
	return (mbx_get_region_pixel_xy(region, pos.x, pos.y));
}

mlx_color	mbx_get_pixel_xy(t_mbx *mbx, int x, int y)
{
	return (mbx_get_region_pixel_xy(&mbx->viewport, x, y));
}

mlx_color	mbx_get_pixel(t_mbx *mbx, t_vec2i pos)
{
	return (mbx_get_region_pixel_xy(&mbx->viewport, pos.x, pos.y));
}
