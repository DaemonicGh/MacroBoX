/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_drawing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:32:17 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:43 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../lib/VecLibC/include/veclc.h"
#include "mbx_core.h"

/**
 * Clears the given region with the given color.
 *
 * @region	the region to query.
 * @col		the color to clear the region with.
 *
 * Color blending won't be performed
 */
void
mbx_clear(
	t_mbx_region *restrict region, t_mbx_color col);

/**
 * Returns the color of a pixel on a region at the given position.
 *
 * @region	the region to query.
 * @pos		the position of the pixel.
 */
t_mbx_color
mbx_get_pixel(
	t_mbx_region *restrict region, t_vec2i pos);

/**
 * Returns the color of a pixel on a region at the given position.
 *
 * @region	the region to query.
 * @x		the x-coordinate of the pixel.
 * @y		the y-coordinate of the pixel.
 */
t_mbx_color
mbx_get_pixel_xy(
	t_mbx_region *restrict region, int x, int y);

/**
 * Returns the color of a pixel on a region at the given position.
 *
 * @region	the region to query.
 * @i		the index of the pixel.
 */
t_mbx_color
mbx_get_pixel_i(
	t_mbx_region *restrict region, int i);

/**
 * Returns the color of a pixel on a region at the given position.
 *
 * @region	the region to query.
 * @pos		the position of the pixel.
 *
 * This version doesn't perform bounds checking.
 */
t_mbx_color
mbx_get_pixel_unsafe(
	t_mbx_region *restrict region, t_vec2i pos);

/**
 * Returns the color of a pixel on a region at the given position.
 *
 * @region	the region to query.
 * @x		the x-coordinate of the pixel.
 * @y		the y-coordinate of the pixel.
 *
 * This version doesn't perform bounds checking.
 */
t_mbx_color
mbx_get_pixel_unsafe_xy(
	t_mbx_region *restrict region, int x, int y);

/**
 * Returns the color of a pixel on a region at the given position.
 *
 * @region	the region to query.
 * @i		the index of the pixel.
 *
 * This version doesn't perform bounds checking.
 */
t_mbx_color
mbx_get_pixel_unsafe_i(
	t_mbx_region *restrict region, int i);

/**
 * Returns the color of a pixel on a region at the given position.
 *
 * @region	the region to query.
 * @pos		the position of the pixel.
 *
 * This version doesn't perform bounds checking
 * and isn't affected by color modifiers.
 */
t_mbx_color
mbx_get_pixel_raw(
	t_mbx_region *restrict region, t_vec2i pos);

/**
 * Returns the color of a pixel on a region at the given position.
 *
 * @region	the region to query.
 * @x		the x-coordinate of the pixel.
 * @y		the y-coordinate of the pixel.
 *
 * This version doesn't perform bounds checking
 * and isn't affected by color modifiers.
 */
t_mbx_color
mbx_get_pixel_raw_xy(
	t_mbx_region *restrict region, int x, int y);

/**
 * Returns the color of a pixel on a region at the given position.
 *
 * @region	the region to query.
 * @i		the index of the pixel.
 *
 * This version doesn't perform bounds checking
 * and isn't affected by color modifiers.
 */
t_mbx_color
mbx_get_pixel_raw_i(
	t_mbx_region *restrict region, int i);

/**
 * Sets the color of a pixel on a region at the given position.
 *
 * @region	the region to draw on.
 * @pos		the position of the pixel.
 * @col		the color of the pixel.
 *
 * It will be blended with the current pixel color if the color is not opaque.
 */
void
mbx_set_pixel(
	t_mbx_region *restrict region, t_vec2i pos, t_mbx_color col);

/**
 * Sets the color of a pixel on a region at the given position.
 *
 * @region	the region to draw on.
 * @x		the x-coordinate of the pixel.
 * @y		the y-coordinate of the pixel.
 * @col		the color of the pixel.
 *
 * It will be blended with the current pixel color if the color is not opaque.
 */
void
mbx_set_pixel_xy(
	t_mbx_region *restrict region, int x, int y, t_mbx_color col);

/**
 * Sets the color of a pixel on a region at the given position.
 *
 * @region	the region to draw on.
 * @x		the x-coordinate of the pixel.
 * @y		the y-coordinate of the pixel.
 * @col		the color of the pixel.
 *
 * This version doesn't perform bounds checking.
 * Color blending is still performed.
 */
void
mbx_set_pixel_unsafe(
	t_mbx_region *restrict region, t_vec2i pos, t_mbx_color col);

/**
 * Sets the color of a pixel on a region at the given position.
 *
 * @region	the region to draw on.
 * @x		the x-coordinate of the pixel.
 * @y		the y-coordinate of the pixel.
 * @col		the color of the pixel.
 *
 * This version doesn't perform bounds checking.
 * Color blending is still performed.
 */
void
mbx_set_pixel_unsafe_xy(
	t_mbx_region *restrict region, int x, int y, t_mbx_color col);

/**
 * Sets the color of a pixel on a region at the given index.
 *
 * @region	the region to draw on.
 * @i		the index of the pixel.
 * @col		the color of the pixel.
 *
 * This version doesn't perform bounds checking.
 * Color blending is still performed.
 */
void
mbx_set_pixel_unsafe_i(
	t_mbx_region *restrict region, int i, t_mbx_color col);

/**
* Sets the color of a pixel on a region at the given index.
*
* @region	the region to draw on.
* @i		the index of the pixel.
* @col		the color of the pixel.
*
* This version doesn't perform bounds checking
* and isn't affected by color modifiers.
 */
void
mbx_set_pixel_raw(
	t_mbx_region *restrict region, t_vec2i pos, t_mbx_color col);

/**
* Sets the color of a pixel on a region at the given index.
*
* @region	the region to draw on.
* @i		the index of the pixel.
* @col		the color of the pixel.
*
* This version doesn't perform bounds checking
* and isn't affected by color modifiers.
 */
void
mbx_set_pixel_raw_xy(
	t_mbx_region *restrict region, int x, int y, t_mbx_color col);

/**
* Sets the color of a pixel on a region at the given index.
*
* @region	the region to draw on.
* @i		the index of the pixel.
* @col		the color of the pixel.
*
* This version doesn't perform bounds checking
* and isn't affected by color modifiers.
 */
void
mbx_set_pixel_raw_i(
	t_mbx_region *restrict region, int i, t_mbx_color col);

/**
 * Draws a rectangle on a region.
 *
 * @region	the region to draw on.
 * @pos		the position of the top-left corner of the rectangle.
 * @size	the size of the rectangle in pixels.
 * @col		the color of the rectangle.
 */
void
mbx_set_rect(
	t_mbx_region *restrict region, t_vec2i pos, t_vec2i size, t_mbx_color col);

/**
 * Draws a line on a region.
 *
 * @region	the region to draw on.
 * @pos		the position of the two endpoints of the line.
 * @col		the color of the line.
 *
 * Bresenham's line algorithm is used to draw the line.
 */
void
mbx_set_line(
	t_mbx_region *restrict region, t_vec2ix2 pos, t_mbx_color col);

/**
 * Draws a line on a region with a specified thickness.
 *
 * @region		the region to draw on.
 * @pos			the position of the two endpoints of the line.
 * @thickness	the thickness of the line in pixels.
 * @col			the color of the line.
 */
void
mbx_set_line_thick(
	t_mbx_region *restrict region, t_vec2ix2 pos,
	unsigned int thickness, t_mbx_color col);

/**
 * Draws a single character scaled on a region.
 *
 * @region		the region to draw on.
 * @c			the character to draw.
 * @pos_scaled 	the position and scale of the character.
 * @font		the font to use.
 *
 * If the font is not an atlas, nothing will be drawn.
 */
void
mbx_set_char(
	t_mbx_region *restrict region,
	char c, t_vec2i pos, t_mbx_atlas *font);

void
mbx_set_char_scaled(
	t_mbx_region *restrict region,
	char c, t_vec2ix2 pos_scale, t_mbx_atlas *font);

/**
 * Draws a string on a region.
 *
 * @region	the region to draw on.
 * @str		the string to draw.
 * @pos 	the position of the string.
 * @font	the font to use.
 *
 * If the font is not an atlas, nothing will be drawn.
 */
void
mbx_set_text(
	t_mbx_region *restrict region,
	const char *str, t_vec2i pos, t_mbx_atlas *font);

/**
 * Draws a string scaled on a region.
 *
 * @region		the region to draw on.
 * @str			the string to draw.
 * @pos_scale 	the position and scale of the string.
 * @font		the font to use.
 *
 * If the font is not an atlas, nothing will be drawn.
 */
void
mbx_set_text_scaled(
	t_mbx_region *restrict region,
	const char *str, t_vec2ix2 pos_scale, t_mbx_atlas *font);

/**
 * Draws a region on a region.
 *
 * @region	the region to draw on.
 * @pos 	the position of the region.
 * @src		the region to draw.
 */
void
mbx_set_region(
	t_mbx_region *restrict region, t_mbx_region *restrict src, t_vec2i pos);

/**
 * Draws a part of a region on a region.
 *
 * @region	the region to draw on.
 * @pos 	the position of the subregion.
 * @uvwh	the uvwh of the subregion.
 * @src		the region to draw.
 */
void
mbx_set_subregion(
	t_mbx_region *restrict region, t_mbx_region *restrict src,
	t_vec2i pos, t_vec2ix2 uvwh);

/**
 * Draws a scaled region on a region.
 *
 * @region	the region to draw on.
 * @pos 	the position of the region.
 * @scale	the scale to use.
 * @src		the region to draw.
 */
void
mbx_set_region_scaled(
	t_mbx_region *restrict region, t_mbx_region *restrict src,
	t_vec2i pos, t_vec2 scale);

/**
 * Draws a scaled subregion on a region.
 *
 * @region	the region to draw on.
 * @posuvwh	the position and uvwh of the subregion.
 * @scale	the scale to use.
 * @src		the region to draw.
 */
void
mbx_set_subregion_scaled(
	t_mbx_region *restrict region, t_mbx_region *restrict src,
	t_vec2ix3 posuvwh, t_vec2 scale);

/**
 * Returns true if a pixel is within the bounds of a region.
 *
 * @region	the region to check.
 * @pos		the position of the pixel.
 */
bool
mbx_is_pixel_in_bounds(
	t_mbx_region *restrict region, t_vec2i pos);

/**
 * Returns true if a pixel is within the bounds of a region.
 *
 * @region	the region to check.
 * @x		the x position of the pixel.
 * @y		the y position of the pixel.
 */
bool
mbx_is_pixel_in_bounds_xy(
	t_mbx_region *restrict region, int x, int y);

/**
 * Returns true if a pixel is within the bounds of a region.
 *
 * @region	the region to check.
 * @i		the index of the pixel.
 */
bool
mbx_is_pixel_in_bounds_i(
	t_mbx_region *restrict region, int i);

/**
 * Returns the index of a pixel in a region.
 *
 * @region	the region to check.
 * @pos		the position of the pixel.
 */
int
mbx_get_pixel_index(
	t_mbx_region *restrict region, t_vec2i pos);

/**
 * Returns the index of a pixel in a region.
 *
 * @region	the region to check.
 * @x		the x position of the pixel.
 * @y		the y position of the pixel.
 */
int
mbx_get_pixel_index_xy(
	t_mbx_region *restrict region, int x, int y);

/**
 * Creates an opaque color from a hexadecimal value.
 *
 * @hex the hexadecimal value of the color.
 *
 * the hexadecimal value is expected to be in the format 0xRRGGBB.
 */
t_mbx_color
color(
	unsigned int hex);

/**
 * Creates a color from a hexadecimal value.
 *
 * @hex The hexadecimal value of the color.
 *
 * the hexadecimal value is expected to be in the format 0xRRGGBBAA.
 */
t_mbx_color
color_rgba(
	unsigned int hex);

/**
 * Creates a color from its four channels.
 *
 * @r	The red channel of the color.
 * @g	The green channel of the color.
 * @b	The blue channel of the color.
 * @a	The alpha channel of the color.
 */
t_mbx_color
color_r_g_b_a(
	uint8_t r, uint8_t g, uint8_t b, uint8_t a);

/**
 * Blends two colors together, respecting transparency.
 *
 * @bg the background color.
 * @fg the foreground color.
 */
t_mbx_color
color_blend(
	t_mbx_color bg, t_mbx_color fg);

/**
 * Blends two colors together, respecting transparency.
 *
 * @bg the background color.
 * @fg the foreground color.
 *
 * This version doesn't optimize if fg is fully opaque or transparent,
 * use it when you know that fg isn't either.
 */
t_mbx_color
color_blend_quick(
	t_mbx_color bg, t_mbx_color fg);

/**
 * Adds two colors together, respecting transparency.
 *
 * @bg the background color.
 * @fg the foreground color.
 */
t_mbx_color
color_add(
	t_mbx_color bg, t_mbx_color fg);

/**
 * Subtracts two colors together, respecting transparency.
 *
 * @bg the background color.
 * @fg the foreground color.
 */
t_mbx_color
color_sub(
	t_mbx_color bg, t_mbx_color fg);

/**
 * Mutiplies two colors together.
 *
 * @bg the background color.
 * @fg the foreground color.
 */
t_mbx_color
color_mult(
	t_mbx_color col1, t_mbx_color col2);

/**
 * Average two colors together.
 *
 * @col1 the first color.
 * @col2 the second color.
 */
t_mbx_color
color_average(
	t_mbx_color col1, t_mbx_color col2);

/**
 * Average two colors together, with an optional weight.
 *
 * @col1 the first color.
 * @col2 the second color.
 * @weight_ratio the weight ratio of the second color.
 *
 * If weight_ratio is above 1, the result will favor col1, otherwise col2.
 */
t_mbx_color
color_average_weighted(
	t_mbx_color col1, t_mbx_color col2, double weight_ratio);

/**
 * Interpolates between two colors by t.
 *
 * @col1 the first color.
 * @col2 the second color.
 * @t	 the interpolation factor.
 *
 * If t is 0, returns start. If t is 1, returns end.
 * Values of t outside the range [0, 1] give undefined results.
 */
t_mbx_color
color_lerp(
	t_mbx_color col1, t_mbx_color col2, double t);

/**
 * Converts a color to a normalized 4D vector.
 */
t_vec4
vec4_from_color(t_mbx_color	col);

/**
 * Converts a normalized 4D vector to a color.
 */
t_mbx_color
vec4_to_color(t_vec4 p);

/**
 * Blends two vectorized colors together, respecting transparency.
 *
 * @bg the background color.
 * @fg the foreground color.
 *
 * This version doesn't optimize if fg is fully opaque or transparent,
 * use it when you know that fg isn't either.
 */
t_vec4
vec4_blend_quick(t_vec4 bg, t_vec4 fg);

/**
 * Blends two vectorized colors together, respecting transparency.
 *
 * @bg the background color.
 * @fg the foreground color.
 */
t_vec4
vec4_blend(t_vec4 bg, t_vec4 fg);

/**
 * Forces the rendering of the given region on the window.
 *
 * @mbx	the MacroBoX context.
 *
 * If the given region doesn't have an assigned image, one will be created. This
 * process can fail, then the function will return false.
 * Make sure to not destroy your region during the frame.
 */
bool
mbx_render_region(
	t_mbx *mbx, t_mbx_region *region, t_vec2i pos, t_vec2 scale);

/**
 * Forces the rendering of the given region as a viewport on the window.
 *
 * @mbx	the MacroBoX context.
 *
 * If the given region doesn't have an assigned image, one will be created. This
 * process can fail, then the function will return false.
 * Make sure to not destroy your region during the frame.
 */
bool
mbx_render_region_as_viewport(
	t_mbx *mbx, t_mbx_region *region, t_mbx_viewport_render render_mode);
