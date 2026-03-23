/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:34:34 by daemo             #+#    #+#             */
/*   Updated: 2026/02/05 05:14:38 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/mbx_s_mbx.h"

t_mbximage	mbx_make_image(t_mbx *mbx, t_vec2i size)
{
	t_mbximage	img;

	img.mlx = mlx_new_image(mbx->mlx, size.x, size.y);
	img.size = size;
	return (img);
}

t_mbximage	mbx_make_image_from_file(t_mbx *mbx, char *path)
{
	t_mbximage	img;

	img.mlx = mlx_new_image_from_file(mbx->mlx, path, &img.size.x, &img.size.y);
	return (img);
}

t_mbximage	mbx_make_image_from_mlx(mlx_image image, t_vec2i size)
{
	t_mbximage	img;

	img.mlx = image;
	img.size = size;
	return (img);
}

void	mbx_destroy_image(t_mbx *mbx, t_mbximage *image)
{
	mlx_destroy_image(mbx->mlx, image->mlx);
	*image = (t_mbximage){0};
}
