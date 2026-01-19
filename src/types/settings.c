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

#include "../../includes/modules/types/mbx_s_mbx.h"
#include "../../includes/modules/consts/mbx_c_other.h"

void	mbx_refresh_settings(t_mbx *mbx)
{
	mlx_set_fps_goal(mbx->mlx, mbx->settings.fps_cap);
}

void	mbx_reset_settings(t_mbx *mbx)
{
	mbx->settings.background_color = color(MBX_BASE_BACKGROUND_COLOR);
	mbx->settings.fps_cap = MBX_BASE_FPS_CAP;
	mbx->settings.do_window_cross_exit = MBX_BASE_DO_WINDOW_CROSS_EXIT;
	mbx->settings.exit_key = MBX_BASE_EXIT_KEY;
	mbx->settings.fullscreen_toggle_key = MBX_BASE_FULLSCREEN_TOGGLE_KEY;
	mbx_refresh_settings(mbx);
}
