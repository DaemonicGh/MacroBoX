/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 00:46:09 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:53 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_utils.h"
#include "modules/mbx_handlers.h"

bool	should_skip_frame(t_mbx *mbx)
{
	double	time;

	time = mbx_get_timestamp();
	if (time == -1)
		return (false);
	if (time < mbx->now
		+ MBX_FRAME_SKIP_MARGIN_RATIO / mbx_get_fps_cap(mbx))
	{
		return (true);
	}
	return (false);
}

void	update_time_values(t_mbx *mbx)
{
	double	time;

	time = mbx_get_timestamp();
	if (time != -1)
		mbx->seconds_per_frame = time - mbx->now;
	mbx->frames_elapsed++;
}

void	refresh_deltatime(t_mbx *mbx)
{
	double	time;

	time = mbx_get_timestamp();
	if (time == -1)
		return ;
	mbx->delta_time = time - mbx->now;
	mbx->now = time;
}
