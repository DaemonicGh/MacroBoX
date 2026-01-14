/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:56:59 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:42:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/types/veclc_s_vecn.h"

t_vec3	vec3_cross(t_vec3 p1, t_vec3 p2)
{
	return ((t_vec3){
		.x = p1.y * p2.z - p1.z * p2.y,
		.y = p1.z * p2.x - p1.x * p2.z,
		.z = p1.x * p2.y - p1.y * p2.x
	});
}

t_vec3i	vec3i_cross(t_vec3i p1, t_vec3i p2)
{
	return ((t_vec3i){
		.x = p1.y * p2.z - p1.z * p2.y,
		.y = p1.z * p2.x - p1.x * p2.z,
		.z = p1.x * p2.y - p1.y * p2.x
	});
}
