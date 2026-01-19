/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   region.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:02:39 by daemo             #+#    #+#             */
/*   Updated: 2026/01/19 15:14:53 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/modules/types/mbx_s_mbx.h"

t_mbxregion	mbx_make_region_wh(int width, int height)
{
	t_mbxregion	region;

	region.size.x = width;
	region.size.y = height;
	region.canvas = malloc(sizeof(t_mbxcolor) * width * height);
	if (!region.canvas)
		return ((t_mbxregion){0});
	region.image = NULL;
	return (region);
}

t_mbxregion	mbx_make_region(t_vec2i size)
{
	return (mbx_make_region_wh(size.x, size.y));
}

t_mbxregion	mbx_make_region_from_image(t_mbx *mbx, t_mbximage *image)
{
	t_mbxregion	region;
	int			i;

	region = mbx_make_region_wh(image->size.x, image->size.y);
	if (!region.canvas)
		return ((t_mbxregion){0});
	region.image = image->img;
	i = 0;
	while (i < image->size.x * image->size.y)
	{
		region.canvas[i] = mlx_get_image_pixel(mbx->mlx,
				image->img, i % image->size.x, i / image->size.x);
		i++;
	}
	return (region);
}

void	mbx_destroy_region(t_mbx *mbx, t_mbxregion *region)
{
	if (region->image)
		mlx_destroy_image(mbx->mlx, region->image);
	free(region->canvas);
	*region = (t_mbxregion){0};
}
