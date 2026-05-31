/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:49:42 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 23:04:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec3.h"

t_vec3	vec3_mult_d(t_vec3 p, double d)
{
	return ((t_vec3){
		.x = p.x * d,
		.y = p.y * d,
		.z = p.z * d,
	});
}

t_vec3i	vec3i_mult_d(t_vec3i p, double d)
{
	return ((t_vec3i){
		.x = p.x * d,
		.y = p.y * d,
		.z = p.z * d,
	});
}
