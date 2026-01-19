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

#include "../../includes/modules/mbx_drawing.h"
#include "../../includes/modules/mbx_math.h"

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
		pos->x = max(pos->x, 0);
		size->x = min(pos->x + size->x, region->size.x);
	}
	if (size->y < 0)
	{
		ppos = pos->y;
		pos->y = max(pos->y + size->y, 0);
		size->y = min(ppos, region->size.y);
	}
	else
	{
		pos->y = max(pos->y, 0);
		size->y = min(pos->y + size->y, region->size.y);
	}
}

void	mbx_set_region_rect(t_mbxregion *region,
	t_vec2i pos, t_vec2i size, t_mbxcolor col)
{
	int	x;
	int	y;

	set_rect_bounds(region, &pos, &size);
	x = pos.x;
	while (x < size.x)
	{
		y = pos.y;
		while (y < size.y)
		{
			mbx_set_region_pixel_unsafe_xy(region, x, y, col);
			y++;
		}
		x++;
	}
}

void	mbx_set_rect(t_mbx *mbx, t_vec2i pos, t_vec2i size, t_mbxcolor col)
{
	mbx_set_region_rect(&mbx->viewport, pos, size, col);
}
