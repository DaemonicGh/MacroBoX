/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_transform.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 20:20:30 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 13:14:44 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_S_TRANSFORM_H
# define MBX_S_TRANSFORM_H

# include "../../../VecLibC/includes/modules/types/veclc_s_vec2i.h"
# include "../../../VecLibC/includes/modules/types/veclc_s_vec2xn.h"
# include "../../../VecLibC/includes/modules/types/veclc_s_vec3xn.h"
# include "mbx_s_color.h"

/**
 * UNUSED FEATURE
 * Struct that contains transformation data for some draw calls.
 *
 * @matrix	affine matrix that holds the transformation data.
 * @color	color modifier.
 */
typedef struct s_mbxtransform
{
	double		matrix[2][3];
	t_mbxcolor	color;
}	t_mbxtransform;

/**
 * UNUSED FEATURE
 * Creates and returns an identity transform that does nothing.
 */
t_mbxtransform	mbx_transform_id(void);

/**
 * UNUSED FEATURE
 * Creates and returns a transform that contains the given data.
 *
 * @rotation	rotation angle in radians.
 * @scale		scale factor.
 * @pivot		pivot point, values must be in the range [0, 1].
 * @color		color modifier.
 */
t_mbxtransform	mbx_transform(float rotation,
					t_vec2 scale, t_vec2 pivot, t_mbxcolor color);

/**
 * UNUSED FEATURE
 * Creates and returns a transform that contains the given data.
 *
 * @matrix	affine matrix that holds the transformation data.
 * @color	color modifier.
 */
t_mbxtransform	mbx_transform_mat(t_vec3x2 matrix, t_mbxcolor color);

/**
 * UNUSED FEATURE
 *
 * Create and returns a transform that would allow to fit
 * a source rectangle into a destination parralelogram.
 *
 * @source_size	size of the source rectangle.
 * @points		coordinates of the points of the destination parralelogram.
 * @color		color modifier.
 *
 * This function returns an identity transform
 * if the points do not form a valid parallelogram.
 */
t_mbxtransform	mbx_transform_4p(
					t_vec2i source_size, t_vec2x4 points, t_mbxcolor color);
#endif
