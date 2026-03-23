/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:20:38 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 17:13:03 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "modules/mbx_handlers.h"
#include <stdio.h>

static void	window_events_handler(t_mbx *mbx, int event)
{
	if (event == MBX_WINDOW_MOVE)
	{
		mlx_get_window_position(
			mbx->mlx, mbx->window.mlx, &mbx->window.pos.x, &mbx->window.pos.y);
		if (mbx->window.pos.x != 0 && mbx->window.pos.y != 60)
			mbx->window.is_maximized = false;
	}
	else if (event == MBX_WINDOW_RESIZE)
		mlx_get_window_size(mbx->mlx, mbx->window.mlx,
			&mbx->window.size.x, &mbx->window.size.y);
	else if (event == MBX_WINDOW_MAXIMIZE)
		mbx->window.is_maximized = true;
	else if (event == MBX_WINDOW_MINIMIZE)
		mbx->window.is_minimized = true;
	else if (event == MBX_WINDOW_FOCUS)
		mbx->window.is_minimized = false;
}

static void	special_key_handler(t_mbx *mbx, int key)
{
	if ((mbx->settings.do_window_cross_exit && key == MBX_WINDOW_CLOSE)
		|| mbx->settings.exit_key == key)
		mbx->exiting = true;
	else if (mbx->settings.fullscreen_toggle_key == key)
	{
		mbx->window.is_fullscreen = !mbx->window.is_fullscreen;
		mlx_set_window_fullscreen(
			mbx->mlx, mbx->window.mlx,
			mbx->window.is_fullscreen);
	}
	if (key >= MBX_INPUT_ARRAY_WINDOW_START
		&& key <= MBX_INPUT_ARRAY_WINDOW_END)
		window_events_handler(mbx, key);
}

void	mbx_tap_input(t_mbx *mbx, int key)
{
	if (key < MBX_INPUT_ARRAY_START
		|| key > MBX_INPUT_ARRAY_END)
		return ;
	mbx->key_presses[key] = 0;
	mbx->key_releases[key] = 0;
	mbx->last_press = mbx->timestamps.frame_start;
	mbx->last_release = mbx->timestamps.frame_start;
	special_key_handler(mbx, key);
}

void	mbx_press_input(t_mbx *mbx, int key)
{
	if (key < MBX_INPUT_ARRAY_START
		|| key > MBX_INPUT_ARRAY_END)
		return ;
	mbx->key_presses[key] = 0;
	mbx->last_press = mbx->timestamps.frame_start;
	special_key_handler(mbx, key);
}

void	mbx_release_input(t_mbx *mbx, int key)
{
	if (key < MBX_INPUT_ARRAY_START
		|| key > MBX_INPUT_ARRAY_END)
		return ;
	mbx->key_releases[key] = 0;
	mbx->last_release = mbx->timestamps.frame_start;
}
