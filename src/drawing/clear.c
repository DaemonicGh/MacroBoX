/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:15:30 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/07 22:32:39 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

void	mbx_region_clear(t_mbxregion *region, mlx_color color)
{
	int	i;

	i = 0;
	while (i < region->width * region->height)
		region->canvas[i++] = color;
}

void	mbx_clear(t_mbx *mbx, mlx_color color)
{
	mbx_region_clear(&mbx->viewport, color);
}
