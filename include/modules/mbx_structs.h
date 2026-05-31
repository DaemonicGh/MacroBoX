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

/**
 * Struct to represent a MacroBoX image.
 *
 * @image					an optional slot to store the region
 * as a MacroLibX image.
 * @size					the size of the region.
 * @subregion_size			the size of a subregion, used for atlases.
 * @pipeline				the pipeline functions used by the region.
 * @pixels					the array (FAM) containing the pixel data.
 *
 * This struct must be destroyed manually using mbx_destroy_region().
 */
typedef struct s_mbx_region	t_mbx_region;

/**
 * Struct contaning all the functions used in a region drawing pipeline.
 *
 * @get		the function used to get a color from the buffer.
 * @blend	the function used to blend a translucent color before setting.
 * @set		the function used to set a color on the buffer.
 * @data	the data pointer passed to the color setter and getter.
 *
 * The functions are used as follows in the drawing functions :
 *   if (color.a == 0x00) return;
 *   if (color.a != 0xFF) color = blend(data, get(data, region, index), color);
 *   set(data, region, index, color);
 */
typedef struct s_mbx_region_pipeline_functions
{
	t_mbx_color	(*get)(
		void *restrict data,
		t_mbx_region * restrict region,
		int index);
	t_mbx_color	(*blend)(
		void *restrict data,
		t_mbx_color background,
		t_mbx_color foreground);
	void		(*set)(
			void *restrict data,
			t_mbx_region *restrict region,
			int i,
			t_mbx_color color);
	void		*data;
}	t_mbx_region_pipeline;

typedef struct s_mbx_region
{
	mlx_image				image;
	t_vec2i					size;
	t_vec2i					subregion_size;
	t_mbx_region_pipeline	pipeline;
	t_mbx_color				pixels[];
}	t_mbx_region;

/**
 * Struct to represent a MacroBoX image atlas.
 *
 * It uses same struct as a regular region.
 * This typedef exist to specify that the region uses .subregion_size
 *
 * This struct must be destroyed manually using mbx_destroy_region().
 */
typedef struct s_mbx_region	t_mbx_atlas;

/**
 * Wrapper struct for a MacroLibX image.
 *
 * @mlx 	the MacroLibX image.
 * @size	the size of the image.
 *
 * Do not confuse images with regions, which are MacroBoX actual images.
 * This struct must be destroyed manually using mbx_destroy_image().
 */
typedef struct s_mbx_image
{
	mlx_image	mlx;
	t_vec2i		size;
}	t_mbx_image;

/**
 * Wrapper struct for a MacroLibX window.
 *
 * @win				the MacroLibX window.
 * @image			the target image if one is provided.
 * @pos				the position of the window.
 * @limits			the minimum and maximum size of the window.
 * @size			the size of the window.
 * @title			the title of the window.
 * @screen_size		the size of the screen the window is on.
 * @is_fullscreen	true if the window is fullscreen.
 * @is_resizable	true if the window is resizable.
 * @is_minimized	true if the window is minimized.
 * @is_maximized	true if the window is maximized.
 *
 * This struct must be destroyed manually using mbx_destroy_window().
 * WARNING: Resizing is VERY crash-prone!
 */
typedef struct s_mbx_window
{
	mlx_window		mlx;
	mlx_image		mlx_image;
	t_vec2i			pos;
	t_vec2i			size;
	t_vec2ix2		limits;
	t_vec2i			screen_size;
	char			*title;
	bool			is_fullscreen;
	bool			is_resizable;
	bool			is_minimized;
	bool			is_maximized;
	bool			is_focused;
}	t_mbx_window;

typedef struct s_mbx_allocation
{
	void					*ptr;
	uint32_t				id;
	t_mbx_alloc_flags		flags;
}	t_mbx_alloc;

typedef struct s_mbx_allocator
{
	t_mbx_alloc		*allocs;
	uint32_t		alloc_count;
	uint32_t		capacity;
	uint32_t		cache[MBX_ALLOCATOR_CACHE_SIZE];
}	t_mbx_allocator;
