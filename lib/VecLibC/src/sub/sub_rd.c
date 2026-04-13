/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:50:09 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:42:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vecn.h"

t_vec2	vec2_sub_rd(double d, t_vec2 p)
{
	return ((t_vec2){.x = d - p.x, .y = d - p.y});
}

t_vec2i	vec2i_sub_rd(double d, t_vec2i p)
{
	return ((t_vec2i){.x = d - p.x, .y = d - p.y});
}

t_vec3	vec3_sub_rd(double d, t_vec3 p)
{
	return ((t_vec3){.x = d - p.x, .y = d - p.y, .z = d - p.z});
}

t_vec3i	vec3i_sub_rd(double d, t_vec3i p)
{
	return ((t_vec3i){.x = d - p.x, .y = d - p.y, .z = d - p.z});
}
