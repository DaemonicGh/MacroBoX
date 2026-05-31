/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 02:09:15 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 23:04:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "modules/types/veclc_s_vec3.h"

t_vec3	vec3_abs(t_vec3 p)
{
	return ((t_vec3){
		.x = fabs(p.x),
		.y = fabs(p.y),
		.z = fabs(p.z),
	});
}

t_vec3i	vec3i_abs(t_vec3i p)
{
	return ((t_vec3i){
		.x = abs(p.x),
		.y = abs(p.y),
		.z = abs(p.z),
	});
}
