/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:34:34 by daemo             #+#    #+#             */
/*   Updated: 2026/01/19 15:17:58 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/types/mbx_s_mbx.h"

t_mbximage	mbx_make_image(t_mbx *mbx, t_vec2i size)
{
	t_mbximage	img;

	img.img = mlx_new_image(mbx->mlx, size.x, size.y);
	img.size = size;
	return (img);
}

t_mbximage	mbx_make_image_from_file(t_mbx *mbx, char *path)
{
	t_mbximage	img;

	img.img = mlx_new_image_from_file(mbx->mlx, path, &img.size.x, &img.size.y);
	return (img);
}

t_mbximage	mbx_make_image_from_mlx(mlx_image image, int width, int height)
{
	t_mbximage	img;

	img.img = image;
	img.size.x = width;
	img.size.y = height;
	return (img);
}

void	mbx_destroy_image(t_mbx *mbx, t_mbximage *image)
{
	mlx_destroy_image(mbx->mlx, image->img);
}
