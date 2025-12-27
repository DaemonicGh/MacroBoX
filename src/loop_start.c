/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:52:30 by daemo             #+#    #+#             */
/*   Updated: 2025/12/27 21:00:09 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mbx.h"

static void	refresh_deltatime(t_mbxcontext *mbx)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	mbx->time.delta = (double)(end.tv_sec - mbx->time.frame_start.tv_sec)
		+ (double)(end.tv_usec - mbx->time.frame_start.tv_usec) / 1000000;
	mbx->time.frame_start = end;
}

static void	refresh_mouse(t_mbxcontext *mbx)
{
	mbx->inputs.prev_mouse.x = mbx->inputs.mouse.x;
	mbx->inputs.prev_mouse.y = mbx->inputs.mouse.y;
	mlx_mouse_get_pos(mbx->mlx,
		&mbx->inputs.mouse.x, &mbx->inputs.mouse.y);
	mbx->inputs.mouse.x *= (double)mbx->viewport.width
		/ mbx->window.width;
	mbx->inputs.mouse.y *= (double)mbx->viewport.height
		/ mbx->window.height;
}

void	mbx_start_frame(t_mbxcontext *mbx)
{
	refresh_deltatime(mbx);
	refresh_mouse(mbx);
	mlx_get_window_size(mbx->mlx, mbx->window.win,
		&mbx->window.width, &mbx->window.height);
	mlx_clear_window(mbx->mlx, mbx->window.win, (mlx_color){.rgba = 0x0});
}