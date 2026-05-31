/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 02:09:15 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 23:04:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "modules/types/veclc_s_vec3.h"

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
