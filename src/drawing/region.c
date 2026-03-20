/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   region.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:46:33 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 14:43:50 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "veclc.h"
#include "modules/mbx_drawing.h"
#include "modules/mbx_math.h"

void	mbx_set_subregion(t_mbxregion *region, t_mbxregion *src,
	t_vec2i pos, t_vec2ix2 uvwh)
{
	const t_vec2ix2	bounds = vec2ix2(
			vec2i(max(pos.x, 0), max(pos.y, 0)),
			vec2i(
				min(pos.x + abs(uvwh.p2.x), region->size.x),
				min(pos.y + abs(uvwh.p2.y), region->size.y))
			);
	const t_vec2i	incr = vec2i_sign(uvwh.p2);
	t_vec2i			uv;

	pos.x = bounds.p1.x;
	uv.x = uvwh.p1.x;
	while (pos.x < bounds.p2.x)
	{
		pos.y = bounds.p1.y;
		uv.y = uvwh.p1.y;
		while (pos.y < bounds.p2.y)
		{
			mbx_set_pixel_unsafe(region, pos,
				mbx_get_pixel_unsafe(src, uv));
			pos.y++;
			uv.y += incr.y;
		}
		pos.x++;
		uv.x += incr.x;
	}
}

void	mbx_set_region(t_mbxregion *region, t_mbxregion *src, t_vec2i pos)
{
	mbx_set_subregion(region, src, pos, vec2ix2(vec2i_zero(), src->size));
}
