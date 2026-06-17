/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:26:53 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_core.h"
#include "modules/mbx_utils.h"
#include "../../_private/mbx_internal.h"

static void	set_alloc(
	t_mbx *mbx, uint32_t index, void *ptr, t_mbx_alloc_flags flags)
{
	static uint32_t	id = 0;

	id++;
	mbx->allocator.allocs[index] = (t_mbx_alloc){
		.ptr = ptr,
		.id = id,
		.flags = flags
	};
	mbx->allocator.alloc_count++;
	mbx_report_mem(mbx, "Assigning to memory block #", index);
}

static bool	append_alloc(
	t_mbx *mbx, void *ptr, t_mbx_alloc_flags flags, uint32_t new_capacity)
{
	t_mbx_alloc		*new_allocs;
	uint32_t		i;

	new_allocs = malloc(sizeof(t_mbx_alloc) * new_capacity);
	if (!new_allocs)
	{
		mbx_report(mbx, "Failed allocation assignement");
		return (false);
	}
	i = 0;
	while (i < mbx->allocator.capacity)
	{
		new_allocs[i] = mbx->allocator.allocs[i];
		i++;
	}
	free(mbx->allocator.allocs);
	mbx->allocator.allocs = new_allocs;
	set_alloc(mbx, i++, ptr, flags);
	while (i < new_capacity)
		new_allocs[i++] = (t_mbx_alloc){0};
	i = min(MBX_ALLOCATOR_CACHE_SIZE, mbx->allocator.capacity - 1);
	while (--i)
		mbx->allocator.cache[i] = new_capacity - i - 1;
	mbx->allocator.capacity = new_capacity;
	return (true);
}

bool	mbx_add_alloc(t_mbx *mbx, void *ptr, t_mbx_alloc_flags flags)
{
	uint32_t	i;

	i = 0;
	while (i < MBX_ALLOCATOR_CACHE_SIZE)
	{
		if (mbx->allocator.cache[i] != -1u)
		{
			set_alloc(mbx, mbx->allocator.cache[i], ptr, flags);
			mbx->allocator.cache[i] = -1;
			return (true);
		}
		i++;
	}
	i = 0;
	while (i < mbx->allocator.capacity)
	{
		if (!mbx->allocator.allocs[i].ptr)
		{
			set_alloc(mbx, i, ptr, flags);
			return (true);
		}
		i++;
	}
	return (append_alloc(mbx, ptr, flags, mbx->allocator.capacity * 2));
}

void	*mbx_alloc_flags(t_mbx *mbx, size_t alloc_size, t_mbx_alloc_flags flags)
{
	void	*ptr;

	ptr = malloc(alloc_size);
	if (!ptr)
	{
		mbx_report(mbx, "Failed allocation");
		return (NULL);
	}
	if (!mbx_add_alloc(mbx, ptr, flags))
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}

void	*mbx_alloc(t_mbx *mbx, size_t alloc_size)
{
	return (mbx_alloc_flags(
			mbx, alloc_size, mbx->settings.default_alloc_flags));
}
