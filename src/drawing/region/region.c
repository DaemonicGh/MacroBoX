/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   region.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:46:33 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "modules/mbx_drawing.h"
#include "modules/mbx_utils.h"

void	mbx_set_subregion(t_mbx_region *restrict region,
	t_mbx_region *restrict src, t_vec2i pos, t_vec2ix2 uvwh)
{
	const t_vec2ix3	bounds = vec2ix3(vec2i(max(pos.x, 0), max(pos.y, 0)), vec2i(
				uvwh.p1.x + max(-uvwh.p2.x, 0), uvwh.p1.y + max(-uvwh.p2.y, 0)),
			vec2i(min(pos.x + abs(uvwh.p2.x), region->size.x),
				min(pos.y + abs(uvwh.p2.y), region->size.y)));
	const t_vec2i	incr = vec2i(sign(uvwh.p2.x), sign(uvwh.p2.y));
	t_vec2i			uv;
	int				i;

	pos.y = bounds.p1.y;
	uv.y = bounds.p2.y;
	i = bounds.p1.y * region->size.x + bounds.p1.x;
	while (pos.y < bounds.p3.y)
	{
		pos.x = bounds.p1.x;
		uv.x = bounds.p2.x;
		while (pos.x < bounds.p3.x)
		{
			mbx_set_pixel_unsafe_i(region, i++, mbx_get_pixel_unsafe(src, uv));
			pos.x++;
			uv.x += incr.x;
		}
		pos.y++;
		uv.y += incr.y;
		i += region->size.x - (bounds.p3.x - bounds.p1.x);
	}
}

void	mbx_set_region(t_mbx_region *restrict region,
	t_mbx_region *restrict src, t_vec2i pos)
{
	mbx_set_subregion(region, src, pos, vec2ix2(vec2i_zero(), src->size));
}

void	mbx_set_region_scaled(t_mbx_region *restrict region,
	t_mbx_region *restrict src, t_vec2i pos, t_vec2 scale)
{
	mbx_set_subregion_scaled(region, src,
		vec2ix3(pos, vec2i_zero(), src->size),
		scale);
}

void	mbx_set_region_transformed(t_mbx_region *restrict region,
	t_mbx_region *restrict src, t_vec2i pos, t_vec2x2 transform)
{
	mbx_set_subregion_transformed(region, src,
		vec2ix3(pos, vec2i_zero(), src->size),
		transform);
}
