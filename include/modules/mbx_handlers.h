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
#include <stdbool.h>

/**
 * Creates and returns a new region with the given size.
 *
 * @size	The size of the region to create.
 *
 * This function can fail allocation, then the returned region will NULL.
 */
t_mbx_region
*mbx_make_region(
	t_mbx *mbx, t_vec2i size);

/**
 * Creates and returns a new region with a linked image.
 *
 * @mbx		The macrobox context.
 * @size	The size of the region to create.
 *
 * This function can fail allocation, then the returned region will be NULL.
 */
t_mbx_region
*mbx_make_region_with_image(
	t_mbx *mbx, t_vec2i size);

/**
 * Creates and returns a new region from the given image.
 *
 * @mbx		The macrobox context.
 * @image	The image to create the region from.
 *
 * This function can fail allocation, then the returned region will be NULL.
 */
t_mbx_region
*mbx_make_region_from_image(
	t_mbx *mbx, t_mbx_image *image);

/**
 * Creates and returns a new region from the given image path.
 *
 * @mbx 		The macrobox context.
 * @filename	The path to the image.
 *
 * This function can fail allocation, then the returned region will be NULL.
 */
t_mbx_region
*mbx_make_region_from_file(
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
 * Resizes the given region.
 *
 * @mbx		The MacroBoX context.
 * @region	A pointer to the region to resize.
 * @size	The new size of the viewport.
 *
 * This function can fail allocation, then it will return false.
 */
bool
mbx_resize_region(
	t_mbx *mbx, t_mbx_region **region, t_vec2i size);

/**
 * Resizes the given region and its content.
 *
 * @mbx		The MacroBoX context.
 * @region	A pointer to the region to resize.
 * @size	The new size of the viewport.
 *
 * This function can fail allocation, then it will return false.
 * The contents of the mlx image will not be copied (it will still be resized).
 */
bool
mbx_resize_region_with_content(
	t_mbx *mbx, t_mbx_region **region, t_vec2i size);

/**
 * Returns true if the given region is a valid atlas.
 *
 * @region	The region to check.
 */
bool
mbx_is_atlas(t_mbx_region *region);

/**
 * Default color getter function for regions.
 *
 * @data	a customizable data pointer, MacroBoX context by default.
 * @region	the region to get the pixel from.
 * @index	the index of the pixel in the region.
 *
 * For performance reasons, the index is given rather than the xy position.
 * MacroBoX uses this function for color getting by default,
 * it can be overloaded for each region using region.pipeline.get.
 */
t_mbx_color
mbx_default_pipeline_get(
	void *restrict data, t_mbx_region *restrict region, int index);

/**
 * Color getter function for regions, does nothing.
 *
 * @data		a customizable data pointer, MacroBoX context by default.
 * @background	the background color.
 * @foreground	the foreground color.
 *
 * This function is not the default color blender,
 * MacroBoX uses mbx_color_blend_quick by default.
 */
t_mbx_color
mbx_pipeline_blend_ignore(
	void *restrict data, t_mbx_color background, t_mbx_color foreground);

/**
 * Default color getter function for regions.
 *
 * @data		a customizable data pointer, MacroBoX context by default.
 * @background	the background color.
 * @foreground	the foreground color.
 *
 * The function will never be ran for fully opaque or transparent foregrounds.
 * MacroBoX uses this function for color blending by default,
 * it can be overloaded for each region using region.pipeline.blend.
 */
t_mbx_color
mbx_default_pipeline_blend(
	void *restrict data, t_mbx_color background, t_mbx_color foreground);

/**
 * Default color setter function for regions.
 *
 * @data	a customizable data pointer, MacroBoX context by default.
 * @region	the region to set the pixel to.
 * @index	the index of the target pixel in the region.
 * @color	the color to be modified.
 *
 * For performance reasons, the destination position cannot be passed on.
 * MacroBoX uses this function for color setting by default,
 * it can be overloaded for each region using region.pipeline.set.
 */
void
mbx_default_pipeline_set(
	void *restrict data, t_mbx_region *restrict region,
	int index, t_mbx_color color);

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
mbx_update_window(
	t_mbx *mbx, t_mbx_window *window);

/**
 * Refreshes the given window to match its properties.
 *
 * @mbx			the MacroBoX context.
 * @window		the window to update.
 */
void
mbx_refresh_window(
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
mbx_get_screen_size_windowless(
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
