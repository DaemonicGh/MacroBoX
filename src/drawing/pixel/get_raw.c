/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 02:42:49 by rprieur           #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_drawing.h"

t_mbx_color	mbx_get_pixel_raw_i(t_mbx_region *restrict region, int i)
{
	return (region->pixels[i]);
}

t_mbx_color	mbx_get_pixel_raw_xy(t_mbx_region *restrict region, int x, int y)
{
	return (region->pixels[y * region->size.x + x]);
}

t_mbx_color	mbx_get_pixel_raw(t_mbx_region *restrict region, t_vec2i pos)
{
	return (region->pixels[pos.y * region->size.x + pos.x]);
}
