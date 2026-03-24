/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 02:33:11 by rprieur           #+#    #+#             */
/*   Updated: 2026/03/24 02:33:11 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "veclc.h"
#include "modules/mbx_math.h"
#include "modules/mbx_handlers.h"

void	mbx_render_region(
	t_mbx *mbx, t_mbx_region *region, t_vec2i pos, t_vec2 scale)
{
	if (!region->image)
		region->image = mlx_new_image(mbx->mlx, region->size.x, region->size.y);
	mlx_set_image_region(mbx->mlx, region->image, 0, 0,
		region->size.x, region->size.y, region->canvas);
	mlx_put_transformed_image_to_window(mbx->mlx, mbx->window.mlx,
		region->image, pos.x, pos.y, scale.x, scale.y, 0);
}

void	mbx_render_region_as_viewport(t_mbx *mbx, t_mbx_region *region)
{
	const int			scale = min(
			mbx->window.size.x / region->size.x,
			mbx->window.size.y / region->size.y);
	const t_vec2i		size = vec2i(
			region->size.x * scale,
			region->size.y * scale);

	if (!region->image)
		region->image = mlx_new_image(mbx->mlx, region->size.x, region->size.y);
	mlx_set_image_region(mbx->mlx, region->image, 0, 0,
		region->size.x, region->size.y, region->canvas);
	mlx_put_transformed_image_to_window(mbx->mlx, mbx->window.mlx,
		region->image, (mbx->window.size.x - (size.x)) / 2,
		(mbx->window.size.y - (size.y)) / 2, scale, scale, 0);
}
