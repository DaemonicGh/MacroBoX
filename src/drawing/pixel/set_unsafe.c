/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_unsafe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:13:32 by daemo             #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_drawing.h"

void	mbx_set_pixel_unsafe_i(t_mbx_region *restrict region,
	int i, t_mbx_color col)
{
	if (!col.a)
		return ;
	if (col.a != 0xFF)
		col = region->pipeline.blend(region->pipeline.data,
				region->pipeline.get(region->pipeline.data, region, i),
				col);
	region->pipeline.set(region->pipeline.data, region, i, col);
}

void	mbx_set_pixel_unsafe_xy(t_mbx_region *restrict region,
	int x, int y, t_mbx_color col)
{
	const int	i = (y * region->size.x + x);

	if (!col.a)
		return ;
	if (col.a != 0xFF)
		col = region->pipeline.blend(region->pipeline.data,
				region->pipeline.get(region->pipeline.data, region, i), col);
	region->pipeline.set(region->pipeline.data, region, i, col);
}

void	mbx_set_pixel_unsafe(t_mbx_region *restrict region,
	t_vec2i pos, t_mbx_color col)
{
	const int	i = (pos.y * region->size.x + pos.x);

	if (!col.a)
		return ;
	if (col.a != 0xFF)
		col = region->pipeline.blend(region->pipeline.data,
				region->pipeline.get(region->pipeline.data, region, i), col);
	region->pipeline.set(region->pipeline.data, region, i, col);
}
