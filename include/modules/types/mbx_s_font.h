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
 * Struct representing a MacroBoX font.
 *
 * @region		the font's reference texture atlas.
 * @glyph_size	the font's glyph size in pixels.
 * @grid_size	the amount of rows and columns in the font's texture atlas.
 * @color		the font's color.
 *
 * This struct must be destroyed manually using mbx_destroy_font().
 */
typedef struct s_mbxfont
{
	t_mbxregion	region;
	t_vec2i		glyph_size;
	t_vec2i		grid_size;
	t_mbxcolor	color;
}	t_mbxfont;
