/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 20:22:37 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 15:15:10 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../includes/modules/types/mbx_s_transform.h"
#include "../../VecLibC/includes/modules/veclc_vec2.h"
#include "../../VecLibC/includes/modules/types/veclc_s_vec2xn.h"
#include "../../VecLibC/includes/modules/types/veclc_s_vec3xn.h"

t_mbxtransform	mbx_transform_id(void)
{
	t_mbxtransform	transform;

	transform.matrix[0][0] = 1.0;
	transform.matrix[0][1] = 0.0;
	transform.matrix[1][0] = 0.0;
	transform.matrix[1][1] = 1.0;
	transform.matrix[0][2] = 0.0;
	transform.matrix[1][2] = 0.0;
	transform.color = color_rgba(0xFFFFFFFF);
	return (transform);
}

t_mbxtransform	mbx_transform(
	float rotation, t_vec2 scale, t_vec2 pivot, t_mbxcolor color)
{
	const double	c = cos(rotation);
	const double	s = sin(rotation);
	t_mbxtransform	transform;

	transform.matrix[0][0] = c * (1.0 / scale.x);
	transform.matrix[0][1] = s * (1.0 / scale.x);
	transform.matrix[1][0] = -s * (1.0 / scale.y);
	transform.matrix[1][1] = c * (1.0 / scale.y);
	transform.matrix[0][2] = pivot.x
		- (transform.matrix[0][0] * pivot.x + transform.matrix[0][1] * pivot.y);
	transform.matrix[1][2] = pivot.y
		- (transform.matrix[1][0] * pivot.x + transform.matrix[1][1] * pivot.y);
	transform.color = color;
	return (transform);
}

t_mbxtransform	mbx_transform_mat(t_vec3x2 matrix, t_mbxcolor color)
{
	t_mbxtransform	transform;

	transform.matrix[0][0] = matrix.p1.x;
	transform.matrix[0][1] = matrix.p1.y;
	transform.matrix[0][2] = matrix.p2.z;
	transform.matrix[1][0] = matrix.p2.x;
	transform.matrix[1][1] = matrix.p2.y;
	transform.matrix[1][2] = matrix.p2.z;
	transform.color = color;
	return (transform);
}

t_mbxtransform	mbx_transform_4p(
	t_vec2i source_size, t_vec2x4 points, t_mbxcolor color)
{
	t_mbxtransform	transform;

	if (!vec2_eq(vec2_add(vec2_sub(
					points.p3, points.p2), points.p1), points.p4))
	{
		transform = mbx_transform_id();
		transform.color = color;
		return (transform);
	}
	transform.matrix[0][0] = (points.p2.x - points.p1.x) / source_size.x;
	transform.matrix[0][1] = (points.p4.x - points.p1.x) / source_size.y;
	transform.matrix[0][2] = points.p1.x;
	transform.matrix[1][0] = (points.p2.y - points.p1.y) / source_size.x;
	transform.matrix[1][1] = (points.p4.y - points.p1.y) / source_size.y;
	transform.matrix[1][2] = points.p1.y;
	transform.color = color;
	return (transform);
}
