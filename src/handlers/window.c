/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:33:36 by daemo             #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_handlers.h"
#include "modules/types/mbx_s_window.h"

t_mbx_window	mbx_make_window(t_mbx *mbx,
		t_vec2i size, char *title, t_mbx_window_flags flags)
{
	t_mbx_window	win;

	win = (t_mbx_window){
		.mlx_image = NULL,
		.size = size, .title = title,
		.is_fullscreen = flags & MBX_WINDOW_FLAG_FULLSCREEN,
		.is_resizable = flags & MBX_WINDOW_FLAG_RESIZABLE,
		.is_minimized = flags & MBX_WINDOW_FLAG_MINIMIZED,
		.is_maximized = false, .is_focused = true
	};
	win.mlx = mlx_new_window(mbx->mlx, &(mlx_window_create_info){
			NULL, win.title, size.x, size.y,
			win.is_fullscreen, win.is_resizable});
	mbx_refresh_window(mbx, &win);
	win.limits = vec2ix2(vec2i_zero(), win.screen_size);
	mlx_set_window_min_size(
		mbx->mlx, win.mlx, win.limits.p1.x, win.limits.p1.y);
	mlx_set_window_max_size(
		mbx->mlx, win.mlx, win.limits.p2.x, win.limits.p2.y);
	if (win.is_minimized)
		mlx_minimize_window(mbx->mlx, win.mlx);
	return (win);
}

t_mbx_window	mbx_make_window_with_target(t_mbx *mbx,
		t_vec2i size, char *title, t_mbx_window_flags flags)
{
	t_mbx_window	win;

	win.mlx_image = mlx_new_image(mbx->mlx, size.x, size.y);
	if (!win.mlx_image)
		return ((t_mbx_window){0});
	win = (t_mbx_window){
		.mlx_image = win.mlx_image,
		.size = size, .title = title,
		.is_fullscreen = flags & MBX_WINDOW_FLAG_FULLSCREEN,
		.is_resizable = false,
		.is_minimized = flags & MBX_WINDOW_FLAG_MINIMIZED,
		.is_maximized = false, .is_focused = true
	};
	win.mlx = mlx_new_window(mbx->mlx, &(mlx_window_create_info){
			win.mlx_image, win.title, win.size.x, win.size.y,
			win.is_fullscreen, win.is_resizable});
	mbx_refresh_window(mbx, &win);
	win.limits = vec2ix2(vec2i_zero(), win.screen_size);
	mlx_set_window_min_size(
		mbx->mlx, win.mlx, win.limits.p1.x, win.limits.p1.y);
	mlx_set_window_max_size(
		mbx->mlx, win.mlx, win.limits.p2.x, win.limits.p2.y);
	if (win.is_minimized)
		mlx_minimize_window(mbx->mlx, win.mlx);
	return (win);
}

t_mbx_window	mbx_make_window_target(t_mbx *mbx, t_mbx_image image)
{
	t_mbx_window	win;

	win = (t_mbx_window){0};
	win.mlx_image = image.mlx;
	win.size = image.size;
	win.title = "";
	win.mlx = mlx_new_window(mbx->mlx, &(mlx_window_create_info){
			win.mlx_image, win.title, win.size.x, win.size.y,
			false, false});
	return (win);
}

void	mbx_destroy_window(t_mbx *mbx, t_mbx_window *window)
{
	mlx_destroy_window(mbx->mlx, window->mlx);
	*window = (t_mbx_window){0};
}
