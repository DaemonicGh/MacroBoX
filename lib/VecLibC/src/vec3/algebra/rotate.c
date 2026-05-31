/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 23:03:55 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 23:39:49 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "modules/veclc_vec3.h"

t_vec3	vec3_rotate_axis(t_vec3 p, t_vec3 axis, double radians)
{
	const double	c = cos(radians);
	const double	s = sin(radians);

	return (
		vec3_add(
			vec3_add(
				vec3_mult_d(p, c),
				vec3_mult_d(vec3_cross(axis, p), s)),
			vec3_mult_d(axis, vec3_dot(axis, p) * (1.0 - c))
		)
	);
}

t_vec3	vec3_rotate(t_vec3 p, t_vec3 up, double pitch_rad, double yaw_rad)
{
	t_vec3	right;

	p = vec3_rotate_axis(p, up, yaw_rad);
	right = vec3_cross(p, up);
	p = vec3_rotate_axis(p, right, pitch_rad);
	return (p);
}
