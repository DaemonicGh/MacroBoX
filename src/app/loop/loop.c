/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:12:15 by daemo             #+#    #+#             */
/*   Updated: 2026/01/19 15:05:39 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_inputs.h"
#include "veclc.h"
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

void	mbx_run(t_mbx *mbx,
		void (*update)(t_mbx *mbx, void *args), void *args)
{
	t__mbxloopcontext	context;

	context.mbx = mbx;
	context.update = update;
	context.args = args;
	enter_loop(mbx);
	mlx_add_loop_hook(mbx->mlx, &mbx_loop, &context);
	mlx_loop(mbx->mlx);
	exit_loop(mbx);
}
