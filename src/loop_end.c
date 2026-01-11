/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:52:50 by daemo             #+#    #+#             */
/*   Updated: 2026/01/10 13:39:16 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mbx.h"
#include "../includes/mbx_internal.h"

static void	update_time_stuff(t_mbx *mbx)
{
	double	time;

	time = get_sec_since_epoch();
	if (time != -1)
		mbx->time.sec_per_frame = time - mbx->time.frame_start;
	mbx->time.frames_elapsed++;
}

void	mbx_end_frame(t_mbx *mbx)
{
	draw_viewport(mbx);
	mbx_flush_inputs(mbx);
	mbx_refresh_settings(mbx);
	update_time_stuff(mbx);
}
