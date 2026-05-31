/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truediv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:16:44 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 23:04:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec3.h"

t_vec3	vec3i_truediv(t_vec3i p1, t_vec3i p2)
{
	return ((t_vec3){
		.x = (double)p1.x / p2.x,
		.y = (double)p1.y / p2.y,
		.z = (double)p1.z / p2.z
	});
}

t_vec3	vec3i_truediv_d(t_vec3i p, double d)
{
	return ((t_vec3){
		.x = (double)p.x / d,
		.y = (double)p.y / d,
		.z = (double)p.z / d
	});
}

t_vec3	vec3i_truediv_rd(double d, t_vec3i p)
{
	return ((t_vec3){
		.x = d / (double)p.x,
		.y = d / (double)p.y,
		.z = d / (double)p.z
	});
}
