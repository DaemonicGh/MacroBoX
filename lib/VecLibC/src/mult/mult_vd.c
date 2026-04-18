/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_vd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:16:44 by daemo             #+#    #+#             */
/*   Updated: 2026/04/13 02:09:39 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vecn.h"

t_vec2i	vec2i_mult_vd(t_vec2i p1, t_vec2 p2)
{
	return ((t_vec2i){.x = p1.x * p2.x, .y = p1.y * p2.y});
}

t_vec3i	vec3i_mult_vd(t_vec3i p1, t_vec3 p2)
{
	return ((t_vec3i){.x = p1.x * p2.x, .y = p1.y * p2.y, .z = p1.z * p2.z});
}
