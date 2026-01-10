/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:34:34 by daemo             #+#    #+#             */
/*   Updated: 2026/01/10 01:21:50 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mbx.h"

t_mbximage	mbx_make_image(t_mbx *mbx, int width, int height)
{
	t_mbximage	img;

	img.img = mlx_new_image(mbx->mlx, width, height);
	img.width = width;
	img.height = height;
	return (img);
}

t_mbximage	mbx_make_image_from_file(t_mbx *mbx, char *path)
{
	t_mbximage	img;

	img.img = mlx_new_image_from_file(mbx->mlx, path, &img.width, &img.height);
	return (img);
}

t_mbximage	mbx_make_image_from_mlx(mlx_image image, int width, int height)
{
	t_mbximage	img;

	img.img = image;
	img.width = width;
	img.height = height;
	return (img);
}

void	mbx_fill_image(t_mbx *mbx, t_mbximage image, mlx_color color)
{
	mlx_color	*buffer;
	int			i;

	buffer = malloc(sizeof(mlx_color) * image.width * image.height);
	i = 0;
	while (i < image.width * image.height)
		buffer[i++] = color;
	mlx_set_image_region(mbx->mlx, image.img, 0, 0,
		image.width, image.height, buffer);
	free(buffer);
}

void	mbx_destroy_image(t_mbx *mbx, t_mbximage *image)
{
	mlx_destroy_image(mbx->mlx, image->img);
}
