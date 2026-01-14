/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_veci.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:24:52 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:42:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/types/veclc_s_vecn.h"

t_vec2i	vec2_to_vec2i(t_vec2 p)
{
	return ((t_vec2i){.x = p.x, .y = p.y});
}

t_vec3i	vec3_to_vec3i(t_vec3 p)
{
	return ((t_vec3i){.x = p.x, .y = p.y, .z = p.z});
}
