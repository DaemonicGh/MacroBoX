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

#include "modules/types/mbx_s_mbx.h"

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
}

void	mbx_tap_input(t_mbx *mbx, int key)
{
	if (key < MBX_INPUT_ARRAY_START
		|| key > MBX_INPUT_ARRAY_END)
		return ;
	mbx->presses[key] = -0.0;
	mbx->last_press = mbx->timestamps.frame_start;
	special_key_handler(mbx, key);
}

void	mbx_press_input(t_mbx *mbx, int key)
{
	if (key < MBX_INPUT_ARRAY_START
		|| key > MBX_INPUT_ARRAY_END)
		return ;
	if (mbx->presses[key] >= -MBX_INPUT_EPSILON)
		mbx->presses[key] = 0.0;
	else
		mbx->presses[key] = MBX_INPUT_EPSILON;
	mbx->last_press = mbx->timestamps.frame_start;
	special_key_handler(mbx, key);
}

void	mbx_release_input(t_mbx *mbx, int key)
{
	if (key < MBX_INPUT_ARRAY_START
		|| key > MBX_INPUT_ARRAY_END)
		return ;
	if (mbx->presses[key] <= MBX_INPUT_EPSILON)
		mbx->presses[key] = -0.0;
	else
		mbx->presses[key] = -MBX_INPUT_EPSILON;
}
