/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:15:30 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/18 21:07:22 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_drawing.h"

void	mbx_clear(t_mbx_region *restrict region, t_mbx_color col)
{
	const t_mbx_color	mcol = region->color_setter(
			region->color_modifier_data, col);
	const int			size = region->size.x * region->size.y;
	int					i;

	i = 0;
	while (i < size)
		region->pixels[i++] = mcol;
}
