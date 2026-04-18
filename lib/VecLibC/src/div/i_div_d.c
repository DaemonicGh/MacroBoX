/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_div_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:51:28 by daemo             #+#    #+#             */
/*   Updated: 2026/04/13 02:42:58 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vecn.h"

t_vec2i	vec2i_div_d(t_vec2i p, double d)
{
	return ((t_vec2i){.x = p.x / d, .y = p.y / d});
}

t_vec2i	vec2i_div_rd(double d, t_vec2i p)
{
	return ((t_vec2i){.x = d / p.x, .y = d / p.y});
}

t_vec3i	vec3i_div_d(t_vec3i p, double d)
{
	return ((t_vec3i){.x = p.x / d, .y = p.y / d, .z = p.z / d});
}

t_vec3i	vec3i_div_rd(double d, t_vec3i p)
{
	return ((t_vec3i){.x = d / p.x, .y = d / p.y, .z = d / p.z});
}
