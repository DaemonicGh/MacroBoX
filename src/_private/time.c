/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 00:46:09 by rprieur           #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/mbx_s_mbx.h"
#include "modules/mbx_utils.h"

bool	should_skip_frame(t_mbx *mbx)
{
	double	time;

	time = mbx_get_timestamp();
	if (time == -1)
		return (false);
	if (time < mbx->now
		+ MBX_FRAME_SKIP_MARGIN_RATIO / mbx->settings.fps_cap)
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
