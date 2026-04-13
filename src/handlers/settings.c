/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:28:29 by daemo             #+#    #+#             */
/*   Updated: 2026/01/19 17:37:25 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_drawing.h"
#include "modules/mbx_utils.h"

void	mbx_refresh_settings(t_mbx *mbx)
{
	if (mbx->settings.fps_cap <= 0)
		mlx_set_fps_goal(mbx->mlx, INT_MAX);
	else
		mlx_set_fps_goal(mbx->mlx,
			mbx->settings.fps_cap * MBX_MLX_FPS_CAP_RATIO);
	if (mbx->settings.show_cursor)
		mlx_mouse_show(mbx->mlx);
	else
		mlx_mouse_hide(mbx->mlx);
}

void	mbx_reset_settings(t_mbx *mbx)
{
	mbx->settings.viewport_render
		= (t_mbx_viewport_render)MBX_DEFAULT_VIEWPORT_RENDER;
	mbx->settings.background_color = color(MBX_DEFAULT_BACKGROUND_COLOR);
	mbx->settings.fps_cap = MBX_DEFAULT_FPS_CAP;
	mbx->settings.default_color_getter = &mbx_color_getter_ignore;
	mbx->settings.default_color_setter = &mbx_color_setter_ignore;
	mbx->settings.default_color_modifier_data = mbx;
	mbx->settings.exit_key = MBX_DEFAULT_EXIT_KEY;
	mbx->settings.fullscreen_toggle_key = MBX_DEFAULT_FULLSCREEN_TOGGLE_KEY;
	mbx->settings.do_window_cross_exit = MBX_DEFAULT_DO_WINDOW_CROSS_EXIT;
	mbx->settings.lock_cursor = MBX_DEFAULT_LOCK_CURSOR;
	mbx->settings.show_cursor = MBX_DEFAULT_SHOW_CURSOR;
	mbx_refresh_settings(mbx);
}
