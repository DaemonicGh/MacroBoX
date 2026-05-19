/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 01:59:08 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 18:29:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec3.h"

t_vec3	vec3_square(t_vec3 p)
{
	return ((t_vec3){
		.x = p.x * p.x,
		.y = p.y * p.y,
		.z = p.z * p.z,
	});
}

t_vec3i	vec3i_square(t_vec3i p)
{
	return ((t_vec3i){
		.x = p.x * p.x,
		.y = p.y * p.y,
		.z = p.z * p.z,
	});
}
