/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:23:44 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 23:04:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec2.h"
#include "modules/types/veclc_s_vec3.h"
#include "modules/types/veclc_s_vec4.h"

t_vec2	vec4_xy(t_vec4 p)
{
	return ((t_vec2){
		.x = p.x,
		.y = p.y,
	});
}

t_vec2i	vec4i_xy(t_vec4i p)
{
	return ((t_vec2i){
		.x = p.x,
		.y = p.y,
	});
}

t_vec3	vec4_xyz(t_vec4 p)
{
	return ((t_vec3){
		.x = p.x,
		.y = p.y,
		.z = p.z,
	});
}

t_vec3i	vec4i_xyz(t_vec4i p)
{
	return ((t_vec3i){
		.x = p.x,
		.y = p.y,
		.z = p.z,
	});
}
