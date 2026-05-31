/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 03:28:19 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_structs.h"

bool	mbx_is_pixel_in_bounds_i(t_mbx_region *restrict region, int i)
{
	return (i >= 0 && i < region->size.x * region->size.y);
}

bool	mbx_is_pixel_in_bounds_xy(t_mbx_region *restrict region, int x, int y)
{
	return (x >= 0 && x < region->size.x && y >= 0 && y < region->size.y);
}

bool	mbx_is_pixel_in_bounds(t_mbx_region *region, t_vec2i pos)
{
	return (pos.x >= 0 && pos.x < region->size.x
		&& pos.y >= 0 && pos.y < region->size.y);
}

int	mbx_get_pixel_index_xy(t_mbx_region *restrict region, int x, int y)
{
	return (y * region->size.x + x);
}

int	mbx_get_pixel_index(t_mbx_region *restrict region, t_vec2i pos)
{
	return (pos.y * region->size.x + pos.x);
}
