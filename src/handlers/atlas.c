/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atlas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:02:20 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 15:15:50 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_handlers.h"

t_mbx_atlas	mbx_make_atlas(t_mbx_region atlas, t_vec2i region_size)
{
	return ((t_mbx_atlas){.atlas = atlas, .region_size = region_size});
}

void	mbx_destroy_atlas(t_mbx *mbx, t_mbx_atlas *atlas)
{
	mbx_destroy_region(mbx, &atlas->atlas);
	*atlas = (t_mbx_atlas){0};
}
