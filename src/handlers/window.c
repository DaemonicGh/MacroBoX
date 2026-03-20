/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:33:36 by daemo             #+#    #+#             */
/*   Updated: 2026/02/05 03:43:21 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/mbx_s_mbx.h"

t_mbxwindow	mbx_make_window(t_mbx *mbx,
		t_vec2i size, char *title, unsigned int flags)
{
	t_mbxwindow	win;

	win.mlx_image = NULL;
	win.size = size;
	win.title = title;
	win.is_fullscreen = flags & MBX_WINDOW_FLAG_FULLSCREEN;
	win.is_resizable = flags & MBX_WINDOW_FLAG_RESIZABLE;
	win.mlx = mlx_new_window(mbx->mlx, &(mlx_window_create_info){
			NULL, win.title, win.size.x, win.size.y,
			win.is_fullscreen, win.is_resizable});
	return (win);
}

t_mbxwindow	mbx_make_window_target(t_mbx *mbx, t_mbximage image)
{
	t_mbxwindow	win;

	win.mlx_image = image.mlx;
	win.size = image.size;
	win.title = "";
	win.is_fullscreen = false;
	win.is_resizable = false;
	win.mlx = mlx_new_window(mbx->mlx, &(mlx_window_create_info){
			win.mlx_image, win.title, win.size.x, win.size.y,
			false, false});
	return (win);
}

void	mbx_refresh_window(t_mbx *mbx, t_mbxwindow *window)
{
	mlx_set_window_size(mbx->mlx, window->mlx,
		window->size.x, window->size.y);
	mlx_set_window_title(mbx->mlx, window->mlx, window->title);
	mlx_set_window_fullscreen(mbx->mlx,
		window->mlx, window->is_fullscreen);
}

void	mbx_center_window(t_mbx *mbx, t_mbxwindow *window)
{
	t_vec2i	screen;

	mlx_get_screen_size(mbx->mlx, window->mlx, &screen.x, &screen.y);
	mlx_set_window_position(mbx->mlx, window->mlx,
		screen.x / 2 - window->size.x / 2,
		screen.y / 2 - window->size.y / 2);
}

void	mbx_destroy_window(t_mbx *mbx, t_mbxwindow *window)
{
	mlx_destroy_window(mbx->mlx, window->mlx);
}
