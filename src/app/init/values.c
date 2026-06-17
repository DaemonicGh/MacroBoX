/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 22:19:40 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_utils.h"
#include "modules/mbx_handlers.h"
#include "../../_private/mbx_internal.h"

static void	init_time(t_mbx *mbx)
{
	double	time;

	time = mbx_get_timestamp();
	mbx->app_timestamp = time;
	mbx->now = time;
	mbx->delta_time = 1.0 / mbx->settings.fps_cap;
	mbx->seconds_per_frame = 0;
	mbx->frames_elapsed = 0;
}

static bool	init_assets(t_mbx *mbx)
{
	mbx->assets.font_small = mbx_atlas(mbx_create_region_from_file(
				mbx, MBX_ROOT "assets/font_5x7.png"), vec2i(5, 7));
	if (!mbx->assets.font_small)
		return (false);
	mbx->assets.font_large = mbx_atlas(mbx_create_region_from_file(
				mbx, MBX_ROOT "assets/font_12x16.png"), vec2i(12, 16));
	if (!mbx->assets.font_large)
		return (false);
	mbx->assets.placeholder = mbx_create_region_from_file(
			mbx, MBX_ROOT "assets/42.png");
	if (!mbx->assets.placeholder)
		return (false);
	return (true);
}

bool	init_values(t_mbx *mbx)
{
	if (!create_allocator(mbx))
		return (false);
	init_time(mbx);
	if (!init_assets(mbx))
	{
		destroy_allocator(mbx);
		return (false);
	}
	return (true);
}
