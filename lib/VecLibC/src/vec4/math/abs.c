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
#include "modules/types/veclc_s_vec4.h"

t_vec4	vec4_abs(t_vec4 p)
{
	return ((t_vec4){
		.x = fabs(p.x),
		.y = fabs(p.y),
		.z = fabs(p.z),
		.w = fabs(p.w),
	});
}

t_vec4i	vec4i_abs(t_vec4i p)
{
	return ((t_vec4i){
		.x = abs(p.x),
		.y = abs(p.y),
		.z = abs(p.z),
		.w = abs(p.w),
	});
}
