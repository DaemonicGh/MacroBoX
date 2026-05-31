/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 22:19:40 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_utils.h"
#include "../../_private/mbx_internal.h"

static void	init_time(t_mbx *mbx)
{
	double	time;

	time = mbx_get_timestamp();
	mbx->app_timestamp = time;
	mbx->now = time;
	mbx->delta_time = 1.0 / mbx->settings.fps_cap;
	mbx->seconds_per_frame = 0;
	mbx->frames_elapsed = 0;
}

void	init_values(t_mbx *mbx)
{
	create_allocator(mbx);
	init_time(mbx);
}
