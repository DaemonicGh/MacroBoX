/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:52:30 by daemo             #+#    #+#             */
/*   Updated: 2026/01/19 15:04:30 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/mbx_internal.h"

static void	refresh_deltatime(t_mbx *mbx)
{
	double	time;

	time = get_sec_since_epoch();
	if (time == -1)
		return ;
	mbx->time.delta = time - mbx->time.frame_start;
	mbx->time.frame_start = time;
}

static void	refresh_mouse(t_mbx *mbx)
{
	mbx->inputs.prev_mouse.x = mbx->inputs.mouse.x;
	mbx->inputs.prev_mouse.y = mbx->inputs.mouse.y;
	mlx_mouse_get_pos(mbx->mlx,
		&mbx->inputs.mouse.x, &mbx->inputs.mouse.y);
	mbx->inputs.mouse.x *= (double)mbx->viewport.size.x
		/ mbx->window.size.x;
	mbx->inputs.mouse.y *= (double)mbx->viewport.size.y
		/ mbx->window.size.y;
}

void	mbx_start_frame(t_mbx *mbx)
{
	refresh_deltatime(mbx);
	refresh_mouse(mbx);
	mlx_get_window_size(mbx->mlx, mbx->window.win,
		&mbx->window.size.x, &mbx->window.size.y);
	mlx_clear_window(mbx->mlx, mbx->window.win, mbx->settings.background_color);
}
