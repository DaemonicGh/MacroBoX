/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:20:38 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "modules/mbx_handlers.h"
#include "../_private/mbx_internal.h"

static void	window_events_handler(t_mbx *mbx, int event)
{
	if (event == MBX_WINDOW_MAXIMIZE)
		mbx->window.is_maximized = true;
	else if (event == MBX_WINDOW_MINIMIZE)
		mbx->window.is_minimized = true;
	else if (event == MBX_WINDOW_FOCUS)
	{
		mbx->window.is_minimized = false;
		mbx->window.is_focused = true;
	}
	else if (event == MBX_WINDOW_UNFOCUS)
		mbx->window.is_focused = false;
	mbx_refresh_window(mbx, &mbx->window);
	if (event == MBX_WINDOW_MOVE
		&& mbx->window.pos.x != 0 && mbx->window.pos.y != 60)
		mbx->window.is_maximized = false;
	refresh_mlx_fps_cap(mbx);
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
	if (key >= MBX_SCANCODES_WINDOW_START)
		window_events_handler(mbx, key);
}

void	mbx_press_input(t_mbx *mbx, int key)
{
	if (key < MBX_SCANCODES_START || key > MBX_SCANCODES_END)
		return ;
	mbx->keys[key].press = 0;
	if (key >= MBX_SCANCODES_WINDOW_START)
		mbx->last_window_event = 0;
	else
		mbx->last_press = 0;
	special_key_handler(mbx, key);
}

void	mbx_release_input(t_mbx *mbx, int key)
{
	if (key < MBX_SCANCODES_START || key > MBX_SCANCODES_END)
		return ;
	mbx->keys[key].release = 0;
	if (key >= MBX_SCANCODES_WINDOW_START)
		mbx->last_window_event = 0;
	else
		mbx->last_release = 0;
}

void	mbx_tap_input(t_mbx *mbx, int key)
{
	if (key < MBX_SCANCODES_START || key > MBX_SCANCODES_END)
		return ;
	mbx->keys[key].press = 0;
	mbx->keys[key].release = 0;
	if (key >= MBX_SCANCODES_WINDOW_START)
		mbx->last_window_event = 0;
	else
	{
		mbx->last_press = 0;
		mbx->last_release = 0;
	}
	special_key_handler(mbx, key);
}
