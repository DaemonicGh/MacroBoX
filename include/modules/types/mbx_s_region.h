/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_region.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:23:32 by rprieur           #+#    #+#             */
/*   Updated: 2026/02/08 08:54:24 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../../lib/VecLibC/include/veclc.h"
#include "mbx_s_color.h"

/**
 * Struct to represent a MacroBoX image.
 *
 * @canvas				the array containing the pixel data.
 * @image				an optional slot to store the region
 * as a MacroLibX image.
 * @size				the size of the region.
 * @color_getter		the function used to get a color from the buffer.
 * @color_setter		the function used to set a color on the buffer.
 * @color_modifier_data	the data pointer passed to the setter and getter.
 *
 * This struct must be destroyed manually using mbx_destroy_region().
 */
typedef struct s_mbx_region	t_mbx_region;
typedef struct s_mbx_region
{
	t_mbx_color	*canvas;
	mlx_image	image;
	t_vec2i		size;
	t_mbx_color	(*color_getter)(void *data, t_mbx_region * region, int index);
	t_mbx_color	(*color_setter)(void *data, t_mbx_color col);
	void		*color_modifier_data;
}	t_mbx_region;
