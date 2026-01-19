/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 03:28:19 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/18 21:07:22 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/types/mbx_s_mbx.h"

bool	mbx_region_is_pixel_in_bounds_i(t_mbxregion *region, int i)
{
	if (i >= 0 && i < region->size.x * region->size.y)
		return (true);
	return (false);
}

bool	mbx_region_is_pixel_in_bounds_xy(t_mbxregion *region, int x, int y)
{
	if (x >= 0 && x < region->size.x && y >= 0 && y < region->size.y)
		return (true);
	return (false);
}

bool	mbx_region_is_pixel_in_bounds(t_mbxregion *region, t_vec2i pos)
{
	if (pos.x >= 0 && pos.x < region->size.x
		&& pos.y >= 0 && pos.y < region->size.y)
		return (true);
	return (false);
}

int	mbx_region_get_pixel_index_xy(t_mbxregion *region, int x, int y)
{
	return (y * region->size.x + x);
}

int	mbx_region_get_pixel_index(t_mbxregion *region, t_vec2i pos)
{
	return (pos.y * region->size.x + pos.x);
}
