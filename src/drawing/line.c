/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:09:36 by daemo             #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "veclc.h"
#include "modules/mbx_drawing.h"
#include "../_private/mbx_internal.h"

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

void	mbx_set_line(t_mbx_region *restrict region,
	t_vec2ix2 pos, t_mbx_color col)
{
	const t_vec2i	d = vec2i_abs(vec2i_sub(pos.p2, pos.p1));
	const t_vec2i	s = vec2i(
			((pos.p1.x < pos.p2.x) << 1) - 1,
			((pos.p1.y < pos.p2.y) << 1) - 1);
	int				err;

	err = d.x - d.y;
	while (true)
	{
		mbx_set_pixel_xy(region, pos.p1.x, pos.p1.y, col);
		if (pos.p1.x == pos.p2.x && pos.p1.y == pos.p2.y)
			break ;
		line_step(&pos.p1, &err, d, s);
	}
}

void	mbx_set_line_thick(t_mbx_region *restrict region,
	t_vec2ix2 pos, unsigned int thickness, t_mbx_color col)
{
	const t_vec2i	d = vec2i_abs(vec2i_sub(pos.p2, pos.p1));
	const t_vec2i	s = vec2i(
			((pos.p1.x < pos.p2.x) << 1) - 1,
			((pos.p1.y < pos.p2.y) << 1) - 1);
	int				err;

	err = d.x - d.y;
	while (true)
	{
		if (d.x < d.y)
			mbx_set_rect(region,
				vec2i(pos.p1.x - thickness / 2, pos.p1.y),
				vec2i(thickness, 1), col);
		else
			mbx_set_rect(region,
				vec2i(pos.p1.x, pos.p1.y - thickness / 2),
				vec2i(1, thickness), col);
		if (pos.p1.x == pos.p2.x && pos.p1.y == pos.p2.y)
			break ;
		line_step(&pos.p1, &err, d, s);
	}
}
