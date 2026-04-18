/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_angle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:42:26 by rprieur           #+#    #+#             */
/*   Updated: 2026/03/06 16:30:34 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "modules/types/veclc_s_vecn.h"

t_vec2	vec2_from_angle(double radians)
{
	return ((t_vec2){.x = sin(radians), .y = cos(radians)});
}

t_vec3	vec3_from_angle(t_vec2 pitch_yaw_rad)
{
	const double	xzl = cos(pitch_yaw_rad.x);

	return ((t_vec3){
		.x = xzl * cos(pitch_yaw_rad.y),
		.y = sin(pitch_yaw_rad.x),
		.z = xzl * sin(-pitch_yaw_rad.y)
	});
}
