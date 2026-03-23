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

static void	set_rect_bounds(t_mbxregion *region,
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

void	mbx_set_rect(t_mbxregion *region,
	t_vec2i pos, t_vec2i size, t_mbxcolor col)
{
	t_vec2i	xy;

	set_rect_bounds(region, &pos, &size);
	xy.x = pos.x;
	while (xy.x < size.x)
	{
		xy.y = pos.y;
		while (xy.y < size.y)
		{
			mbx_set_pixel_unsafe(region, xy, col);
			xy.y++;
		}
		xy.x++;
	}
}
