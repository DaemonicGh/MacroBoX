/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:20:24 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/27 22:47:22 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mbx.h"

#include <stdio.h>

static void	reset_inputs(t_mbxcontext *mbx)
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

static int	make_window(t_mbxcontext *mbx, t_vec2i viewport_size,
	char *win_title, int win_mode)
{
	mlx_window	temp_win;
	t_vec2i		size;

	temp_win = mlx_new_window(mbx->mlx, &(mlx_window_create_info){
			.render_target = NULL, .width = 0, .height = 0, .title = "",
			.is_resizable = false, .is_fullscreen = false});
	if (!temp_win)
		return (0);
	mlx_get_screen_size(mbx->mlx, temp_win, &size.x, &size.y);
	mlx_destroy_window(mbx->mlx, temp_win);
	size = vec2i_div(vec2i_div_i(size, 2), viewport_size);
	mbx->window = mbx_make_window(mbx,
			vec2i_mult_i(viewport_size, max(min(size.x, size.y), 1)),
			win_title, win_mode);
	if (!mbx->window.win)
		return (0);
	mbx->viewport = mbx_make_window_target(mbx,
			mbx_make_image(mbx, viewport_size.x, viewport_size.y));
	if (!mbx->viewport.win)
	{
		mlx_destroy_window(mbx->mlx, mbx->window.win);
		return (0);
	}
	return (1);
}

t_mbxcontext	*mbx_init(t_vec2i viewport_size, char *win_title, int win_mode)
{
	t_mbxcontext	*mbx;

	mbx = malloc(sizeof(t_mbxcontext));
	if (!mbx)
		return (NULL);
	mbx->mlx = mlx_init();
	if (!mbx->mlx)
		return (NULL);
	if (!make_window(mbx, viewport_size, win_title, win_mode))
		return (NULL);
	reset_inputs(mbx);
	mbx_reset_settings(mbx);
	mbx_start_events(mbx);
	mbx->time.frames_elapsed = 0;
	mbx->time.delta = 1.0 / mbx->settings.fps_cap;
	gettimeofday(&mbx->time.frame_start, NULL);
	return (mbx);
}
