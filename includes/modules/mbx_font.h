/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_font.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:27:39 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 13:15:17 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_FONT_H
# define MBX_FONT_H

# include "types/mbx_s_mbx.h"

/**
 * Creates and returns a font.
 *
 * @region	the source image atlas of the font.
 * @glyph_size	the size of a glyph	in pixels.
 * @col		the base color of the font.
 *
 * MacroBoX currently only supports monospace fonts,
 * make sure that the image's glyphs are white for color to work properly.
 */
t_mbxfont		mbx_make_font(t_mbxregion region,
					t_vec2i glyph_size, t_mbxcolor col);

/**
 * Creates and returns a font from a file.
 *
 * @mbx	the macrobox instance
 * @path	the path to the font file containing the image atlas.
 * @glyph_size	the size of a glyph	in pixels.
 * @col		the base color of the font.
 *
 * MacroBoX currently only supports monospace fonts,
 * make sure that the image's glyphs are white for color to work properly.
 */
t_mbxfont		mbx_make_font_from_file(t_mbx *mbx,
					char *path, t_vec2i glyph_size, t_mbxcolor col);

/**
 * Destroys and frees the content of the given font.
 *
 * @mbx		the MacrBoX context.
 * @font	the font to destroy.
 */
void			mbx_destroy_font(t_mbx *mbx, t_mbxfont *font);

#endif
