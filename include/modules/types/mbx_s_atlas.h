/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_font.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:45:46 by rprieur           #+#    #+#             */
/*   Updated: 2026/02/08 08:54:24 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../../lib/VecLibC/include/veclc.h"
#include "mbx_s_region.h"

/**
 * Struct representing a MacroBoX region atlas.
 *
 * @region		the atlas's reference texture.
 * @glyph_size	the size of a region within the atlas in pixels.
 *
 * This struct must be destroyed manually using mbx_destroy_region_set().
 */
typedef struct s_mbx_region_atlas
{
	t_mbx_region	atlas;
	t_vec2i			region_size;
}	t_mbx_atlas;
