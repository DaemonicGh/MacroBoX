/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:06:25 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:42:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/types/veclc_s_vecn.h"

t_vec2	vec2_add(t_vec2 p1, t_vec2 p2)
{
	return ((t_vec2){.x = p1.x + p2.x, .y = p1.y + p2.y});
}

t_vec2i	vec2i_add(t_vec2i p1, t_vec2i p2)
{
	return ((t_vec2i){.x = p1.x + p2.x, .y = p1.y + p2.y});
}

t_vec3	vec3_add(t_vec3 p1, t_vec3 p2)
{
	return ((t_vec3){.x = p1.x + p2.x, .y = p1.y + p2.y, .z = p1.z + p2.z});
}

t_vec3i	vec3i_add(t_vec3i p1, t_vec3i p2)
{
	return ((t_vec3i){.x = p1.x + p2.x, .y = p1.y + p2.y, .z = p1.z + p2.z});
}
