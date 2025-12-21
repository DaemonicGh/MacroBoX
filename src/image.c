/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:34:34 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/21 10:53:19 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mbx.h"

t_mbximage	mbx_make_image(t_mbxcontext *mbx, int width, int height)
{
	t_mbximage	img;

	img.img = mlx_new_image(mbx->mlx, width, height);
	img.width = width;
	img.height = height;
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

void	mbx_fill_image(t_mbxcontext *mbx, t_mbximage image, mlx_color color)
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
