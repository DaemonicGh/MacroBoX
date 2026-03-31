/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_region.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:23:32 by rprieur           #+#    #+#             */
/*   Updated: 2026/02/08 08:54:24 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "types/mbx_s_mbx.h"
#include "types/mbx_s_atlas.h"

/**
 * Creates and returns a new region with the given size.
 *
 * @size	The size of the region to create.
 *
 * This function can fail allocation, then the returned region will be 0 padded.
 */
t_mbx_region
mbx_make_region(
	t_mbx *mbx, t_vec2i size);

/**
 * Creates and returns a new region with a linked image.
 *
 * @mbx		The macrobox context.
 * @size	The size of the region to create.
 *
 * This function can fail allocation, then the returned region will be 0 padded.
 */
t_mbx_region
mbx_make_region_with_image(
	t_mbx *mbx, t_vec2i size);

/**
 * Creates and returns a new region from the given image.
 *
 * @mbx		The macrobox context.
 * @image	The image to create the region from.
 *
 * This function can fail allocation, then the returned region will be 0 padded.
 */
t_mbx_region
mbx_make_region_from_image(
	t_mbx *mbx, t_mbx_image *image);

/**
 * Creates and returns a new region from the given image path.
 *
 * @mbx 		The macrobox context.
 * @filename	The path to the image.
 *
 * This function can fail allocation, then the returned region will be 0 padded.
 */
t_mbx_region
mbx_make_region_from_file(
	t_mbx *mbx, char *filename);

/**
 * Destroys and frees the contents of the given region.
 *
 * @mbx 	The macrobox context.
 * @region	The region to destroy.
 */
void
mbx_destroy_region(
	t_mbx *mbx, t_mbx_region *region);

/**
 * Modifies the given region's content using the provided color modifiers.
 *
 * @dest				The region to modify.
 * @color_modifier_data	The data pointer to pass to the modifers.
 * @color_getter		The getter modifier function.
 * @color_setter		The setter modifier function.
 *
 * If the data pointer is set to NULL, the region's will be used.
 * If set to NULL, the getter and setter modifiers will do nothing.
 */
void
mbx_modify_region(t_mbx_region *dest, void *color_modifier_data,
	t_mbx_color (*color_getter)(void *data, t_mbx_region *region, int i),
	t_mbx_color (*color_setter)(void *data, t_mbx_color col));

/**
 * Resizes the given region.
 *
 * @mbx		The MacroBoX context.
 * @region	The region to resize.
 * @size	The new size of the viewport.
 *
 * This function can fail allocation, then it will return false.
 */
bool
mbx_resize_region(
	t_mbx *mbx, t_mbx_region *region, t_vec2i size);

/**
 * Resizes the given region and its content.
 *
 * @mbx		The MacroBoX context.
 * @region	The region to resize.
 * @size	The new size of the viewport.
 *
 * This function can fail allocation, then it will return false.
 * The contents of the mlx image will not be copied (it will still be resized).
 */
bool
mbx_resize_region_with_content(
	t_mbx *mbx, t_mbx_region *region, t_vec2i size);

/**
 * Creates an returns a MacroBoX image.
 *
 * @mbx		the MacroBoX context.
 * @size	the size of the image.
 */
t_mbx_image
mbx_make_image(
	t_mbx *mbx, t_vec2i size);

/**
 * Creates an returns a MacroBoX image from a file.
 *
 * @mbx		the MacroBoX context.
 * @path	the path to the image file.
 */
t_mbx_image
mbx_make_image_from_file(
	t_mbx *mbx, char *path);

/**
 * Creates an returns a MacroBoX image from its MacroLibX equivalent.
 *
 * @mbx		the MacroBoX context.
 * @image	the MacroLibX image.
 * @size	the size of the image.
 */
t_mbx_image
mbx_make_image_from_mlx(
	mlx_image image, t_vec2i size);

/**
 * Destroys and frees the content of a MacroBoX image.
 *
 * @mbx		the MacroBoX context.
 * @image	the MacroBoX image to destroy.
 */
void
mbx_destroy_image(
	t_mbx *mbx, t_mbx_image *image);

/**
 * Creates and returns a font.
 *
 * @atlas		the source region for the atlas.
 * @region_size	the size of a region in the atlas in pixels.
 *
 * MacroBoX currently only supports monospace fonts,
 * make sure that the image's glyphs are white for color to work properly.
 */
t_mbx_atlas
mbx_make_atlas(
	t_mbx_region region, t_vec2i region_size);

/**
 * Destroys and frees the content of the given font.
 *
 * @mbx		the MacrBoX context.
 * @font	the font to destroy.
 */
void
mbx_destroy_atlas(
	t_mbx *mbx, t_mbx_atlas *atlas);

/**
 * Creates and returns a MacroBoX window.
 *
 * @mbx			the MacroBoX context.
 * @size		the size in pixels of the window.
 * @title		the title of the window.
 * @flags		bit mask of the window's behavior flags, see MBX_WINDOW_FLAG_*
 *
 * This function can fail allocation, then the result will be 0 padded.
 */
t_mbx_window
mbx_make_window(
	t_mbx *mbx, t_vec2i size, char *title, t_mbx_window_flags flags);

/**
 * Creates and returns a MacroBoX window that contains a target.
 *
 * @mbx			the MacroBoX context.
 * @size		the size in pixels of the window.
 * @title		the title of the window.
 * @flags		bit mask of the window's behavior flags, see MBX_WINDOW_FLAG_*
 *
 * This function can fail allocation, then the result will be 0 padded.
 */
t_mbx_window
mbx_make_window_with_target(
	t_mbx *mbx, t_vec2i size, char *title, t_mbx_window_flags flags);

/**
 * Creates and returns a MacroBoX window that targets to a given image.
 *
 * @mbx			the MacroBoX context.
 * @image		the image to target.
 *
 * This is an abstraction of the MacroLibX's function,
 * it is not compatible with MacroBoX drawing system.
 *
 * This function can fail allocation, then the result will be 0 padded.
 */
t_mbx_window
mbx_make_window_target(
	t_mbx *mbx, t_mbx_image image);

/**
 * Destroys and frees the contents of the given MacroBoX window.
 *
 * @mbx			the MacroBoX context.
 * @window		the window to destroy.
 */
void
mbx_destroy_window(
	t_mbx *mbx, t_mbx_window *window);

/**
 * Refreshes the given window's properties to match its values.
 *
 * @mbx			the MacroBoX context.
 * @window		the window to refresh.
 *
 * This function is very unstable and may result in unexpected behavior.
 */
void
mbx_refresh_window(
	t_mbx *mbx, t_mbx_window *window);

/**
 * Refreshes the given window's position to match its properties.
 *
 * @mbx			the MacroBoX context.
 * @window		the window to update.
 */
void
mbx_refresh_window_pos(
	t_mbx *mbx, t_mbx_window *window);

/**
 * Refreshes the given window's size to match its properties.
 *
 * @mbx			the MacroBoX context.
 * @window		the window to update.
 */
void
mbx_refresh_window_size(
	t_mbx *mbx, t_mbx_window *window);

/**
 * Centers the given window on the screen.
 *
 * @mbx			the MacroBoX context.
 * @window		the window to center.
 *
 * This function is very unstable and may result in unexpected behavior.
 */
void
mbx_center_window(
	t_mbx *mbx, t_mbx_window *window);

/**
 * Resizes the viewport.
 *
 * @mbx		The MacroBoX context.
 * @size	The new size of the viewport.
 *
 * This function can fail allocation, then it will return false.
 */
bool
mbx_resize_viewport(
	t_mbx *mbx, t_vec2i size);

/**
 * Resizes the viewport and its content.
 *
 * @mbx		The MacroBoX context.
 * @size	The new size of the viewport.
 *
 * This function can fail allocation, then it will return false.
 * The content of the viewport will stretch to fit the new size.
 */
bool
mbx_resize_viewport_with_content(
	t_mbx *mbx, t_vec2i size);

/**
 * Gets the size of the main screen without requiring an open window.
 *
 * @mbx			the MacroBoX context.
 *
 * This function creates a temporary window.
 * This function can fail allocation, then the result will be 0 padded.
 */
t_vec2i
get_screen_size_windowless(
	t_mbx *mbx);

/**
 * Resets the settings to their default values.
 *
 * @mbx the MacroBox context.
 */
void
mbx_reset_settings(
	t_mbx *mbx);

/**
 * Updates the elements affected by settings.
 *
 * @mbx the MacroBox context.
 */
void
mbx_refresh_settings(
	t_mbx *mbx);
