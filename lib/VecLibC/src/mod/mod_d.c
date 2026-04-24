/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 02:09:15 by daemo             #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "modules/types/veclc_s_vecn.h"

t_vec2	vec2_mod_d(t_vec2 p, double d)
{
	return ((t_vec2){.x = fmod(p.x, d), .y = fmod(p.y, d)});
}

t_vec2i	vec2i_mod_d(t_vec2i p, double d)
{
	return ((t_vec2i){.x = fmod(p.x, d), .y = fmod(p.y, d)});
}

t_vec3	vec3_mod_d(t_vec3 p, double d)
{
	return ((t_vec3){
		.x = fmod(p.x, d),
		.y = fmod(p.y, d),
		.z = fmod(p.z, d)
	});
}

t_vec3i	vec3i_mod_d(t_vec3i p, double d)
{
	return ((t_vec3i){
		.x = fmod(p.x, d),
		.y = fmod(p.y, d),
		.z = fmod(p.z, d)
	});
}
