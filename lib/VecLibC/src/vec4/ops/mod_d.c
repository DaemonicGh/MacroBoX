/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 02:09:15 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 22:40:30 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "modules/types/veclc_s_vec4.h"

t_vec4	vec4_mod_d(t_vec4 p, double d)
{
	return ((t_vec4){
		.x = fmod(p.x, d),
		.y = fmod(p.y, d),
		.z = fmod(p.z, d),
		.w = fmod(p.w, d),
	});
}

t_vec4i	vec4i_mod_d(t_vec4i p, double d)
{
	return ((t_vec4i){
		.x = fmod(p.x, d),
		.y = fmod(p.y, d),
		.z = fmod(p.z, d),
		.w = fmod(p.w, d),
	});
}

t_vec4	vec4_mod_rd(double d, t_vec4 p)
{
	return ((t_vec4){
		.x = fmod(d, p.x),
		.y = fmod(d, p.y),
		.z = fmod(d, p.z),
		.w = fmod(d, p.w),
	});
}

t_vec4i	vec4i_mod_rd(double d, t_vec4i p)
{
	return ((t_vec4i){
		.x = fmod(d, p.x),
		.y = fmod(d, p.y),
		.z = fmod(d, p.z),
		.w = fmod(d, p.w),
	});
}
