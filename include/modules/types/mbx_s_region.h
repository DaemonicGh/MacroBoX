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
 * @canvas	the array containing the image data.
 * @image	(optional) a mlx_image slot to store the image as a MacroLibX image.
 * @size	the size of the image.
 *
 * This struct must be destroyed manually using mbx_destroy_region().
 */
typedef struct s_mbx_region
{
	t_mbx_color	*canvas;
	mlx_image	image;
	t_vec2i		size;
}	t_mbx_region;
