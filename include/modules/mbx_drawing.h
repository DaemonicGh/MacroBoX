/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_drawing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:32:17 by rprieur           #+#    #+#             */
/*   Updated: 2026/02/08 08:54:24 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../lib/VecLibC/include/veclc.h"
#include "types/mbx_s_mbx.h"

/**
 * Clears the given region with the given color.
 *
 * @region	the region to query.
 * @col	the color to clear the region with.
 */
void		mbx_clear(t_mbxregion *region, t_mbxcolor col);

/**
 * Returns the color of a pixel on a region at the given position.
 *
 * @region	the region to query.
 * @pos		the position of the pixel.
 */
t_mbxcolor	mbx_get_pixel(t_mbxregion *region, t_vec2i pos);

/**
 * Returns the color of a pixel on a region at the given position.
 *
 * @region	the region to query.
 * @pos		the position of the pixel.
 *
 * This version does not perform bounds checking.
 */
t_mbxcolor	mbx_get_pixel_unsafe(t_mbxregion *region, t_vec2i pos);

/**
 * Returns the color of a pixel on a region at the given position.
 *
 * @region	the region to query.
 * @x	the x-coordinate of the pixel.
 * @y	the y-coordinate of the pixel.
 */
t_mbxcolor	mbx_get_pixel_xy(t_mbxregion *region, int x, int y);

/**
 * Returns the color of a pixel on a region at the given position.
 *
 * @region	the region to query.
 * @x	the x-coordinate of the pixel.
 * @y	the y-coordinate of the pixel.
 *
 * This version does not perform bounds checking.
 */
t_mbxcolor	mbx_get_pixel_unsafe_xy(t_mbxregion *region, int x, int y);

/**
 * Sets the color of a pixel on a region at the given position.
 *
 * @region	the region to draw on.
 * @pos	the position of the pixel.
 * @col	the color of the pixel.
 *
 * It will be blended with the current pixel color if the color is not opaque.
 */
void		mbx_set_pixel(t_mbxregion *region, t_vec2i pos, t_mbxcolor col);

/**
 * Sets the color of a pixel on a region at the given position.
 *
 * @region	the region to draw on.
 * @x	the x-coordinate of the pixel.
 * @y	the y-coordinate of the pixel.
 * @col	the color of the pixel.
 *
 * It will be blended with the current pixel color if the color is not opaque.
 */
void		mbx_set_pixel_xy(t_mbxregion *region, int x, int y, t_mbxcolor col);

/**
 * Sets the color of a pixel on a region at the given position.
 *
 * @region	the region to draw on.
 * @x	the x-coordinate of the pixel.
 * @y	the y-coordinate of the pixel.
 * @col	the color of the pixel.
 *
 * This version does not perform bounds checking.
 * Color blending is still performed.
 */
void		mbx_set_pixel_unsafe(t_mbxregion *region,
				t_vec2i pos, t_mbxcolor col);

/**
 * Sets the color of a pixel on a region at the given position.
 *
 * @region	the region to draw on.
 * @x	the x-coordinate of the pixel.
 * @y	the y-coordinate of the pixel.
 * @col	the color of the pixel.
 *
 * This version does not perform bounds checking.
 * Color blending is still performed.
 */
void		mbx_set_pixel_unsafe_xy(t_mbxregion *region,
				int x, int y, t_mbxcolor col);

/**
 * Sets the color of a pixel on a region at the given index.
 *
 * @region	the region to draw on.
 * @i	the index of the pixel.
 * @col	the color of the pixel.
 *
 * This version does not perform bounds checking.
 * Color blending is still performed.
 */
void		mbx_set_pixel_unsafe_i(t_mbxregion *region, int i, t_mbxcolor col);

/**
* Sets the color of a pixel on a region at the given index.
*
* @region	the region to draw on.
* @i	the index of the pixel.
* @col	the color of the pixel.
*
* This version does not perform bounds checking nor color blending.
 */
void		mbx_set_pixel_raw(t_mbxregion *region, t_vec2i pos, t_mbxcolor col);

/**
* Sets the color of a pixel on a region at the given index.
*
* @region	the region to draw on.
* @i	the index of the pixel.
* @col	the color of the pixel.
*
* This version does not perform bounds checking nor color blending.
 */
void		mbx_set_pixel_raw_xy(t_mbxregion *region,
				int x, int y, t_mbxcolor col);

/**
* Sets the color of a pixel on a region at the given index.
*
* @region	the region to draw on.
* @i	the index of the pixel.
* @col	the color of the pixel.
*
* This version does not perform bounds checking nor color blending.
 */
void		mbx_set_pixel_raw_i(t_mbxregion *region, int i, t_mbxcolor col);

/**
 * Draws a rectangle on a region.
 *
 * @region	the region to draw on.
 * @pos	the position of the top-left corner of the rectangle.
 * @size	the size of the rectangle in pixels.
 * @col	the color of the rectangle.
 */
void		mbx_set_rect(t_mbxregion *region,
				t_vec2i pos, t_vec2i size, t_mbxcolor col);

/**
 * Draws a line on a region.
 *
 * @region	the region to draw on.
 * @pos the position of the two endpoints of the line.
 * @col	the color of the line.
 *
 * Bresenham's line algorithm is used to draw the line.
 */
void		mbx_set_line(t_mbxregion *region, t_vec2ix2 pos, t_mbxcolor col);

/**
 * Draws a line on a region with a specified thickness.
 *
 * @region	the region to draw on.
 * @pos the position of the two endpoints of the line.
 * @thickness	the thickness of the line in pixels.
 * @col	the color of the line.
 */
void		mbx_set_line_thick(t_mbxregion *region,
				t_vec2ix2 pos, unsigned int thickness, t_mbxcolor col);

/**
 * Draws a single character on a region.
 *
 * @region	the region to draw on.
 * @pos the position of the character.
 * @c	the character to draw.
 * @font	the font to use, the font's base color is used.
 */
void		mbx_set_char(t_mbxregion *region,
				t_vec2i pos, char c, t_mbxfont *font);

/**
 * Draws a string on a region.
 *
 * @region	the region to draw on.
 * @pos the position of the string.
 * @str	the string to draw.
 * @font	the font to use, the font's base color is used.
 */
void		mbx_set_text(t_mbxregion *region,
				t_vec2i pos, const char *str, t_mbxfont *font);

/**
 * Draws a region on a region.
 *
 * @region	the region to draw on.
 * @pos the position of the region.
 * @src	the region to draw.
 */
void		mbx_set_region(t_mbxregion *region, t_mbxregion *src,
				t_vec2i pos);

/**
 * Draws a part of a region on a region.
 *
 * @region	the region to draw on.
 * @pos the position of the subregion.
 * @uvwh	the uvwh of the subregion.
 * @src	the region to draw.
 */
void		mbx_set_subregion(t_mbxregion *region, t_mbxregion *src,
				t_vec2i pos, t_vec2ix2 uvwh);

/**
 * Draws a scaled region on a region.
 *
 * @region	the region to draw on.
 * @pos the position of the region.
 * @scale	the scale to use.
 * @src	the region to draw.
 */
void		mbx_set_region_scaled(t_mbxregion *region,
				t_mbxregion *src, t_vec2i pos, t_vec2 scale);

/**
 * Draws a scaled subregion on a region.
 *
 * @region	the region to draw on.
 * @posuvwh	the position and uvwh of the subregion.
 * @scale	the scale to use.
 * @src	the region to draw.
 */
void		mbx_set_subregion_scaled(t_mbxregion *region,
				t_mbxregion *src, t_vec2ix3 posuvwh, t_vec2 scale);

/**
 * Returns true if a pixel is within the bounds of a region.
 *
 * @region	the region to check.
 * @pos	the position of the pixel.
 */
bool		mbx_is_pixel_in_bounds(t_mbxregion *region, t_vec2i pos);

/**
 * Returns true if a pixel is within the bounds of a region.
 *
 * @region	the region to check.
 * @x	the x position of the pixel.
 * @y	the y position of the pixel.
 */
bool		mbx_is_pixel_in_bounds_xy(t_mbxregion *region, int x, int y);

/**
 * Returns true if a pixel is within the bounds of a region.
 *
 * @region	the region to check.
 * @i	the index of the pixel.
 */
bool		mbx_is_pixel_in_bounds_i(t_mbxregion *region, int i);

/**
 * Returns the index of a pixel in a region.
 *
 * @region	the region to check.
 * @pos	the position of the pixel.
 */
int			mbx_get_pixel_index(t_mbxregion *region, t_vec2i pos);

/**
 * Returns the index of a pixel in a region.
 *
 * @region	the region to check.
 * @x	the x position of the pixel.
 * @y	the y position of the pixel.
 */
int			mbx_get_pixel_index_xy(t_mbxregion *region, int x, int y);

/**
 * Creates and returns an opaque version of the given color.
 */
t_mbxcolor	color_opaque(t_mbxcolor col);

/**
 * Blends two color together, respecting transparency.
 *
 * @bg the background color.
 * @fg the foreground color.
 */
t_mbxcolor	color_blend(t_mbxcolor bg, t_mbxcolor fg);

/**
 * Blends two color together, respecting transparency.
 *
 * @bg the background color.
 * @fg the foreground color.
 *
 * this version does not optimize if fg is fully opaque or transparent,
 * use it when you know that fg isn't either.
 */
t_mbxcolor	color_blend_quick(t_mbxcolor bg, t_mbxcolor fg);

/**
 * Adds two color together, respecting transparency.
 *
 * @bg the background color.
 * @fg the foreground color.
 */
t_mbxcolor	color_add(t_mbxcolor bg, t_mbxcolor fg);

/**
 * Subtracts two color together, respecting transparency.
 *
 * @bg the background color.
 * @fg the foreground color.
 */
t_mbxcolor	color_sub(t_mbxcolor bg, t_mbxcolor fg);

/**
 * Average two color together.
 *
 * @col1 the first color.
 * @col2 the second color.
 */
t_mbxcolor	color_average(t_mbxcolor col1, t_mbxcolor col2);

/**
 * Adds two color together, without respecting transparency.
 *
 * @bg the background color.
 * @fg the foreground color.
 */
t_mbxcolor	color_add_fast(t_mbxcolor bg, t_mbxcolor fg);

/**
 * Subtracts two color together, without respecting transparency.
 *
 * @bg the background color.
 * @fg the foreground color.
 */
t_mbxcolor	color_sub_fast(t_mbxcolor bg, t_mbxcolor fg);