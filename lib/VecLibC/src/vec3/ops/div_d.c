/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:48:50 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 18:30:09 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec3.h"

t_vec3	vec3_div_d(t_vec3 p, double d)
{
	return ((t_vec3){
		.x = p.x / d,
		.y = p.y / d,
		.z = p.z / d,
	});
}

t_vec3i	vec3i_div_d(t_vec3i p, double d)
{
	return ((t_vec3i){
		.x = p.x / d,
		.y = p.y / d,
		.z = p.z / d,
	});
}

t_vec3	vec3_div_rd(double d, t_vec3 p)
{
	return ((t_vec3){
		.x = d / p.x,
		.y = d / p.y,
		.z = d / p.z,
	});
}

t_vec3i	vec3i_div_rd(double d, t_vec3i p)
{
	return ((t_vec3i){
		.x = d / p.x,
		.y = d / p.y,
		.z = d / p.z,
	});
}
