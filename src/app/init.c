/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:20:24 by daemo             #+#    #+#             */
/*   Updated: 2026/02/05 04:34:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "veclc.h"
#include "modules/mbx_handlers.h"
#include "modules/mbx_math.h"
#include "../_private/mbx_internal.h"

static void	init_time(t_mbx *mbx)
{
	double	time;

	time = get_sec_since_epoch();
	mbx->timestamps.app_start = time;
	mbx->timestamps.frame_start = time;
	mbx->delta_time = 1.0 / mbx->settings.fps_cap;
	mbx->seconds_per_frame = 0;
	mbx->frames_elapsed = 0;
}

bool	mbx_make_main_window(t_mbx *mbx, t_vec2i viewport_size,
	char *win_title, unsigned int win_flags)
{
	mbx->screen_size = get_screen_size_windowless(mbx);
	if (!mbx->screen_size.x || !mbx->screen_size.y)
		return (false);
	vec2i_mult_to_d(&mbx->screen_size, MBX_INIT_MAX_WINDOW_COVERAGE_RATIO);
	vec2i_div_to(&mbx->screen_size, viewport_size);
	mbx->window = mbx_make_window(mbx, vec2i_mult_i(viewport_size,
				max(min(mbx->screen_size.x, mbx->screen_size.y), 1)),
			win_title, win_flags);
	if (!mbx->window.mlx)
		return (false);
	mlx_set_window_min_size(mbx->mlx,
		mbx->window.mlx, viewport_size.x, viewport_size.y);
	mbx->viewport = mbx_make_region_with_image(mbx, viewport_size);
	if (!mbx->viewport.canvas)
	{
		mlx_destroy_window(mbx->mlx, mbx->window.mlx);
		return (false);
	}
	mbx_start_events(mbx);
	return (true);
}

t_mbx	*mbx_init_windowless(void)
{
	t_mbx	*mbx;

	mbx = malloc(sizeof(t_mbx));
	if (!mbx)
		return (NULL);
	mbx->mlx = mlx_init();
	if (!mbx->mlx)
	{
		free(mbx);
		return (NULL);
	}
	mbx_reset_settings(mbx);
	reset_inputs(mbx);
	init_time(mbx);
	return (mbx);
}

t_mbx	*mbx_init(t_vec2i viewport_size, char *win_title, unsigned int flags)
{
	t_mbx	*mbx;

	mbx = mbx_init_windowless();
	if (!mbx)
		return (NULL);
	if (!mbx_make_main_window(mbx, viewport_size, win_title, flags))
	{
		mlx_destroy_context(mbx->mlx);
		free(mbx);
		return (NULL);
	}
	return (mbx);
}
