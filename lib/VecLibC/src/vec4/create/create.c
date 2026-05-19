/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:04:36 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 22:40:30 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec4.h"

t_vec4	vec4(double x, double y, double z, double w)
{
	return ((t_vec4){
		.x = x,
		.y = y,
		.z = z,
		.w = w,
	});
}

t_vec4i	vec4i(int x, int y, int z, int w)
{
	return ((t_vec4i){
		.x = x,
		.y = y,
		.z = z,
		.w = w,
	});
}

t_vec4	vec4_d(double xyzw)
{
	return ((t_vec4){
		.x = xyzw,
		.y = xyzw,
		.z = xyzw,
		.w = xyzw,
	});
}

t_vec4i	vec4i_i(int xyzw)
{
	return ((t_vec4i){
		.x = xyzw,
		.y = xyzw,
		.z = xyzw,
		.w = xyzw,
	});
}
