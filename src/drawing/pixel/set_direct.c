/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_direct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:13:32 by daemo             #+#    #+#             */
/*   Updated: 2026/01/18 20:56:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_drawing.h"

void	mbx_set_pixel_direct_i(t_mbx_region *restrict region,
	int i, t_mbx_color col)
{
	if (col.a == 0)
		return ;
	if (col.a == 0xFF)
		region->canvas[i] = col;
	else
		region->canvas[i] = color_blend_quick(region->canvas[i], col);
}

void	mbx_set_pixel_direct_xy(t_mbx_region *restrict region,
	int x, int y, t_mbx_color col)
{
	const int	i = (y * region->size.x + x);

	if (col.a == 0)
		return ;
	if (col.a == 0xFF)
		region->canvas[i] = col;
	else
		region->canvas[i] = color_blend_quick(region->canvas[i], col);
}

void	mbx_set_pixel_direct(t_mbx_region *restrict region,
	t_vec2i pos, t_mbx_color col)
{
	const int	i = (pos.y * region->size.x + pos.x);

	if (col.a == 0)
		return ;
	if (col.a == 0xFF)
		region->canvas[i] = col;
	else
		region->canvas[i] = color_blend_quick(region->canvas[i], col);
}
