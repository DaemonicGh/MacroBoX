/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:33:36 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/21 21:17:47 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mbx.h"

t_mbxwindow	mbx_make_window(t_mbxcontext *mbx,
		t_vec2i size, char *title, int mode)
{
	t_mbxwindow	win;

	win.image = NULL;
	win.width = size.x;
	win.height = size.y;
	win.title = title;
	win.is_fullscreen = mode >> 1 & 1;
	if (mode & 1)
		write(1, "\033[1;36mMacroBoX doesn't support window resizing yet, \
			sorry :P\033[0m\n", 66);
	win.is_resizable = 0;
	win.win = mlx_new_window(mbx->mlx, &(mlx_window_create_info){
			NULL, win.title, win.width, win.height,
			win.is_fullscreen, win.is_resizable});
	return (win);
}

t_mbxwindow	mbx_make_window_target(t_mbxcontext *mbx, t_mbximage image)
{
	t_mbxwindow	win;

	win.image = image.img;
	win.width = image.width;
	win.height = image.height;
	win.title = "";
	win.is_fullscreen = false;
	win.is_resizable = false;
	win.win = mlx_new_window(mbx->mlx, &(mlx_window_create_info){
			win.image, win.title, win.width, win.height,
			win.is_fullscreen, win.is_resizable});
	return (win);
}

void	mbx_refresh_window(t_mbxcontext *mbx)
{
	mlx_set_window_size(mbx->mlx, mbx->window.win,
		mbx->window.width, mbx->window.height);
	mlx_set_window_title(mbx->mlx, mbx->window.win, mbx->window.title);
	mlx_set_window_fullscreen(mbx->mlx,
		mbx->window.win, mbx->window.is_fullscreen);
}

void	mbx_center_window(t_mbxcontext *mbx)
{
	t_vec2i	screen;

	mlx_get_screen_size(mbx->mlx, mbx->window.win, &screen.x, &screen.y);
	mlx_set_window_position(mbx->mlx, mbx->window.win,
		screen.x / 2 - mbx->window.width / 2,
		screen.y / 2 - mbx->window.height / 2);
}
