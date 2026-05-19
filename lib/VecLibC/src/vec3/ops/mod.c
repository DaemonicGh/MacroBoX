/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 02:09:15 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 18:10:55 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "modules/types/veclc_s_vec3.h"

t_vec3	vec3_mod(t_vec3 p1, t_vec3 p2)
{
	return ((t_vec3){
		.x = fmod(p1.x, p2.x),
		.y = fmod(p1.y, p2.y),
		.z = fmod(p1.z, p2.z)
	});
}

t_vec3i	vec3i_mod(t_vec3i p1, t_vec3i p2)
{
	return ((t_vec3i){
		.x = p1.x % p2.x,
		.y = p1.y % p2.y,
		.z = p1.z % p2.z
	});
}
