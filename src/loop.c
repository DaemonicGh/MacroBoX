/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:12:15 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/22 22:00:28 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mbx.h"

void	mbx_start_frame(t_mbxcontext *mbx)
{
	mbx->inputs.prev_mouse.x = mbx->inputs.mouse.x;
	mbx->inputs.prev_mouse.y = mbx->inputs.mouse.y;
	mlx_mouse_get_pos(mbx->mlx,
		&mbx->inputs.mouse.x, &mbx->inputs.mouse.y);
	mbx->inputs.mouse.x *= (float)mbx->viewport.width
		/ mbx->window.width;
	mbx->inputs.mouse.y *= (float)mbx->viewport.height
		/ mbx->window.height;
	mlx_get_window_size(mbx->mlx, mbx->window.win,
		&mbx->window.width, &mbx->window.height);
	mlx_clear_window(mbx->mlx, mbx->window.win, (mlx_color){.rgba = 0x0});
}

void	mbx_end_frame(t_mbxcontext *mbx)
{
	mbx_flush_inputs(mbx);
	mbx_refresh_settings(mbx);
	mbx->time.frames_elapsed++;
}

static void	mbx_loop(void *rawcontext)
{
	struct timeval		end;
	t__mbxloopcontext	*context;

	context = rawcontext;
	gettimeofday(&end, NULL);
	context->mbx->time.delta = (double)
		(end.tv_sec - context->mbx->time.frame_start.tv_sec) + (double)
		(end.tv_usec - context->mbx->time.frame_start.tv_usec) / 1000000;
	context->mbx->time.frame_start = end;
	mbx_start_frame(context->mbx);
	context->update(context->mbx, context->args);
	mbx_end_frame(context->mbx);
}

void	mbx_run(t_mbxcontext *mbx,
		void (*update)(t_mbxcontext *mbx, void *args), void *args)
{
	t__mbxloopcontext	context;

	context.mbx = mbx;
	context.update = update;
	context.args = args;
	mlx_add_loop_hook(mbx->mlx, &mbx_loop, &context);
	mlx_loop(mbx->mlx);
}
