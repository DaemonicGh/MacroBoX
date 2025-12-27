/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:52:50 by daemo             #+#    #+#             */
/*   Updated: 2025/12/27 21:41:42 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mbx.h"

static inline void	draw_viewport_keep(t_mbxcontext *mbx)
{
	const double	smallest = fmin(
			(double)mbx->window.width / mbx->viewport.width,
			(double)mbx->window.height / mbx->viewport.height);

	mlx_put_transformed_image_to_window(mbx->mlx, mbx->window.win,
		mbx->viewport.image,
		(mbx->window.width - (mbx->viewport.width * smallest)) / 2,
		(mbx->window.height - (mbx->viewport.height * smallest)) / 2,
		smallest, smallest, 0);
}

static inline void	draw_viewport_stretch(t_mbxcontext *mbx)
{
	mlx_put_transformed_image_to_window(mbx->mlx, mbx->window.win,
		mbx->viewport.image, 0, 0,
		(double)mbx->window.width / mbx->viewport.width,
		(double)mbx->window.height / mbx->viewport.height, 0);
}

static void	draw_viewport(t_mbxcontext *mbx)
{
	if (mbx->settings.viewport_mode == MBX_VIEWPORT_MODE_KEEP)
		draw_viewport_keep(mbx);
	else if (mbx->settings.viewport_mode == MBX_VIEWPORT_MODE_STRETCH)
		draw_viewport_stretch(mbx);
}

void	mbx_end_frame(t_mbxcontext *mbx)
{
	draw_viewport(mbx);
	mbx_flush_inputs(mbx);
	mbx_refresh_settings(mbx);
	mbx->time.frames_elapsed++;
}
