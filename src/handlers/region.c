/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   region.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:02:39 by daemo             #+#    #+#             */
/*   Updated: 2026/02/05 04:22:58 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "modules/types/mbx_s_mbx.h"

t_mbx_region	mbx_make_region(t_mbx *mbx, t_vec2i size)
{
	t_mbx_region	region;

	region.size.x = size.x;
	region.size.y = size.y;
	region.canvas = malloc(sizeof(t_mbx_color) * size.x * size.y);
	if (!region.canvas)
		return ((t_mbx_region){0});
	region.image = NULL;
	region.color_getter = mbx->settings.default_color_getter;
	region.color_setter = mbx->settings.default_color_setter;
	region.color_modifier_data = mbx->settings.default_color_modifier_data;
	return (region);
}

t_mbx_region	mbx_make_region_with_image(t_mbx *mbx, t_vec2i size)
{
	t_mbx_region	region;

	region.size.x = size.x;
	region.size.y = size.y;
	region.canvas = malloc(sizeof(t_mbx_color) * size.x * size.y);
	if (!region.canvas)
		return ((t_mbx_region){0});
	region.image = mlx_new_image(mbx->mlx, size.x, size.y);
	if (!region.image)
	{
		free(region.canvas);
		return ((t_mbx_region){0});
	}
	region.color_getter = mbx->settings.default_color_getter;
	region.color_setter = mbx->settings.default_color_setter;
	region.color_modifier_data = mbx->settings.default_color_modifier_data;
	return (region);
}

t_mbx_region	mbx_make_region_from_image(t_mbx *mbx, t_mbx_image *image)
{
	t_mbx_region	region;

	region = mbx_make_region(mbx, image->size);
	if (!region.canvas)
		return ((t_mbx_region){0});
	region.image = image->mlx;
	mlx_get_image_region(mbx->mlx, image->mlx,
		0, 0, image->size.x, image->size.y, region.canvas);
	return (region);
}

t_mbx_region	mbx_make_region_from_file(t_mbx *mbx, char *filename)
{
	t_mbx_image		image;
	t_mbx_region	region;

	image.mlx = mlx_new_image_from_file(mbx->mlx, filename,
			&image.size.x, &image.size.y);
	if (!image.mlx)
		return ((t_mbx_region){0});
	region = mbx_make_region_from_image(mbx, &image);
	if (!region.canvas)
		return ((t_mbx_region){0});
	return (region);
}

void	mbx_destroy_region(t_mbx *mbx, t_mbx_region *region)
{
	if (region->image)
		mlx_destroy_image(mbx->mlx, region->image);
	free(region->canvas);
	*region = (t_mbx_region){0};
}
