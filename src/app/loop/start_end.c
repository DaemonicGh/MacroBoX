/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:52:30 by daemo             #+#    #+#             */
/*   Updated: 2026/01/24 00:09:16 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "modules/mbx_drawing.h"
#include "modules/mbx_inputs.h"
#include "modules/mbx_handlers.h"
#include "../../_private/mbx_internal.h"

void	mbx_start_frame(t_mbx *mbx)
{
	refresh_deltatime(mbx);
	refresh_cursor(mbx);
	mlx_clear_window(mbx->mlx, mbx->window.mlx, mbx->settings.background_color);
}

void	mbx_end_frame(t_mbx *mbx)
{
	if (mbx->settings.viewport_render != MBX_VIEWPORT_RENDER_SKIP)
		mbx_render_region_as_viewport(mbx, &mbx->viewport);
	mbx_flush_inputs(mbx);
	mbx_refresh_settings(mbx);
	update_time_values(mbx);
}
