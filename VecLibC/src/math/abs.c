/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 02:09:15 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:42:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "../../includes/modules/types/veclc_s_vecn.h"

t_vec2	vec2_abs(t_vec2 p)
{
	return ((t_vec2){.x = fabs(p.x), .y = fabs(p.y)});
}

t_vec2i	vec2i_abs(t_vec2i p)
{
	return ((t_vec2i){.x = abs(p.x), .y = abs(p.y)});
}

t_vec3	vec3_abs(t_vec3 p)
{
	return ((t_vec3){.x = fabs(p.x), .y = fabs(p.y), .z = fabs(p.z)});
}

t_vec3i	vec3i_abs(t_vec3i p)
{
	return ((t_vec3i){.x = abs(p.x), .y = abs(p.y), .z = abs(p.z)});
}
