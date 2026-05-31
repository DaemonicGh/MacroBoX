/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 22:19:33 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_constants.h"
#include "modules/mbx_handlers.h"
#include "modules/mbx_utils.h"
#include "../../_private/mbx_internal.h"

static void	set_window_attributes(t_mbx *mbx, t_vec2i viewport_size)
{
	t_vec2i	scale;

	mbx_change_alloc_flags(mbx, mbx->window.mlx,
		MBX_ALLOC_FREE_ON_RUN_END, MBX_ALLOC_EMPTY);
	scale = vec2i_div(vec2i_mult_d(mbx->window.screen_size,
				MBX_INIT_MAX_WINDOW_COVERAGE_RATIO), viewport_size);
	mbx->window.size = vec2i_mult_d(viewport_size,
			max(min(scale.x, scale.y), 1));
	mbx->window.pos = vec2i_div_d(vec2i_sub(
				mbx->window.screen_size, mbx->window.size), 2);
	mlx_set_window_size(mbx->mlx, mbx->window.mlx,
		mbx->window.size.x, mbx->window.size.y);
	mlx_set_window_position(mbx->mlx, mbx->window.mlx,
		mbx->window.pos.x, mbx->window.pos.y);
}

static bool	create_viewport(t_mbx *mbx, t_vec2i viewport_size)
{
	mbx->viewport = mbx_create_region_with_image(mbx, viewport_size);
	if (!mbx->viewport)
	{
		mbx_destroy_window(mbx, &mbx->window);
		return (false);
	}
	mbx_change_alloc_flags(mbx, mbx->viewport,
		MBX_ALLOC_FREE_ON_RUN_END, MBX_ALLOC_EMPTY);
	mbx_change_alloc_flags(mbx, mbx->viewport->image,
		MBX_ALLOC_FREE_ON_RUN_END, MBX_ALLOC_EMPTY);
	return (true);
}

bool	mbx_create_main_window(t_mbx *mbx, t_vec2i viewport_size,
	char *win_title, unsigned int win_flags)
{
	mbx->window = mbx_create_window(mbx, vec2i_zero(), win_title, win_flags);
	if (!mbx->window.mlx)
		return (false);
	set_window_attributes(mbx, viewport_size);
	if (!create_viewport(mbx, viewport_size))
		return (false);
	mbx_start_events(mbx);
	mbx_report(mbx, "Successfully initialized main window");
	return (true);
}
