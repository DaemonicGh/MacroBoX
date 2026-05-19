/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:06:25 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 18:29:56 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec3.h"

t_vec3	vec3_add(t_vec3 p1, t_vec3 p2)
{
	return ((t_vec3){
		.x = p1.x + p2.x,
		.y = p1.y + p2.y,
		.z = p1.z + p2.z,
	});
}

t_vec3i	vec3i_add(t_vec3i p1, t_vec3i p2)
{
	return ((t_vec3i){
		.x = p1.x + p2.x,
		.y = p1.y + p2.y,
		.z = p1.z + p2.z,
	});
}

t_vec3	vec3_add_d(t_vec3 p, double d)
{
	return ((t_vec3){
		.x = p.x + d,
		.y = p.y + d,
		.z = p.z + d,
	});
}

t_vec3i	vec3i_add_d(t_vec3i p, double d)
{
	return ((t_vec3i){
		.x = p.x + d,
		.y = p.y + d,
		.z = p.z + d,
	});
}
