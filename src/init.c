/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:20:24 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/21 19:12:44 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mbx.h"

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

t_mbxcontext	*mbx_init(t_vec2i win_size, char *win_title, int win_mode)
{
	t_mbxcontext	*mbx;

	mbx = malloc(sizeof(t_mbxcontext));
	mbx->mlx = mlx_init();
	mbx->window = mbx_make_window(mbx, win_size, win_title, win_mode);
	mbx->viewport = mbx_make_window_target(mbx,
			mbx_make_image(mbx, win_size.x, win_size.y));
	reset_inputs(mbx);
	mbx_start_events(mbx);
	mbx->time.frames_elapsed = 0;
	mbx->time.delta = 0.05;
	gettimeofday(&mbx->time.frame_start, NULL);
	return (mbx);
}
