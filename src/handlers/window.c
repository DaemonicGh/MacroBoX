/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:33:36 by daemo             #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_handlers.h"
#include "modules/mbx_structs.h"

static bool	final_window_setup(t_mbx *mbx, t_mbx_window *win)
{
	if (!mbx_add_alloc(mbx, win->mlx, MBX_ALLOC_TYPE_MLX_WINDOW
			| MBX_ALLOC_GROUP_MBX | MBX_ALLOC_GROUP_MLX))
	{
		mlx_destroy_window(mbx->mlx, win->mlx);
		return (false);
	}
	mbx_refresh_window(mbx, win);
	win->limits = vec2ix2(vec2i_zero(), win->screen_size);
	mbx_update_window(mbx, win);
	return (true);
}

t_mbx_window	mbx_create_window(t_mbx *mbx,
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
	if (!final_window_setup(mbx, &win))
		return ((t_mbx_window){0});
	return (win);
}

t_mbx_window	mbx_create_window_with_target(t_mbx *mbx,
		t_vec2i size, char *title, t_mbx_window_flags flags)
{
	t_mbx_image		image;
	t_mbx_window	win;

	image = mbx_create_image(mbx, size);
	if (!image.mlx)
		return ((t_mbx_window){0});
	win = (t_mbx_window){
		.mlx_image = image.mlx,
		.size = size, .title = title,
		.is_fullscreen = flags & MBX_WINDOW_FLAG_FULLSCREEN,
		.is_resizable = false,
		.is_minimized = flags & MBX_WINDOW_FLAG_MINIMIZED,
		.is_maximized = false, .is_focused = true
	};
	win.mlx = mlx_new_window(mbx->mlx, &(mlx_window_create_info){
			win.mlx_image, win.title, win.size.x, win.size.y,
			win.is_fullscreen, win.is_resizable});
	if (!final_window_setup(mbx, &win))
		return ((t_mbx_window){0});
	return (win);
}

t_mbx_window	mbx_create_window_target(t_mbx *mbx, t_mbx_image image)
{
	t_mbx_window	win;

	win = (t_mbx_window){0};
	win.mlx_image = image.mlx;
	win.size = image.size;
	win.title = "";
	win.mlx = mlx_new_window(mbx->mlx, &(mlx_window_create_info){
			win.mlx_image, win.title, win.size.x, win.size.y,
			false, false});
	if (!mbx_add_alloc(mbx, win.mlx, MBX_ALLOC_TYPE_MLX_WINDOW
			| MBX_ALLOC_GROUP_MBX | MBX_ALLOC_GROUP_MLX))
	{
		mlx_destroy_window(mbx->mlx, win.mlx);
		return ((t_mbx_window){0});
	}
	return (win);
}

void	mbx_destroy_window(t_mbx *mbx, t_mbx_window *window)
{
	if (!window)
		return ;
	if (window->mlx_image)
		if (!mbx_free(mbx, window->mlx_image))
			mlx_destroy_image(mbx->mlx, window->mlx_image);
	if (!mbx_free(mbx, window->mlx))
		mlx_destroy_window(mbx->mlx, window->mlx);
}
