/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:13:32 by daemo             #+#    #+#             */
/*   Updated: 2026/01/18 20:49:30 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/mbx_drawing.h"
#include "../../includes/modules/mbx_color.h"

void	mbx_set_region_pixel_xy(t_mbxregion *region,
	int x, int y, t_mbxcolor col)
{
	const int	i = mbx_region_get_pixel_index_xy(region, x, y);

	if (col.a == 0 || !mbx_region_is_pixel_in_bounds_i(region, i))
		return ;
	if (col.a == 0xFF)
		region->canvas[i] = col;
	region->canvas[i] = color_blend_quick(region->canvas[i], col);
}

void	mbx_set_region_pixel(t_mbxregion *region, t_vec2i pos, t_mbxcolor col)
{
	const int	i = mbx_region_get_pixel_index(region, pos);

	if (col.a == 0 || !mbx_region_is_pixel_in_bounds_i(region, i))
		return ;
	if (col.a == 0xFF)
		region->canvas[i] = col;
	else
		region->canvas[i] = color_blend_quick(region->canvas[i], col);
}

void	mbx_set_pixel_xy(t_mbx *mbx, int x, int y, t_mbxcolor col)
{
	const int	i = mbx_region_get_pixel_index_xy(&mbx->viewport, x, y);

	if (col.a == 0 || !mbx_region_is_pixel_in_bounds_i(&mbx->viewport, i))
		return ;
	if (col.a == 0xFF)
		mbx->viewport.canvas[i] = col;
	mbx->viewport.canvas[i] = color_blend_quick(mbx->viewport.canvas[i], col);
}

void	mbx_set_pixel(t_mbx *mbx, t_vec2i pos, t_mbxcolor col)
{
	const int	i = mbx_region_get_pixel_index(&mbx->viewport, pos);

	if (col.a == 0 || !mbx_region_is_pixel_in_bounds_i(&mbx->viewport, i))
		return ;
	if (col.a == 0xFF)
		mbx->viewport.canvas[i] = col;
	mbx->viewport.canvas[i] = color_blend_quick(mbx->viewport.canvas[i], col);
}
