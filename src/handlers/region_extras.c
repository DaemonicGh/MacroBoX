/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   region_extras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:55:02 by rprieur           #+#    #+#             */
/*   Updated: 2026/03/25 20:55:03 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_drawing.h"
#include "modules/mbx_handlers.h"
#include "modules/types/mbx_s_region.h"

bool	mbx_resize_region(t_mbx *mbx, t_mbx_region **region, t_vec2i size)
{
	t_mbx_region	*new;

	if ((*region)->image)
		new = mbx_make_region_with_image(mbx, size);
	else
		new = mbx_make_region(mbx, size);
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
		new = mbx_make_region_with_image(mbx, size);
	else
		new = mbx_make_region(mbx, size);
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
