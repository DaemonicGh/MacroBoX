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

#include "../../includes/modules/mbx_drawing.h"
#include "../../includes/modules/mbx_color.h"

void	mbx_region_clear(t_mbxregion *region, t_mbxcolor col)
{
	int	i;

	if (col.a == 0)
		return ;
	if (col.a == 255)
	{
		i = 0;
		while (i < region->size.x * region->size.y)
			region->canvas[i++] = col;
	}
	else
	{
		i = 0;
		while (i < region->size.x * region->size.y)
		{
			region->canvas[i] = color_blend_quick(region->canvas[i], col);
			i++;
		}
	}
}

void	mbx_clear(t_mbx *mbx, t_mbxcolor col)
{
	mbx_region_clear(&mbx->viewport, col);
}
