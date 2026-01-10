/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:20:24 by daemo             #+#    #+#             */
/*   Updated: 2026/01/10 01:58:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mbx.h"
#include "../includes/mbx_internal.h"

static void	reset_inputs(t_mbx *mbx)
{
	int	i;

	mlx_mouse_get_pos(mbx->mlx, &mbx->inputs.mouse.x, &mbx->inputs.mouse.x);
	mbx->inputs.prev_mouse = mbx->inputs.mouse;
	i = 0;
	while (i < MBX_INPUT_ARRAY_LENGTH)
		mbx->inputs.btn[i++] = false;
	mbx_flush_inputs(mbx);
	mbx->inputs.last_key = 0;
	mbx->inputs.should_exit = false;
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
	size = vec2i_div(vec2i_div_i(size, 2), viewport_size);
	mbx->window = mbx_make_window(mbx,
			vec2i_mult_i(viewport_size, max(min(size.x, size.y), 1)),
			win_title, win_mode);
	if (!mbx->window.win)
		return (-1);
	mbx->viewport = mbx_make_region(viewport_size);
	if (!mbx->viewport.canvas)
	{
		mlx_destroy_window(mbx->mlx, mbx->window.win);
		return (-1);
	}
	return (1);
}

static void	init_time(t_mbx *mbx)
{
	mbx->time.sec_per_frame = 0;
	mbx->time.frames_elapsed = 0;
	mbx->time.delta = 1.0 / mbx->settings.fps_cap;
	mbx->time.frame_start = get_sec_since_epoch();
}

t_mbx	*mbx_init(t_vec2i viewport_size, char *win_title, int win_mode)
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
	if (make_window(mbx, viewport_size, win_title, win_mode) == -1)
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
