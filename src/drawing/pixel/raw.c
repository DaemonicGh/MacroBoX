/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:13:32 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 15:53:33 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_drawing.h"

void	mbx_set_pixel_raw_i(t_mbxregion *region, int i, t_mbxcolor col)
{
	region->canvas[i] = col;
}

void	mbx_set_pixel_raw_xy(t_mbxregion *region,
	int x, int y, t_mbxcolor col)
{
	region->canvas[y * region->size.x + x] = col;
}

void	mbx_set_pixel_raw(t_mbxregion *region,
	t_vec2i pos, t_mbxcolor col)
{
	region->canvas[pos.y * region->size.x + pos.x] = col;
}
