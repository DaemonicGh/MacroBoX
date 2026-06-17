/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:52:30 by daemo             #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_constants.h"
#include "modules/mbx_drawing.h"
#include "modules/mbx_handlers.h"
#include "modules/mbx_inputs.h"
#include "../../_private/mbx_internal.h"

void	mbx_start_frame(t_mbx *mbx)
{
	refresh_deltatime(mbx);
	refresh_cursor(mbx);
	mlx_clear_window(mbx->mlx, mbx->window.mlx,
		mbx->settings.background_color);
}

static void	update_allocs_lifetime(t_mbx *mbx)
{
	const uint32_t	pre_allocs = mbx->allocator.alloc_count;
	uint32_t		i;

	mbx_free_groups(mbx, MBX_ALLOC_FREE_THIS_FRAME, MBX_ALLOC_EMPTY);
	if (pre_allocs < mbx->allocator.alloc_count)
		mbx_report_nbr(mbx, "Freed ", mbx->allocator.alloc_count - pre_allocs,
			" allocations this frame");
	i = 0;
	while (i < mbx->allocator.capacity)
	{
		if (mbx->allocator.allocs[i].flags & MBX_ALLOC_FREE_NEXT_FRAME)
		{
			mbx->allocator.allocs[i].flags &= ~MBX_ALLOC_FREE_NEXT_FRAME;
			mbx->allocator.allocs[i].flags |= MBX_ALLOC_FREE_THIS_FRAME;
		}
		i++;
	}
}

void	mbx_end_frame(t_mbx *mbx)
{
	mbx_render_region_as_viewport(mbx,
		mbx->viewport, mbx->settings.viewport_render);
	update_allocs_lifetime(mbx);
	mbx_flush_inputs(mbx);
	update_time_values(mbx);
}
