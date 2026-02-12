/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truediv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:16:44 by daemo             #+#    #+#             */
/*   Updated: 2026/02/05 04:58:35 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vecn.h"

t_vec2	vec2i_truediv(t_vec2i p1, t_vec2i p2)
{
	return ((t_vec2){.x = (double)p1.x / p2.x, .y = (double)p1.y / p2.y});
}

t_vec3	vec3i_truediv(t_vec3i p1, t_vec3i p2)
{
	return ((t_vec3){
		.x = (double)p1.x / p2.x,
		.y = (double)p1.y / p2.y,
		.z = (double)p1.z / p2.z
	});
}

t_vec2	vec2i_truediv_d(t_vec2i p, double value)
{
	return ((t_vec2){.x = (double)p.x / value, .y = (double)p.y / value});
}

t_vec3	vec3i_truediv_d(t_vec3i p, double value)
{
	return ((t_vec3){
		.x = (double)p.x / value,
		.y = (double)p.y / value,
		.z = (double)p.z / value
	});
}
