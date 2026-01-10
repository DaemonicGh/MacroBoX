/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:51:43 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/02 14:36:02 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"
#include <stdio.h>

void	mbx_flush_inputs(t_mbx *mbx)
{
	int	i;

	i = 0;
	while (i < MBX_INPUT_ARRAY_LENGTH)
	{
		mbx->inputs.btnp[i] = false;
		mbx->inputs.btnr[i++] = false;
	}
	mbx->inputs.mouse_wheel = 0;
}

void	mbx_start_events(t_mbx *mbx)
{
	mlx_on_event(mbx->mlx, mbx->window.win,
		MLX_KEYDOWN, key_down_hook, mbx);
	mlx_on_event(mbx->mlx, mbx->window.win,
		MLX_KEYUP, key_up_hook, mbx);
	mlx_on_event(mbx->mlx, mbx->window.win,
		MLX_MOUSEDOWN, mouse_down_hook, mbx);
	mlx_on_event(mbx->mlx, mbx->window.win,
		MLX_MOUSEUP, mouse_up_hook, mbx);
	mlx_on_event(mbx->mlx, mbx->window.win,
		MLX_MOUSEWHEEL, mouse_wheel_hook, mbx);
	mlx_on_event(mbx->mlx, mbx->window.win,
		MLX_WINDOW_EVENT, window_hook, mbx);
}
