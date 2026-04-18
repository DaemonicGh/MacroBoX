/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truediv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:16:44 by daemo             #+#    #+#             */
/*   Updated: 2026/04/13 02:43:08 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vecn.h"

t_vec2	vec2i_truediv_d(t_vec2i p, double d)
{
	return ((t_vec2){.x = (double)p.x / d, .y = (double)p.y / d});
}

t_vec3	vec3i_truediv_d(t_vec3i p, double d)
{
	return ((t_vec3){
		.x = (double)p.x / d,
		.y = (double)p.y / d,
		.z = (double)p.z / d
	});
}

t_vec2	vec2i_truediv_rd(double d, t_vec2i p)
{
	return ((t_vec2){.x = d / (double)p.x, .y = d / (double)p.y});
}

t_vec3	vec3i_truediv_rd(double d, t_vec3i p)
{
	return ((t_vec3){
		.x = d / (double)p.x,
		.y = d / (double)p.y,
		.z = d / (double)p.z
	});
}
