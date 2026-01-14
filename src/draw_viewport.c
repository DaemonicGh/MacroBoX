/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_viewport.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:56:25 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:21:23 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/modules/mbx_drawing.h"
#include "../includes/modules/mbx_math.h"
#include "../includes/modules/mbx_mlx_ext.h"

void	draw_viewport(t_mbx *mbx)
{
	const int			scale = min(
			mbx->window.width / mbx->viewport.width,
			mbx->window.height / mbx->viewport.height);
	const t_vec2i		size = vec2i(mbx->viewport.width * scale,
			mbx->viewport.height * scale);

	if (scale == 1)
	{
		mlx_pixel_put_region(mbx->mlx, mbx->window.win,
			(mbx->window.width - (size.x)) / 2,
			(mbx->window.height - (size.y)) / 2,
			size.x, size.y, mbx->viewport.canvas);
		return ;
	}
	if (!mbx->viewport.image)
		mbx->viewport.image = mlx_new_image(mbx->mlx,
				mbx->viewport.width, mbx->viewport.height);
	if (!mbx->viewport.image)
		return ;
	mlx_set_image_region(mbx->mlx, mbx->viewport.image, 0, 0,
		mbx->viewport.width, mbx->viewport.height, mbx->viewport.canvas);
	mlx_put_transformed_image_to_window(mbx->mlx, mbx->window.win,
		mbx->viewport.image, (mbx->window.width - (size.x)) / 2,
		(mbx->window.height - (size.y)) / 2, scale, scale, 0);
}
