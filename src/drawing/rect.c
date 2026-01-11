/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:46:52 by daemo             #+#    #+#             */
/*   Updated: 2026/01/10 14:06:14 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

static inline void	format_size(t_vec2i *pos, t_vec2i *size)
{
	if (size->x < 0)
	{
		pos->x += size->x + 1;
		size->x = -size->x;
	}
	if (size->y < 0)
	{
		pos->y += size->y + 1;
		size->y = -size->y;
	}
}

void	mbx_set_region_rect(t_mbxregion *region,
	t_vec2i pos, t_vec2i size, mlx_color col)
{
	int	x;
	int	y;

	format_size(&pos, &size);
	x = 0;
	while (x < size.x)
	{
		y = 0;
		while (y < size.y)
		{
			mbx_set_region_pixel_xy(region, pos.x + x, pos.y + y, col);
			y++;
		}
		x++;
	}
}

void	mbx_set_region_rect_border(t_mbxregion *region,
	t_vec2i pos, t_vec2i size, mlx_color col)
{
	int	i;

	format_size(&pos, &size);
	i = 0;
	while (i < size.x)
	{
		mbx_set_region_pixel_xy(region, pos.x + i, pos.y, col);
		mbx_set_region_pixel_xy(region, pos.x + i, pos.y + size.y - 1, col);
		i++;
	}
	i = 1;
	while (i + 1 < size.y)
	{
		mbx_set_region_pixel_xy(region, pos.x, pos.y + i, col);
		mbx_set_region_pixel_xy(region, pos.x + size.x - 1, pos.y + i, col);
		i++;
	}
}

void	mbx_set_rect(t_mbx *mbx, t_vec2i pos, t_vec2i size, mlx_color col)
{
	mbx_set_region_rect(&mbx->viewport, pos, size, col);
}

void	mbx_set_rect_border(t_mbx *mbx,
	t_vec2i pos, t_vec2i size, mlx_color col)
{
	mbx_set_region_rect_border(&mbx->viewport, pos, size, col);
}
