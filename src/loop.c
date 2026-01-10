/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:12:15 by daemo             #+#    #+#             */
/*   Updated: 2026/01/09 02:03:55 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mbx.h"
#include "../includes/mbx_internal.h"

static bool	skip_frame(t_mbx *mbx)
{
	double	time;

	time = get_sec_since_epoch();
	if (time == -1)
		return (false);
	if (time < mbx->time.frame_start
		+ MBX_FRAME_SKIP_MARGIN_RATIO / mbx->settings.fps_cap)
		return (true);
	return (false);
}

static void	mbx_loop(void *rawcontext)
{
	t__mbxloopcontext	*context;

	context = rawcontext;
	if (skip_frame(context->mbx))
		return ;
	mbx_start_frame(context->mbx);
	context->update(context->mbx, context->args);
	mbx_end_frame(context->mbx);
}

void	mbx_run(t_mbx *mbx,
		void (*update)(t_mbx *mbx, void *args), void *args)
{
	t__mbxloopcontext	context;

	context.mbx = mbx;
	context.update = update;
	context.args = args;
	mlx_add_loop_hook(mbx->mlx, &mbx_loop, &context);
	mlx_loop(mbx->mlx);
}
