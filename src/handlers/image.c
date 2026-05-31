/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:34:34 by daemo             #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_handlers.h"

t_mbx_image	mbx_create_image(t_mbx *mbx, t_vec2i size)
{
	t_mbx_image	img;

	img.mlx = mlx_new_image(mbx->mlx, size.x, size.y);
	if (!img.mlx)
		return ((t_mbx_image){0});
	if (!mbx_add_alloc(mbx, img.mlx, MBX_ALLOC_TYPE_MLX_IMAGE
			| MBX_ALLOC_GROUP_MBX | MBX_ALLOC_GROUP_MLX))
	{
		mlx_destroy_image(mbx->mlx, img.mlx);
		return ((t_mbx_image){0});
	}
	img.size = size;
	return (img);
}

t_mbx_image	mbx_create_image_from_file(t_mbx *mbx, char *path)
{
	t_mbx_image	img;

	img.mlx = mlx_new_image_from_file(mbx->mlx, path, &img.size.x, &img.size.y);
	if (!img.mlx)
		return ((t_mbx_image){0});
	if (!mbx_add_alloc(mbx, img.mlx, MBX_ALLOC_TYPE_MLX_IMAGE
			| MBX_ALLOC_GROUP_MBX | MBX_ALLOC_GROUP_MLX))
	{
		mlx_destroy_image(mbx->mlx, img.mlx);
		return ((t_mbx_image){0});
	}
	return (img);
}

t_mbx_image	mbx_create_image_from_mlx(
	t_mbx *mbx, mlx_image image, t_vec2i size)
{
	t_mbx_image	img;

	img.mlx = image;
	if (!mbx_add_alloc(mbx, img.mlx, MBX_ALLOC_TYPE_MLX_IMAGE
			| MBX_ALLOC_GROUP_MBX | MBX_ALLOC_GROUP_MLX))
	{
		mlx_destroy_image(mbx->mlx, img.mlx);
		return ((t_mbx_image){0});
	}
	img.size = size;
	return (img);
}

void	mbx_destroy_image(t_mbx *mbx, t_mbx_image *image)
{
	if (!image)
		return ;
	if (!mbx_free(mbx, image->mlx))
		mlx_destroy_image(mbx->mlx, image->mlx);
}
