/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:13:32 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 15:53:33 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/mbx_drawing.h"
#include "../../includes/modules/mbx_color.h"

void	mbx_set_region_pixel_raw_i(t_mbxregion *region, int i, t_mbxcolor col)
{
	region->canvas[i] = col;
}

void	mbx_set_region_pixel_raw_xy(t_mbxregion *region,
	int x, int y, t_mbxcolor col)
{
	region->canvas[mbx_region_get_pixel_index_xy(region, x, y)] = col;
}

void	mbx_set_region_pixel_raw(t_mbxregion *region,
	t_vec2i pos, t_mbxcolor col)
{
	region->canvas[mbx_region_get_pixel_index(region, pos)] = col;
}
