/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:15:30 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/10 14:07:03 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

void	mbx_region_clear(t_mbxregion *region, mlx_color col)
{
	int	i;

	i = 0;
	while (i < region->width * region->height)
		region->canvas[i++] = col;
}

void	mbx_clear(t_mbx *mbx, mlx_color col)
{
	mbx_region_clear(&mbx->viewport, col);
}
