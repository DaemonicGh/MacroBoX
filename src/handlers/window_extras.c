/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_extras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:33:36 by daemo             #+#    #+#             */
/*   Updated: 2026/02/05 03:43:21 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/mbx_s_mbx.h"

void	mbx_refresh_window(t_mbx *mbx, t_mbx_window *window)
{
	t_vec2i	old_size;

	old_size = window->size;
	mlx_get_window_position(
		mbx->mlx, window->mlx, &window->pos.x, &window->pos.y);
	mlx_get_window_size(
		mbx->mlx, window->mlx, &window->size.x, &window->size.y);
	mlx_get_screen_size(
		mbx->mlx, window->mlx, &window->screen_size.x, &window->screen_size.y);
	mbx->cursor = vec2i_mult_vd(mbx->cursor,
			vec2i_truediv(old_size, window->size));
}

void	mbx_update_window(t_mbx *mbx, t_mbx_window *window)
{
	mlx_set_window_position(
		mbx->mlx, window->mlx, window->pos.x, window->pos.y);
	mlx_set_window_size(
		mbx->mlx, window->mlx, window->size.x, window->size.y);
	mlx_set_window_min_size(
		mbx->mlx, window->mlx, window->limits.p1.x, window->limits.p1.y);
	mlx_set_window_max_size(
		mbx->mlx, window->mlx, window->limits.p2.x, window->limits.p2.y);
	mlx_set_window_title(mbx->mlx, window->mlx, window->title);
	mlx_set_window_fullscreen(mbx->mlx, window->mlx, window->is_fullscreen);
	if (window->is_minimized)
		mlx_minimize_window(mbx->mlx, window->mlx);
	else if (window->is_maximized)
		mlx_maximise_window(mbx->mlx, window->mlx);
	else
		mlx_restore_window(mbx->mlx, window->mlx);
}
