/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:02:39 by daemo             #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "modules/mbx_constants.h"
#include "modules/mbx_handlers.h"

void	*mbx_create_region_ext(
	t_mbx *mbx, t_vec2i size, size_t struct_size)
{
	void			*allocation;
	t_mbx_region	*region;

	allocation = mbx_alloc_flags(mbx,
			struct_size + sizeof(t_mbx_color) * size.x * size.y,
			MBX_ALLOC_GROUP_MBX | MBX_ALLOC_TYPE_MBX_REGION);
	if (!allocation)
		return (NULL);
	region = allocation + struct_size - sizeof(t_mbx_region);
	*region = (t_mbx_region){0};
	region->size = size;
	region->pipeline = mbx->settings.default_pipeline;
	return (allocation);
}

void	*mbx_create_region_ext_with_image(
	t_mbx *mbx, t_vec2i size, size_t struct_size)
{
	void			*allocation;
	t_mbx_region	*region;
	t_mbx_image		image;

	image = mbx_create_image(mbx, size);
	if (!image.mlx)
		return (NULL);
	allocation = mbx_create_region_ext(mbx, size, struct_size);
	if (!allocation)
	{
		mbx_destroy_image(mbx, &image);
		return (NULL);
	}
	region = allocation + struct_size - sizeof(t_mbx_region);
	region->image = image.mlx;
	return (allocation);
}

void	*mbx_create_region_ext_from_image(
	t_mbx *mbx, t_mbx_image *image, size_t struct_size)
{
	void			*allocation;
	t_mbx_region	*region;

	allocation = mbx_create_region_ext(mbx, image->size, struct_size);
	if (!allocation)
		return (NULL);
	region = allocation + struct_size - sizeof(t_mbx_region);
	region->image = image->mlx;
	mlx_get_image_region(mbx->mlx, image->mlx,
		0, 0, image->size.x, image->size.y, region->pixels);
	return (allocation);
}

void	*mbx_create_region_ext_from_file(
	t_mbx *mbx, char *filename, size_t struct_size)
{
	t_mbx_image		image;
	void			*allocation;
	t_mbx_region	*region;

	image.mlx = mlx_new_image_from_file(
			mbx->mlx, filename, &image.size.x, &image.size.y);
	if (!image.mlx)
		return (NULL);
	allocation = mbx_create_region_ext_from_image(mbx, &image, struct_size);
	mlx_destroy_image(mbx->mlx, image.mlx);
	if (!allocation)
		return (NULL);
	region = allocation + struct_size - sizeof(t_mbx_region);
	region->image = NULL;
	return (allocation);
}

void	*mbx_create_region_ext_from_file_with_image(
	t_mbx *mbx, char *filename, size_t struct_size)
{
	t_mbx_image		image;
	void			*allocation;

	image = mbx_create_image_from_file(mbx, filename);
	if (!image.mlx)
		return (NULL);
	allocation = mbx_create_region_ext_from_image(
			mbx, &image, struct_size);
	if (!allocation)
	{
		mbx_destroy_image(mbx, &image);
		return (NULL);
	}
	return (allocation);
}
