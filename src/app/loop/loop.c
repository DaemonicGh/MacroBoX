/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:12:15 by daemo             #+#    #+#             */
/*   Updated: 2026/05/29 03:22:53 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_handlers.h"
#include "modules/mbx_inputs.h"
#include "../../_private/mbx_internal.h"

static void	mbx_loop(void *rawcontext)
{
	t__mbxloopcontext	*context;

	context = rawcontext;
	if (should_skip_frame(context->mbx))
		return ;
	mbx_start_frame(context->mbx);
	context->update(context->mbx, context->args);
	mbx_end_frame(context->mbx);
	if (context->mbx->exiting)
		mlx_loop_end(context->mbx->mlx);
}

static void	enter_loop(t_mbx *mbx)
{
	update_time_values(mbx);
	mbx_refresh_settings(mbx);
	if (mbx->settings.lock_cursor)
		mbx_warp_cursor(mbx, vec2i_div_d(mbx->viewport->size, 2));
	mbx_report_nbr(mbx, "Got ", mbx->allocator.alloc_count,
		" memory blocks upon loop start");
}

static void	exit_loop(t_mbx *mbx)
{
	const uint32_t	prev_allocs = mbx->allocator.alloc_count;

	mbx_free_groups(mbx, MBX_ALLOC_FREE_ON_RUN_END, MBX_ALLOC_EMPTY);
	mbx_report_nbr(mbx, "Cleared ", prev_allocs - mbx->allocator.alloc_count,
		" memory blocks upon loop end");
	mbx_report_nbr(mbx, "Got ", mbx->allocator.alloc_count,
		" memory blocks left upon loop end");
}

void	mbx_run(t_mbx *mbx,
		void (*update)(t_mbx *mbx, void *args), void *args)
{
	t__mbxloopcontext	context;

	context.mbx = mbx;
	context.update = update;
	context.args = args;
	if (!mbx->window.mlx || !mbx->viewport)
		return ;
	enter_loop(mbx);
	mlx_add_loop_hook(mbx->mlx, &mbx_loop, &context);
	mlx_loop(mbx->mlx);
	exit_loop(mbx);
}
