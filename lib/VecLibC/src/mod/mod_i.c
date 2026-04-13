/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 02:09:15 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:42:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "modules/types/veclc_s_vecn.h"

t_vec2i	vec2i_mod_i(t_vec2i p, int i)
{
	return ((t_vec2i){.x = p.x % i, .y = p.y % i});
}

t_vec2i	vec2i_mod_ri(int i, t_vec2i p)
{
	return ((t_vec2i){.x = i % p.x, .y = i % p.y});
}

t_vec3i	vec3i_mod_i(t_vec3i p, int i)
{
	return ((t_vec3i){
		.x = p.x % i,
		.y = p.y % i,
		.z = p.z % i
	});
}

t_vec3i	vec3i_mod_ri(int i, t_vec3i p)
{
	return ((t_vec3i){
		.x = i % p.x,
		.y = i % p.y,
		.z = i % p.z
	});
}
