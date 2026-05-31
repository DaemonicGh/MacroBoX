/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:55:02 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "modules/mbx_drawing.h"
#include "modules/mbx_handlers.h"

bool	mbx_resize_region(t_mbx *mbx, t_mbx_region **region, t_vec2i size)
{
	t_mbx_region	*new;

	if ((*region)->image)
		new = mbx_create_region_with_image(mbx, size);
	else
		new = mbx_create_region(mbx, size);
	if (!new)
		return (false);
	new->pipeline = (*region)->pipeline;
	mbx_destroy_region(mbx, *region);
	*region = new;
	return (true);
}

bool	mbx_resize_region_with_content(
	t_mbx *mbx, t_mbx_region **region, t_vec2i size)
{
	t_mbx_region	*new;
	t_mbx_region	region_data;

	if ((*region)->image)
		new = mbx_create_region_with_image(mbx, size);
	else
		new = mbx_create_region(mbx, size);
	if (!new)
		return (false);
	region_data = **region;
	(*region)->pipeline = mbx->settings.default_pipeline;
	mbx_set_region_scaled(new, *region,
		vec2i_zero(), vec2i_truediv(size, (*region)->size));
	mbx_destroy_region(mbx, *region);
	*new = region_data;
	new->size = size;
	*region = new;
	return (true);
}

bool	mbx_create_region_image(t_mbx *mbx, t_mbx_region *region)
{
	t_mbx_image	image;

	image = mbx_create_image(mbx, region->size);
	if (!image.mlx)
		return (false);
	region->image = image.mlx;
	return (true);
}

void	mbx_destroy_region(t_mbx *mbx, t_mbx_region *region)
{
	if (!region)
		return ;
	if (region->image)
		if (!mbx_free(mbx, region->image))
			mlx_destroy_image(mbx->mlx, region->image);
	if (!mbx_free(mbx, region))
		free(region);
}
