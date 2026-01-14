/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:15:30 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:06:07 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/types/mbx_s_mbx.h"

void	mbx_region_clear(t_mbxregion *region, t_mbxcolor col)
{
	int	i;

	i = 0;
	while (i < region->width * region->height)
		region->canvas[i++] = col;
}

void	mbx_clear(t_mbx *mbx, t_mbxcolor col)
{
	mbx_region_clear(&mbx->viewport, col);
}
