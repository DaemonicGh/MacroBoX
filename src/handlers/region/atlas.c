/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atlas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:37:59 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_structs.h"

t_mbx_atlas	*mbx_atlas(t_mbx_region *region, t_vec2i subregion_size)
{
	if (!region)
		return (NULL);
	region->subregion_size = subregion_size;
	return (region);
}

bool
	mbx_is_atlas(t_mbx_region *region)
{
	return (region->subregion_size.x != 0 && region->subregion_size.y != 0);
}
