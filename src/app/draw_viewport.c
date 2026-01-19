/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_viewport.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:56:25 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 15:06:47 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/types/mbx_s_mbx.h"
#include "../../includes/modules/mbx_math.h"
#include "../../includes/modules/mbx_mlx_ext.h"
#include <stdlib.h>

void	draw_viewport(t_mbx *mbx)
{
	const int			scale = min(
			mbx->window.size.x / mbx->viewport.size.x,
			mbx->window.size.y / mbx->viewport.size.y);
	const t_vec2i		size = vec2i(mbx->viewport.size.x * scale,
			mbx->viewport.size.y * scale);

	if (!mbx->viewport.image)
		mbx->viewport.image = mlx_new_image(mbx->mlx,
				mbx->viewport.size.x, mbx->viewport.size.y);
	if (!mbx->viewport.image)
		return ;
	mlx_set_image_region(mbx->mlx, mbx->viewport.image, 0, 0,
		mbx->viewport.size.x, mbx->viewport.size.y, mbx->viewport.canvas);
	mlx_put_transformed_image_to_window(mbx->mlx, mbx->window.win,
		mbx->viewport.image, (mbx->window.size.x - (size.x)) / 2,
		(mbx->window.size.y - (size.y)) / 2, scale, scale, 0);
}
