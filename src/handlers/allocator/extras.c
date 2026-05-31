/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 19:56:32 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "modules/mbx_constants.h"
#include "modules/mbx_handlers.h"
#include "../../_private/mbx_internal.h"

bool	create_allocator(t_mbx *mbx)
{
	uint32_t	i;

	mbx->allocator.allocs = malloc(
			sizeof(t_mbx_alloc) * MBX_ALLOCATOR_INIT_SIZE);
	if (!mbx->allocator.allocs)
		return (false);
	mbx->allocator.capacity = MBX_ALLOCATOR_INIT_SIZE;
	i = 0;
	while (i < MBX_ALLOCATOR_INIT_SIZE)
		mbx->allocator.allocs[i++] = (t_mbx_alloc){0};
	i = 0;
	while (i < MBX_ALLOCATOR_CACHE_SIZE)
		mbx->allocator.cache[i++] = -1;
	return (true);
}

t_mbx_alloc	*mbx_get_alloc(t_mbx *mbx, void *ptr)
{
	uint32_t	i;

	if (!ptr)
		return (NULL);
	i = 0;
	while (i < mbx->allocator.capacity)
	{
		if (mbx->allocator.allocs[i].ptr == ptr)
			return (&mbx->allocator.allocs[i]);
		i++;
	}
	return (NULL);
}

bool	mbx_change_alloc_flags(t_mbx *mbx, void *ptr,
	t_mbx_alloc_flags add, t_mbx_alloc_flags remove)
{
	uint32_t	i;

	if (!ptr)
		return (false);
	i = 0;
	while (i < mbx->allocator.capacity)
	{
		if (mbx->allocator.allocs[i].ptr == ptr)
		{
			mbx->allocator.allocs[i].flags &= ~remove;
			mbx->allocator.allocs[i].flags |= add;
			return (true);
		}
		i++;
	}
	return (false);
}

void	destroy_allocator(t_mbx *mbx)
{
	uint32_t	i;

	i = 0;
	while (i < mbx->allocator.capacity)
	{
		if (mbx->allocator.allocs[i].ptr)
			free_alloc(mbx, mbx->allocator.allocs[i]);
		i++;
	}
	free(mbx->allocator.allocs);
}
