/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:09:38 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:42:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../includes/modules/types/veclc_s_vecn.h"

t_vec2i	vec2_round(t_vec2 p)
{
	return ((t_vec2i){.x = round(p.x), .y = round(p.y)});
}

t_vec3i	vec3_round(t_vec3 p)
{
	return ((t_vec3i){.x = round(p.x), .y = round(p.y), .z = round(p.z)});
}
