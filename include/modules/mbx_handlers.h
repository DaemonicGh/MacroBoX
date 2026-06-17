/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_handlers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:23:32 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:43 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "mbx_core.h"

/**
 * Allocates a new memory block and adds it to the memory manager.
 *
 * @mbx			The MacroBoX context.
 * @alloc_size	The amount of bytes to allocate.
 *
 * This function can fail allocation, then the returned pointer will be NULL.
 */
void
*mbx_alloc(
	t_mbx *mbx, size_t alloc_size);

/**
 * Allocates a new memory block and adds it to the memory manager.
 *
 * @mbx			The MacroBoX context.
 * @alloc_size	The amount of bytes to allocate.
 * @data		Various flags telling how the memory should be handled.
 *
 * This function can fail allocation, then the returned pointer will be NULL.
 */
void
*mbx_alloc_flags(
	t_mbx *mbx, size_t alloc_size, t_mbx_alloc_flags data);

/**
 * Adds a pointer to the memory manager.
 *
 * @mbx		The MacroBoX context.
 * @ptr		The pointer to add.
 *
 * This function can fail, then it will return false.
 */
bool
mbx_add_alloc(
	t_mbx *mbx, void *ptr, t_mbx_alloc_flags data);

/**
 * Returns the allocation in the memory manager that matches the given pointer.
 *
 * @mbx		The MacroBoX context.
 * @ptr		The pointer to look for.
 *
 * If no instance of the pointer is found, or if the pointer is NULL, this
 * function will return NULL.
 */
t_mbx_alloc
*mbx_get_alloc(t_mbx *mbx, void *ptr);

/**
 * Changes the given pointer's flags.
 *
 * @mbx		The MacroBoX context.
 * @ptr		The pointer to modify.
 * @add		The flags to add to the pointer.
 * @remove	The flags to remove to the pointer.
 *
 * If no instance of the pointer is found, or if the pointer is NULL, this
 * function will return false.
 */
bool
mbx_change_alloc_flags(
	t_mbx *mbx, void *ptr, t_mbx_alloc_flags add, t_mbx_alloc_flags remove);

/**
 * Clears the given pointer from the memory manager and frees it.
 *
 * @mbx		The MacroBoX context.
 * @ptr		The pointer to free and clear.
 *
 * If no instance of the pointer is found, or if the pointer is NULL, this
 * function will return false and the pointer will not be freed.
 * This function properly disposes of MacroLibX instances.
 */
bool
mbx_free(t_mbx *mbx, void *ptr);

/**
* Clears all matching pointers from the memory manager and frees them.
 *
 * @mbx			The MacroBoX context.
 * @whitelist	A mask of all the flags to free.
 * @blacklist	A mask of all the flags to not free.
 *
 * To be freed, an allocation must not have any flag in the blacklist
 * and must have at least one flag in the whitelist.
 */
void
mbx_free_groups(
	t_mbx *mbx, t_mbx_alloc_flags whitelist, t_mbx_alloc_flags blacklist);

/**
 * Creates and returns a new region with the given size.
 *
 * @mbx		The MacroBoX context.
 * @size	The size of the region to create.
 *
 * This function can fail allocation, then the returned region will be NULL.
 */
t_mbx_region
*mbx_create_region(t_mbx *mbx, t_vec2i size);

/**
 * Creates and returns a new region with a linked mlx image.
 *
 * @mbx		The MacroBoX context.
 * @size	The size of the region to create.
 *
 * This function can fail allocation, then the returned region will be NULL.
 */
t_mbx_region
*mbx_create_region_with_image(t_mbx *mbx, t_vec2i size);

/**
 * Creates and returns a new region from the given mlx image.
 *
 * @mbx		The MacroBoX context.
 * @image	The image to create the region from.
 *
 * This function can fail allocation, then the returned region will be NULL.
 */
t_mbx_region
*mbx_create_region_from_image(t_mbx *mbx, t_mbx_image *image);

/**
 * Creates and returns a new region initialized from the given image path.
 *
 * @mbx 		The MacroBoX context.
 * @filename	The path to the image.
 *
 * This function can fail allocation, then the returned region will be NULL.
 */
t_mbx_region
*mbx_create_region_from_file(t_mbx *mbx, char *filename);

/**
 * Creates and returns a new region with a linked mlx image, initialized
 * from the given image path.
 *
 * @mbx 		The MacroBoX context.
 * @filename	The path to the image.
 *
 * This function can fail allocation, then the returned region will be NULL.
 */
t_mbx_region
*mbx_create_region_from_file_with_image(t_mbx *mbx, char *filename);

/**
 * Creates and assign an mlx image to the given region.
 *
 * @mbx 		The MacroBoX context.
 * @region		The region to add the image to.
 *
 * This function can fail allocation, then the function will return false.
 */
bool
mbx_create_region_image(t_mbx *mbx, t_mbx_region *region);

/**
 * Destroys and frees the contents of the given region.
 *
 * @mbx 	The MacroBoX context.
 * @region	The region to destroy.
 */
void
mbx_destroy_region(t_mbx *mbx, t_mbx_region *region);

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

/*
 * Transforms the given region to an atlas with the specified subregion size.
 *
 * @region			The region to transform.
 * @subregion_size	The subregion size to of the new atlas.
 *
 * This function can be safely daisy-chained with region creation functions.
 */
t_mbx_atlas
*mbx_atlas(
	t_mbx_region *region, t_vec2i subregion_size);

/**
 * Returns true if the given region is a valid atlas.
 *
 * @region	The region to check.
 */
bool
mbx_is_atlas(t_mbx_region *region);

/**
 * Returns an allocated area with a new region of the given size at its end.
 *
 * @size		The size of the region to create.
 * @struct_size	The size in bytes of the header (including the region's).
 *
 * This function is meant to be used to create custom region wrappers.
 * This function can fail allocation, then the returned allocation will be NULL.
 */
void
*mbx_create_region_ext(
	t_mbx *mbx, t_vec2i size, size_t struct_size);

/**
 * Returns an allocated area with a new region of the given size
 * and a linked mlx image at its end.
 *
 * @size		The size of the region to create.
 * @struct_size	The size in bytes of the header (including the region's).
 *
 * This function is meant to be used to create custom region wrappers.
 * This function can fail allocation, then the returned allocation will be NULL.
 */
void
*mbx_create_region_ext_with_image(
	t_mbx *mbx, t_vec2i size, size_t struct_size);

/**
 * Returns an allocated area with a new region at its end, initialized
 * from the given mlx image.
 *
 * @size		The size of the region to create.
 * @struct_size	The size in bytes of the header (including the region's).
 *
 * This function is meant to be used to create custom region wrappers.
 * This function can fail allocation, then the returned allocation will be NULL.
 */
void
*mbx_create_region_ext_from_image(
	t_mbx *mbx, t_mbx_image *image, size_t struct_size);

/**
 * Returns an allocated area with a new region at its end, initialized
 * from the given image path.
 *
 * @size		The size of the region to create.
 * @struct_size	The size in bytes of the header (including the region's).
 *
 * This function is meant to be used to create custom region wrappers.
 * This function can fail allocation, then the returned allocation will be NULL.
 */
void
*mbx_create_region_ext_from_file(
	t_mbx *mbx, char *filename, size_t struct_size);

/**
* Returns an allocated area with a new region and a linked mlx image
*  at its end, initialized from the given image path.
 *
 * @size		The size of the region to create.
 * @struct_size	The size in bytes of the header (including the region's).
 *
 * This function is meant to be used to create custom region wrappers.
 * This function can fail allocation, then the returned allocation will be NULL.
 */
void
*mbx_create_region_ext_from_file_with_image(
	t_mbx *mbx, char *filename, size_t struct_size);

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
mbx_create_image(
	t_mbx *mbx, t_vec2i size);

/**
 * Creates an returns a MacroBoX image from a file.
 *
 * @mbx		the MacroBoX context.
 * @path	the path to the image file.
 */
t_mbx_image
mbx_create_image_from_file(t_mbx *mbx, char *path);

/**
 * Creates an returns a MacroBoX image from its MacroLibX equivalent.
 *
 * @mbx		the MacroBoX context.
 * @image	the MacroLibX image.
 * @size	the size of the image.
 */
t_mbx_image
mbx_create_image_from_mlx(t_mbx *mbx, mlx_image image, t_vec2i size);

/**
 * Destroys and frees the content of a MacroBoX image.
 *
 * @mbx		the MacroBoX context.
 * @image	the MacroBoX image to destroy.
 */
void
mbx_destroy_image(t_mbx *mbx, t_mbx_image *image);

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
mbx_create_window(
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
mbx_create_window_with_target(
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
mbx_create_window_target(t_mbx *mbx, t_mbx_image image);

/**
 * Destroys and frees the contents of the given MacroBoX window.
 *
 * @mbx			the MacroBoX context.
 * @window		the window to destroy.
 */
void
mbx_destroy_window(t_mbx *mbx, t_mbx_window *window);

/**
 * Refreshes the given window's properties to match its values.
 *
 * @mbx			the MacroBoX context.
 * @window		the window to refresh.
 *
 * This function is very unstable and may result in unexpected behavior.
 */
void
mbx_update_window(t_mbx *mbx, t_mbx_window *window);

/**
 * Refreshes the given window to match its properties.
 *
 * @mbx			the MacroBoX context.
 * @window		the window to update.
 */
void
mbx_refresh_window(t_mbx *mbx, t_mbx_window *window);

/**
 * Returns the fps cap currently applied to the main window.
 *
 * @mbx			the MacroBoX context.
 *
 * By default, the fps cap will lower if
 * the main window is minimized or unfocused,
 * those values can be changed in the settings.
 */
int
mbx_get_fps_cap(t_mbx *mbx);

/**
 * Resizes the viewport.
 *
 * @mbx		The MacroBoX context.
 * @size	The new size of the viewport.
 *
 * This function can fail allocation, then it will return false.
 */
bool
mbx_resize_viewport(t_mbx *mbx, t_vec2i size);

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
mbx_resize_viewport_with_content(t_mbx *mbx, t_vec2i size);

/**
 * Gets the size of the main screen without requiring an open window.
 *
 * @mbx			the MacroBoX context.
 *
 * This function creates a temporary window.
 * This function can fail allocation, then the result will be 0 padded.
 */
t_vec2i
mbx_get_screen_size_windowless(t_mbx *mbx);

/**
 * Resets the settings to their default values.
 *
 * @mbx the MacroBox context.
 */
void
mbx_reset_settings(t_mbx *mbx);

/**
 * Updates the elements affected by settings.
 *
 * @mbx the MacroBox context.
 */
void
mbx_refresh_settings(t_mbx *mbx);
