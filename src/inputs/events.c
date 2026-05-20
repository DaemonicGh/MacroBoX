/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:51:43 by daemo             #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_private/mbx_internal.h"

void	reset_inputs(t_mbx *mbx)
{
	int		i;

	i = 0;
	while (i < MBX_SCANCODES_LENGTH)
	{
		mbx->keys[i].press = 1e30f;
		mbx->keys[i].release = 1e29f;
		i++;
	}
	mbx->last_press = 1e30f;
	mbx->last_release = 1e29f;
	mbx->last_window_event = 1e30f;
	mbx->cursor = vec2_zero();
	mbx->cursor_delta = vec2_zero();
	mbx->scroll_delta = 0;
}

void	mbx_flush_inputs(t_mbx *mbx)
{
	int	i;

	i = 0;
	while (i < MBX_SCANCODES_LENGTH)
	{
		mbx->keys[i].press += mbx->delta_time;
		mbx->keys[i].release += mbx->delta_time;
		i++;
	}
	mbx->last_press += mbx->delta_time;
	mbx->last_release += mbx->delta_time;
	mbx->last_window_event += mbx->delta_time;
	mbx->cursor_delta = vec2_zero();
	mbx->scroll_delta = 0;
}

void	mbx_start_events(t_mbx *mbx)
{
	mlx_on_event(mbx->mlx, mbx->window.mlx,
		MLX_KEYDOWN, key_down_hook, mbx);
	mlx_on_event(mbx->mlx, mbx->window.mlx,
		MLX_KEYUP, key_up_hook, mbx);
	mlx_on_event(mbx->mlx, mbx->window.mlx,
		MLX_MOUSEDOWN, mouse_down_hook, mbx);
	mlx_on_event(mbx->mlx, mbx->window.mlx,
		MLX_MOUSEUP, mouse_up_hook, mbx);
	mlx_on_event(mbx->mlx, mbx->window.mlx,
		MLX_MOUSEWHEEL, mouse_wheel_hook, mbx);
	mlx_on_event(mbx->mlx, mbx->window.mlx,
		MLX_WINDOW_EVENT, window_hook, mbx);
}
