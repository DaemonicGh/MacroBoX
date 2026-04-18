/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:13:32 by daemo             #+#    #+#             */
/*   Updated: 2026/01/18 20:49:30 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_drawing.h"

void	mbx_set_pixel_xy(t_mbx_region *restrict region,
	int x, int y, t_mbx_color col)
{
	const int	i = (y * region->size.x + x);

	if (!(x >= 0 && x < region->size.x && y >= 0 && y < region->size.y))
		return ;
	col = region->color_setter(region->color_modifier_data, col);
	if (col.a == 0)
		return ;
	if (col.a == 0xFF)
		region->pixels[i] = col;
	region->pixels[i] = color_blend_quick(region->pixels[i], col);
}

void	mbx_set_pixel(
	t_mbx_region *restrict region, t_vec2i pos, t_mbx_color col)
{
	const int	i = (pos.y * region->size.x + pos.x);

	if (!(pos.x >= 0 && pos.x < region->size.x
			&& pos.y >= 0 && pos.y < region->size.y))
		return ;
	col = region->color_setter(region->color_modifier_data, col);
	if (col.a == 0)
		return ;
	if (col.a == 0xFF)
		region->pixels[i] = col;
	else
		region->pixels[i] = color_blend_quick(region->pixels[i], col);
}
