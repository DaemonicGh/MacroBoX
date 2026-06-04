/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:28:29 by daemo             #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_constants.h"
#include "modules/mbx_handlers.h"
#include "modules/mbx_drawing.h"

int	mbx_get_fps_cap(t_mbx *mbx)
{
	if (!mbx->window.mlx)
		return (mbx->settings.fps_cap);
	else if (mbx->window.is_minimized)
		return (mbx->settings.fps_cap_minimized);
	else if (!mbx->window.is_focused)
		return (mbx->settings.fps_cap_unfocused);
	else
		return (mbx->settings.fps_cap);
}

void	refresh_mlx_fps_cap(t_mbx *mbx)
{
	int	goal;

	if (!mbx->window.mlx)
		goal = mbx->settings.fps_cap * MBX_MLX_FPS_CAP_RATIO;
	else if (mbx->window.is_minimized)
		goal = mbx->settings.fps_cap_minimized;
	else if (!mbx->window.is_focused)
		goal = mbx->settings.fps_cap_unfocused;
	else
		goal = mbx->settings.fps_cap * MBX_MLX_FPS_CAP_RATIO;
	if (goal <= 0)
		goal = INT_MAX;
	mlx_set_fps_goal(mbx->mlx, goal);
}

void	mbx_refresh_settings(t_mbx *mbx)
{
	refresh_mlx_fps_cap(mbx);
	if (!mbx->settings.hide_cursor)
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
	mbx->settings.fps_cap_minimized = MBX_DEFAULT_FPS_CAP_MINIMIZED;
	mbx->settings.fps_cap_unfocused = MBX_DEFAULT_FPS_CAP_UNFOCUSED;
	mbx->settings.default_pipeline.get = &mbx_default_pipeline_get;
	mbx->settings.default_pipeline.blend = &mbx_default_pipeline_blend;
	mbx->settings.default_pipeline.set = &mbx_default_pipeline_set;
	mbx->settings.default_pipeline.data = mbx;
	mbx->settings.default_alloc_flags
		= (t_mbx_alloc_flags)MBX_DEFAULT_ALLOC_FLAGS;
	mbx->settings.exit_key = MBX_DEFAULT_EXIT_KEY;
	mbx->settings.fullscreen_toggle_key = MBX_DEFAULT_FULLSCREEN_TOGGLE_KEY;
	mbx->settings.do_window_cross_exit = MBX_DEFAULT_DO_WINDOW_CROSS_EXIT;
	mbx->settings.lock_cursor = MBX_DEFAULT_LOCK_CURSOR;
	mbx->settings.hide_cursor = MBX_DEFAULT_HIDE_CURSOR;
	mbx->settings.use_azerty = MBX_DEFAULT_USE_AZERTY;
	mbx_refresh_settings(mbx);
}
