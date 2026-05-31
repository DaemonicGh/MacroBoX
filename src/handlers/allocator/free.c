/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:00:20 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "modules/mbx_handlers.h"
#include "../../_private/mbx_internal.h"

static void	reset_alloc(t_mbx *mbx, uint32_t index)
{
	uint32_t	i;

	mbx->allocator.allocs[index] = (t_mbx_alloc){0};
	mbx->allocator.alloc_count--;
	mbx_report_mem(mbx, "Clearing memory block #", index);
	i = 0;
	while (i < MBX_ALLOCATOR_CACHE_SIZE)
	{
		if (mbx->allocator.cache[i] == -1u)
		{
			mbx->allocator.cache[i] = index;
			return ;
		}
		i++;
	}
}

void	free_alloc(t_mbx *mbx, t_mbx_alloc ptr)
{
	const uint8_t		type = ptr.flags & MBX_ALLOC_TYPE_MASK;

	if (type == MBX_ALLOC_TYPE_MLX_IMAGE)
		mlx_destroy_image(mbx->mlx, ptr.ptr);
	else if (type == MBX_ALLOC_TYPE_MLX_WINDOW)
		mlx_destroy_window(mbx->mlx, ptr.ptr);
	else
		free(ptr.ptr);
}

bool	mbx_free(t_mbx *mbx, void *ptr)
{
	uint32_t	i;

	if (!ptr)
		return (false);
	i = 0;
	while (i < mbx->allocator.capacity)
	{
		if (mbx->allocator.allocs[i].ptr == ptr)
		{
			free_alloc(mbx, mbx->allocator.allocs[i]);
			reset_alloc(mbx, i);
			return (true);
		}
		i++;
	}
	return (false);
}

void	mbx_free_groups(
	t_mbx *mbx, t_mbx_alloc_flags whitelist, t_mbx_alloc_flags blacklist)
{
	uint32_t	i;

	i = 0;
	while (i < mbx->allocator.capacity)
	{
		if (mbx->allocator.allocs[i].ptr
			&& mbx->allocator.allocs[i].flags & whitelist
			&& mbx->allocator.allocs[i].flags & ~blacklist)
		{
			free_alloc(mbx, mbx->allocator.allocs[i]);
			reset_alloc(mbx, i);
		}
		i++;
	}
}
