/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:09:36 by daemo             #+#    #+#             */
/*   Updated: 2026/01/09 02:45:20 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"
#include "../../includes/mbx_internal.h"

static inline void	line_step(t_vec2i *step, int *err, t_vec2i d, t_vec2i s)
{
	const int	err2 = 2 * *err;

	if (err2 >= -d.y)
	{
		*err -= d.y;
		step->x += s.x;
	}
	if (err2 <= d.x)
	{
		*err += d.x;
		step->y += s.y;
	}
}

void	mbx_set_region_line(t_mbxregion *region, t_2vec2i pos, mlx_color color)
{
	const t_vec2i	d = vec2i(
			abs(pos.p2.x - pos.p1.x), abs(pos.p2.y - pos.p1.y));
	const t_vec2i	s = vec2i(
			(pos.p1.x < pos.p2.x) * 2 - 1, (pos.p1.y < pos.p2.y) * 2 - 1);
	int				err;

	err = d.x - d.y;
	while (true)
	{
		mbx_set_region_pixel_xy(region, pos.p1.x, pos.p1.y, color);
		if (pos.p1.x == pos.p2.x && pos.p1.y == pos.p2.y)
			break ;
		line_step(&pos.p1, &err, d, s);
	}
}

void	mbx_set_region_line_thick(t_mbxregion *region,
	t_2vec2i pos, unsigned int thickness, mlx_color color)
{
	const t_vec2i	d = vec2i(
			abs(pos.p2.x - pos.p1.x), abs(pos.p2.y - pos.p1.y));
	const t_vec2i	s = vec2i(
			(pos.p1.x < pos.p2.x) * 2 - 1, (pos.p1.y < pos.p2.y) * 2 - 1);
	int				err;

	err = d.x - d.y;
	while (true)
	{
		if (d.x < d.y)
			mbx_set_region_rect(region,
				vec2i(pos.p1.x - (float)thickness / 2 - 0.5, pos.p1.y),
				vec2i(thickness, 1), color);
		else
			mbx_set_region_rect(region,
				vec2i(pos.p1.x, pos.p1.y - (float)thickness / 2 - 0.5),
				vec2i(1, thickness), color);
		if (pos.p1.x == pos.p2.x && pos.p1.y == pos.p2.y)
			break ;
		line_step(&pos.p1, &err, d, s);
	}
}

void	mbx_set_line(t_mbx *mbx, t_2vec2i pos, mlx_color color)
{
	mbx_set_region_line(&mbx->viewport, pos, color);
}

void	mbx_set_line_thick(t_mbx *mbx,
	t_2vec2i pos, unsigned int thickness, mlx_color color)
{
	mbx_set_region_line_thick(&mbx->viewport, pos, thickness, color);
}
