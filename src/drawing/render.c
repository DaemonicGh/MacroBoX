/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 02:33:11 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_utils.h"
#include "modules/mbx_handlers.h"

bool	mbx_render_region(
	t_mbx *mbx, t_mbx_region *region, t_vec2i pos, t_vec2 scale)
{
	if (!region->image)
	{
		if (!mbx_create_region_image(mbx, region))
			return (false);
	}
	mlx_set_image_region(mbx->mlx, region->image, 0, 0,
		region->size.x, region->size.y, region->pixels);
	mlx_put_transformed_image_to_window(mbx->mlx, mbx->window.mlx,
		region->image, pos.x, pos.y, scale.x, scale.y, 0);
	return (true);
}

bool	mbx_render_region_as_viewport(
	t_mbx *mbx, t_mbx_region *region, t_mbx_viewport_render render_mode)
{
	t_vec2	scale;
	t_vec2i	pos;

	if (render_mode == MBX_VIEWPORT_RENDER_SKIP)
		return (true);
	if (render_mode == MBX_VIEWPORT_RENDER_KEEP)
		scale = vec2_d(fmin(
					(double)mbx->window.size.x / region->size.x,
					(double)mbx->window.size.y / region->size.y));
	else if (render_mode == MBX_VIEWPORT_RENDER_KEEP_INT)
		scale = vec2_d(min(
					mbx->window.size.x / region->size.x,
					mbx->window.size.y / region->size.y));
	else if (render_mode == MBX_VIEWPORT_RENDER_STRETCH)
		scale = vec2i_truediv(mbx->window.size, region->size);
	else
		scale = vec2_d(1);
	pos = vec2i_div_d(vec2i_sub(mbx->window.size,
				vec2i_mult_vd(region->size, scale)), 2);
	return (mbx_render_region(mbx, region, pos, scale));
}
