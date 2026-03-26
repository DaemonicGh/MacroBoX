/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 02:42:49 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/18 21:07:22 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_drawing.h"

t_mbx_color	mbx_get_pixel_xy(t_mbx_region *restrict region, int x, int y)
{
	if (!(x >= 0 && x < region->size.x && y >= 0 && y < region->size.y))
		return (color_rgba(0x0));
	return (region->color_getter(region->color_modifier_data,
			region, y * region->size.x + x));
}

t_mbx_color	mbx_get_pixel(t_mbx_region *restrict region, t_vec2i pos)
{
	if (!(pos.x >= 0 && pos.x < region->size.x
			&& pos.y >= 0 && pos.y < region->size.y))
		return (color_rgba(0x0));
	return (region->color_getter(region->color_modifier_data,
			region, pos.y * region->size.x + pos.x));
}
