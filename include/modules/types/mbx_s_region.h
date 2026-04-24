/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_region.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:23:32 by rprieur           #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../../lib/VecLibC/include/veclc.h"
#include "mbx_s_color.h"

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
