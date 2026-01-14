/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:28:29 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:39:48 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/modules/types/mbx_s_mbx.h"
#include "../includes/modules/consts/mbx_c_other.h"

void	mbx_reset_settings(t_mbx *mbx)
{
	mbx->settings.background_color = color(MBX_BASE_BACKGROUND_COLOR);
	mbx->settings.fps_cap = 60;
}

void	mbx_refresh_settings(t_mbx *mbx)
{
	mlx_set_fps_goal(mbx->mlx, mbx->settings.fps_cap);
}
