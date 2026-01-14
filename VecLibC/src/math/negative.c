/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:16:23 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:42:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/types/veclc_s_vecn.h"

t_vec2	vec2_neg(t_vec2 p)
{
	return ((t_vec2){.x = -p.x, .y = -p.y});
}

t_vec2i	vec2i_neg(t_vec2i p)
{
	return ((t_vec2i){.x = -p.x, .y = -p.y});
}

t_vec3	vec3_neg(t_vec3 p)
{
	return ((t_vec3){.x = -p.x, .y = -p.y, .z = -p.z});
}

t_vec3i	vec3i_neg(t_vec3i p)
{
	return ((t_vec3i){.x = -p.x, .y = -p.y, .z = -p.z});
}
