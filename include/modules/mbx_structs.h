/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:28:18 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:43 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../lib/VecLibC/include/veclc.h"
#include "mbx_mlx.h"
#include "mbx_constants.h"

/**
 * Represents a color in the RGBA color space.
 * works the same way as MacroLibX's color.
 */
typedef mlx_color			t_mbx_color;

typedef struct s_mbx_region	t_mbx_region;

/**
 * Struct contaning all the functions used in a region drawing pipeline.
 *
 * The functions are used as follows in the drawing functions :
 *   if (color.a == 0x00) return;
 *   if (color.a != 0xFF) color = blend(data, get(data, region, index), color);
 *   set(data, region, index, color);
 */
typedef struct s_mbx_region_pipeline_functions
{
	// Function used to get a color from the buffer.
	t_mbx_color	(*get)(
		void *restrict data,
		t_mbx_region * restrict region,
		int index);
	// Function used to blend a translucent color before setting.
	t_mbx_color	(*blend)(
		void *restrict data,
		t_mbx_color background,
		t_mbx_color foreground);
	// Function used to set a color on the buffer.
	void		(*set)(
			void *restrict data,
			t_mbx_region *restrict region,
			int i,
			t_mbx_color color);
	// Data pointer passed to the color setter and getter.
	void		*data;
}	t_mbx_region_pipeline;

/**
 * Struct used to represent a MacroBoX image.
 *
 * This struct must be destroyed manually using mbx_destroy_region().
 */
typedef struct s_mbx_region
{
	// Optional slot to store the region
	mlx_image				image;
	// The size of the region.
	t_vec2i					size;
	// The size of a subregion, used for atlases.
	t_vec2i					subregion_size;
	// The pipeline functions used by the region.
	t_mbx_region_pipeline	pipeline;
	// The array (FAM) containing the pixel data.
	t_mbx_color				pixels[];
}	t_mbx_region;

/**
 * Struct to represent a MacroBoX image atlas.
 *
 * This uses the same struct as a regular region.
 * And exist to specify that the region is subdivided and
 * uses the subregion_size attribute.
 *
 * This struct must be destroyed manually using mbx_destroy_region().
 */
typedef struct s_mbx_region	t_mbx_atlas;

/**
 * Wrapper struct for a MacroLibX image.
 *
 * Do not confuse images with regions, which are MacroBoX actual images.
 * This struct must be destroyed manually using mbx_destroy_image().
 */
typedef struct s_mbx_image
{
	// The MacroLibX image.
	mlx_image	mlx;
	// The size of the image.
	t_vec2i		size;
}	t_mbx_image;

/**
 * Wrapper struct for a MacroLibX window.
 *
 * This struct must be destroyed manually using mbx_destroy_window().
 * WARNING: Resizing is VERY crash-prone!
 */
typedef struct s_mbx_window
{
	// The MacroLibX window.
	mlx_window		mlx;
	// The window's MacroLibX target image (if provided).
	mlx_image		mlx_image;
	// The position of the window.
	t_vec2i			pos;
	// The size of the window.
	t_vec2i			size;
	// The minimum and maximum size of the window.
	t_vec2ix2		limits;
	// The size of the screen the window is on.
	t_vec2i			screen_size;
	// The title of the window.
	char			*title;
	// True if the window is displayed on fullscreen.
	bool			is_fullscreen;
	// True if the window is resizable.
	bool			is_resizable;
	// True if the window is minimized.
	bool			is_minimized;
	// True if the window is maximized.
	bool			is_maximized;
	// True if the window is focused on.
	bool			is_focused;
}	t_mbx_window;

/**
 * Struct used to store all the configurable values
 * of the MacroBoX application.
 */
typedef struct s_mbx_settings
{
	// How the default viewport should display each frame,
	// see MBX_VIEWPORT_RENDER_*.
	t_mbx_viewport_render	viewport_render;
	// The color of the window areas that aren't able to display the viewport.
	t_mbx_color				background_color;
	// The maximum application refresh rate when focused.
	int						fps_cap;
	// The maximum application refresh rate when the window is minimized.
	int						fps_cap_minimized;
	// The maximum application refresh rate when the window is unfocused.
	int						fps_cap_unfocused;
	// A key that triggers the end of the application loop,
	// can be set to MBX_KEY_NONE to disable.
	int						exit_key;
	// A key that toggles fullscreen on the window,
	// can be set to MBX_KEY_NONE to disable.
	int						fullscreen_toggle_key;
	// If true, the application loop will end when the window cross is pressed.
	bool					do_window_cross_exit;
	// If true, the cursor will be invisible when over the window.
	bool					hide_cursor;
	// If true, the cursor will move to the center of the window every frame.
	bool					lock_cursor;
	// If true, the application will assume display text is typed
	// using a French AZERTY layout rather than QWERTY.
	bool					use_azerty;
	// The pipeline assigned to newly created regions.
	t_mbx_region_pipeline	default_pipeline;
	// The flags assigned to newly allocated memory blocks.
	t_mbx_alloc_flags		default_alloc_flags;
}	t_mbx_settings;

/**
 * Struct used to track a memory allocation performed by MacroBoX.
 */
typedef struct s_mbx_allocation
{
	// The pointer to the memory block.
	void					*ptr;
	// The unique identifier of the allocation.
	uint32_t				id;
	// Bit mask containing extra information about the allocation,
	// see MBX_ALLOC_*.
	t_mbx_alloc_flags		flags;
}	t_mbx_alloc;

/**
 * Struct used to track all memory allocations performed by MacroBoX.
 */
typedef struct s_mbx_allocator
{
	// Array tracking all allocations.
	t_mbx_alloc		*allocs;
	// Amount of tracked allocations in the array.
	uint32_t		alloc_count;
	// Capacity of the array.
	uint32_t		capacity;
	// Buffer containing recently freed slots.
	uint32_t		cache[MBX_ALLOCATOR_CACHE_SIZE];
}	t_mbx_allocator;
