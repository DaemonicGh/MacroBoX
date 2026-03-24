/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:46:52 by daemo             #+#    #+#             */
/*   Updated: 2026/01/18 21:07:22 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_drawing.h"
#include "modules/mbx_math.h"
#include "../_private/mbx_simd.h"

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
	t_vec2i pos, t_vec2i size, t_mbx_color col)
{
	const t_col4	vcol = {col.rgba, col.rgba, col.rgba, col.rgba};
	t_vec2i			xy;
	t_mbx_color		*row;

	xy.y = pos.y;
	row = region->canvas + (xy.y * region->size.x);
	while (xy.y < size.y)
	{
		xy.x = pos.x;
		while (xy.x < size.x - 4)
		{
			*(t_col4 *)(row + xy.x) = vcol;
			xy.x += 4;
		}
		while (xy.x < size.x)
		{
			row[xy.x] = col;
			xy.x++;
		}
		xy.y++;
		row += region->size.x;
	}
}

void	mbx_set_rect(t_mbx_region *restrict region,
	t_vec2i pos, t_vec2i size, t_mbx_color col)
{
	t_vec2i		xy;
	t_mbx_color	*row;

	if (col.a == 0)
		return ;
	set_rect_bounds(region, &pos, &size);
	if (col.a == 0xFF)
	{
		set_rect_opaque(region, pos, size, col);
		return ;
	}
	xy.y = pos.y;
	row = region->canvas + (xy.y * region->size.x);
	while (xy.y < size.y)
	{
		xy.x = pos.x;
		while (xy.x < size.x)
		{
			row[xy.x] = color_blend_quick(row[xy.x], col);
			xy.x++;
		}
		xy.y++;
		row += region->size.x;
	}
}
