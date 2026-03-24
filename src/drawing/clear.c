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
#include "../_private/mbx_simd.h"

void	mbx_clear(t_mbx_region *restrict region, t_mbx_color col)
{
	const t_col4	vcol = {col.rgba, col.rgba, col.rgba, col.rgba};
	const int		size = region->size.x * region->size.y;
	int				i;

	i = 0;
	while (i < size - 4)
	{
		*(t_col4 *)(region->canvas + i) = vcol;
		i += 4;
	}
	while (i < size)
		region->canvas[i++] = col;
}
