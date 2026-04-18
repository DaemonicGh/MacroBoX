/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_rd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 02:09:15 by daemo             #+#    #+#             */
/*   Updated: 2026/04/13 02:43:49 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "modules/types/veclc_s_vecn.h"

t_vec2	vec2_mod_rd(double d, t_vec2 p)
{
	return ((t_vec2){.x = fmod(d, p.x), .y = fmod(d, p.y)});
}

t_vec2i	vec2i_mod_rd(double d, t_vec2i p)
{
	return ((t_vec2i){.x = fmod(d, p.x), .y = fmod(d, p.y)});
}

t_vec3	vec3_mod_rd(double d, t_vec3 p)
{
	return ((t_vec3){
		.x = fmod(d, p.x),
		.y = fmod(d, p.y),
		.z = fmod(d, p.z)
	});
}

t_vec3i	vec3i_mod_rd(double d, t_vec3i p)
{
	return ((t_vec3i){
		.x = fmod(d, p.x),
		.y = fmod(d, p.y),
		.z = fmod(d, p.z)
	});
}
