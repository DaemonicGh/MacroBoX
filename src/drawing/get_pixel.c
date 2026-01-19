/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 02:42:49 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/18 21:07:22 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/types/mbx_s_mbx.h"

t_mbxcolor	mbx_get_region_pixel_xy(t_mbxregion *region, int x, int y)
{
	if (x < 0 || x >= region->size.x || y < 0 || y >= region->size.y)
		return (color(0));
	return (region->canvas[y * region->size.x + x]);
}

t_mbxcolor	mbx_get_region_pixel(t_mbxregion *region, t_vec2i pos)
{
	return (mbx_get_region_pixel_xy(region, pos.x, pos.y));
}

t_mbxcolor	mbx_get_pixel_xy(t_mbx *mbx, int x, int y)
{
	return (mbx_get_region_pixel_xy(&mbx->viewport, x, y));
}

t_mbxcolor	mbx_get_pixel(t_mbx *mbx, t_vec2i pos)
{
	return (mbx_get_region_pixel_xy(&mbx->viewport, pos.x, pos.y));
}
