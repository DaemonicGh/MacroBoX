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

#include "mlx_extended.h"
#include "modules/types/mbx_s_mbx.h"
#include "modules/types/mbx_s_window.h"

t_mbxwindow	mbx_make_window(t_mbx *mbx,
		t_vec2i size, char *title, unsigned int flags)
{
	t_mbxwindow	win;

	win.mlx_image = NULL;
	win.size = size;
	win.title = title;
	win.is_fullscreen = flags & MBX_WINDOW_FLAG_FULLSCREEN;
	win.is_resizable = flags & MBX_WINDOW_FLAG_RESIZABLE;
	win.is_minimized = flags & MBX_WINDOW_FLAG_MINIMIZED;
	win.is_maximized = false;
	win.limits = vec2ix2(vec2i_zero(), mbx->screen_size);
	win.mlx = mlx_new_window(mbx->mlx, &(mlx_window_create_info){
			NULL, win.title, win.size.x, win.size.y,
			win.is_fullscreen, win.is_resizable});
	mlx_get_window_position(mbx->mlx, win.mlx, &win.pos.x, &win.pos.y);
	if (win.is_minimized)
		mlx_minimize_window(mbx->mlx, win.mlx);
	return (win);
}

t_mbxwindow	mbx_make_window_target(t_mbx *mbx, t_mbximage image)
{
	t_mbxwindow	win;

	win = (t_mbxwindow){0};
	win.mlx_image = image.mlx;
	win.size = image.size;
	win.title = "";
	win.mlx = mlx_new_window(mbx->mlx, &(mlx_window_create_info){
			win.mlx_image, win.title, win.size.x, win.size.y,
			false, false});
	return (win);
}

void	mbx_destroy_window(t_mbx *mbx, t_mbxwindow *window)
{
	mlx_destroy_window(mbx->mlx, window->mlx);
	*window = (t_mbxwindow){0};
}
