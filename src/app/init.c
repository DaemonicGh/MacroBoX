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
#include "modules/veclc_vec2i.h"
#include "modules/consts/mbx_c_other.h"
#include "modules/mbx_inputs.h"
#include "modules/mbx_math.h"
#include "modules/mbx_region.h"
#include "modules/mbx_settings.h"
#include "modules/mbx_window.h"
#include "modules/mbx_mlx_ext.h"
#include "../headers/mbx_internal.h"

static void	reset_inputs(t_mbx *mbx)
{
	t_vec2i	new_mouse;
	int		i;

	mlx_mouse_get_pos(mbx->mlx, &new_mouse.x, &new_mouse.y);
	mbx->inputs.mouse_delta = vec2i_sub(new_mouse, mbx->inputs.mouse);
	i = 0;
	while (i < MBX_INPUT_ARRAY_LENGTH)
		mbx->inputs.btn[i++] = false;
	mbx_flush_inputs(mbx);
	mbx->inputs.last_key = 0;
	mbx->should_exit = false;
}

static int	make_window(t_mbx *mbx, t_vec2i viewport_size,
	char *win_title, int win_mode)
{
	mlx_window	temp_win;
	t_vec2i		size;

	temp_win = mlx_new_window(mbx->mlx,
			&(mlx_window_create_info){.title = "", 0});
	if (!temp_win)
		return (-1);
	mlx_get_screen_size(mbx->mlx, temp_win, &size.x, &size.y);
	mlx_destroy_window(mbx->mlx, temp_win);
	size.x = size.x * MBX_INIT_MAX_WINDOW_COVERAGE_RATIO / viewport_size.x;
	size.y = size.y * MBX_INIT_MAX_WINDOW_COVERAGE_RATIO / viewport_size.y;
	mbx->window = mbx_make_window(mbx,
			vec2i_mult_i(viewport_size, max(min(size.x, size.y), 1)),
			win_title, win_mode);
	if (!mbx->window.win)
		return (-1);
	mlx_set_window_min_size(mbx->mlx,
		mbx->window.win, viewport_size.x, viewport_size.y);
	mbx->viewport = mbx_make_region_with_image(mbx, viewport_size);
	if (!mbx->viewport.canvas)
	{
		mlx_destroy_window(mbx->mlx, mbx->window.win);
		return (-1);
	}
	return (1);
}

static void	init_time(t_mbx *mbx)
{
	double	time;

	time = get_sec_since_epoch();
	mbx->time.app_start = time;
	mbx->time.frame_start = time;
	mbx->time.sec_per_frame = 0;
	mbx->time.frames_elapsed = 0;
	mbx->time.delta = 1.0 / mbx->settings.fps_cap;
}

t_mbx	*mbx_init(t_vec2i viewport_size, char *win_title, unsigned int flags)
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
	if (make_window(mbx, viewport_size, win_title, flags) == -1)
	{
		mlx_destroy_context(mbx->mlx);
		free(mbx);
		return (NULL);
	}
	reset_inputs(mbx);
	mbx_reset_settings(mbx);
	mbx_start_events(mbx);
	init_time(mbx);
	return (mbx);
}
