/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:49:42 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:42:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vecn.h"

t_vec2	vec2_mult_d(t_vec2 p, double value)
{
	return ((t_vec2){.x = p.x * value, .y = p.y * value});
}

t_vec2i	vec2i_mult_d(t_vec2i p, double value)
{
	return ((t_vec2i){.x = p.x * value, .y = p.y * value});
}

t_vec3	vec3_mult_d(t_vec3 p, double value)
{
	return ((t_vec3){.x = p.x * value, .y = p.y * value, .z = p.z * value});
}

t_vec3i	vec3i_mult_d(t_vec3i p, double value)
{
	return ((t_vec3i){.x = p.x * value, .y = p.y * value, .z = p.z * value});
}
