/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:46:52 by daemo             #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_drawing.h"
#include "modules/mbx_utils.h"

static void	set_rect_bounds(t_mbx_region *restrict region,
	t_vec2i *pos, t_vec2i *size)
{
	int	ppos;

	if (size->x < 0)
	{
		ppos = pos->x;
		pos->x = max(pos->x + size->x, 0);
		size->x = min(ppos, region->size.x);
	}
	else
	{
		size->x = min(pos->x + size->x, region->size.x);
		pos->x = max(pos->x, 0);
	}
	if (size->y < 0)
	{
		ppos = pos->y;
		pos->y = max(pos->y + size->y, 0);
		size->y = min(ppos, region->size.y);
	}
	else
	{
		size->y = min(pos->y + size->y, region->size.y);
		pos->y = max(pos->y, 0);
	}
}

static void	set_rect_opaque(t_mbx_region *restrict region,
	t_vec2i start, t_vec2i end, t_mbx_color col)
{
	t_vec2i			xy;
	int				i;

	xy.y = start.y;
	i = xy.y * region->size.x + start.x;
	while (xy.y++ < end.y)
	{
		xy.x = start.x;
		while (xy.x++ < end.x)
		{
			region->pipeline.set(region->pipeline.data, region, i, col);
			i++;
		}
		i += start.x - end.x + region->size.x;
	}
}

static void	set_rect_transparent(t_mbx_region *restrict region,
	t_vec2i start, t_vec2i end, t_mbx_color col)
{
	t_vec2i				xy;
	int					i;

	xy.y = start.y;
	i = start.y * region->size.x + start.x;
	while (xy.y++ < end.y)
	{
		xy.x = start.x;
		while (xy.x++ < end.x)
		{
			region->pipeline.set(region->pipeline.data, region, i,
				region->pipeline.blend(region->pipeline.data,
					region->pipeline.get(region->pipeline.data, region, i),
					col));
			i++;
		}
		i += start.x - end.x + region->size.x;
	}
}

void	mbx_set_rect(t_mbx_region *restrict region,
	t_vec2i pos, t_vec2i size, t_mbx_color col)
{
	if (!col.a)
		return ;
	set_rect_bounds(region, &pos, &size);
	if (col.a == 0xFF)
		set_rect_opaque(region, pos, size, col);
	else
		set_rect_transparent(region, pos, size, col);
}
