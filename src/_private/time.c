/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 00:46:09 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/09 01:55:08 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

#include "modules/types/mbx_s_mbx.h"

double	get_sec_since_epoch(void)
{
	struct timeval	time;

	if (gettimeofday(&time, 0) == -1)
		return (-1);
	return ((double)time.tv_sec + (double)time.tv_usec / 1000000.0);
}

bool	should_skip_frame(t_mbx *mbx)
{
	double	time;

	time = get_sec_since_epoch();
	if (time == -1)
		return (false);
	if (time < mbx->timestamps.frame_start
		+ MBX_FRAME_SKIP_MARGIN_RATIO / mbx->settings.fps_cap)
		return (true);
	return (false);
}

void	update_time_values(t_mbx *mbx)
{
	double	time;

	time = get_sec_since_epoch();
	if (time != -1)
		mbx->seconds_per_frame = time - mbx->timestamps.frame_start;
	mbx->frames_elapsed++;
}

void	refresh_deltatime(t_mbx *mbx)
{
	double	time;

	time = get_sec_since_epoch();
	if (time == -1)
		return ;
	mbx->delta_time = time - mbx->timestamps.frame_start;
	mbx->timestamps.frame_start = time;
}
