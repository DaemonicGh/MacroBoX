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

void	mbx_modify_region(t_mbx_region *dest, void *color_modifier_data,
	t_mbx_color (*color_getter)(void *data, t_mbx_region *region, int i),
	t_mbx_color (*color_setter)(void *data, t_mbx_color col))
{
	int	i;

	if (!color_modifier_data)
		color_modifier_data = dest->color_modifier_data;
	if (!color_getter)
		color_getter = &mbx_color_getter_ignore;
	if (!color_setter)
		color_setter = &mbx_color_setter_ignore;
	i = 0;
	while (i < dest->size.x * dest->size.y)
	{
		dest->canvas[i] = color_setter(color_modifier_data,
				color_getter(color_modifier_data, dest, i));
		i++;
	}
}

bool	mbx_resize_region(t_mbx *mbx, t_mbx_region **region, t_vec2i size)
{
	t_mbx_region	*new;

	if ((*region)->image)
		new = mbx_make_region_with_image(mbx, size);
	else
		new = mbx_make_region(mbx, size);
	if (!new)
		return (false);
	new->color_getter = (*region)->color_getter;
	new->color_setter = (*region)->color_setter;
	new->color_modifier_data = (*region)->color_modifier_data;
	mbx_destroy_region(mbx, *region);
	*region = new;
	return (true);
}

bool	mbx_resize_region_with_content(
	t_mbx *mbx, t_mbx_region **region, t_vec2i size)
{
	t_mbx_region	*new;
	void			*getter;
	void			*setter;

	if ((*region)->image)
		new = mbx_make_region_with_image(mbx, size);
	else
		new = mbx_make_region(mbx, size);
	if (!new)
		return (false);
	getter = (*region)->color_getter;
	setter = (*region)->color_setter;
	(*region)->color_getter = &mbx_color_getter_ignore;
	(*region)->color_setter = &mbx_color_setter_ignore;
	new->color_getter = &mbx_color_getter_ignore;
	new->color_setter = &mbx_color_setter_ignore;
	new->color_modifier_data = (*region)->color_modifier_data;
	mbx_set_region_scaled(new, *region,
		vec2i_zero(), vec2i_truediv(size, (*region)->size));
	mbx_destroy_region(mbx, *region);
	new->color_getter = getter;
	new->color_setter = setter;
	*region = new;
	return (true);
}
