/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:04:36 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 18:28:13 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec3.h"

t_vec3	vec3(double x, double y, double z)
{
	return ((t_vec3){
		.x = x,
		.y = y,
		.z = z,
	});
}

t_vec3i	vec3i(int x, int y, int z)
{
	return ((t_vec3i){
		.x = x,
		.y = y,
		.z = z,
	});
}

t_vec3	vec3_d(double xyz)
{
	return ((t_vec3){
		.x = xyz,
		.y = xyz,
		.z = xyz,
	});
}

t_vec3i	vec3i_i(int xyz)
{
	return ((t_vec3i){
		.x = xyz,
		.y = xyz,
		.z = xyz,
	});
}
