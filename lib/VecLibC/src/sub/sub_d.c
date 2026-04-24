/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:50:09 by daemo             #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vecn.h"

t_vec2	vec2_sub_d(t_vec2 p, double d)
{
	return ((t_vec2){.x = p.x - d, .y = p.y - d});
}

t_vec2i	vec2i_sub_d(t_vec2i p, double d)
{
	return ((t_vec2i){.x = p.x - d, .y = p.y - d});
}

t_vec3	vec3_sub_d(t_vec3 p, double d)
{
	return ((t_vec3){.x = p.x - d, .y = p.y - d, .z = p.z - d});
}

t_vec3i	vec3i_sub_d(t_vec3i p, double d)
{
	return ((t_vec3i){.x = p.x - d, .y = p.y - d, .z = p.z - d});
}
