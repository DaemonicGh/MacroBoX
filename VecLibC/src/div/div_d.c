/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:48:50 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:42:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/types/veclc_s_vecn.h"

t_vec2	vec2_div_d(t_vec2 p, double value)
{
	return ((t_vec2){.x = p.x / value, .y = p.y / value});
}

t_vec3	vec3_div_d(t_vec3 p, double value)
{
	return ((t_vec3){.x = p.x / value, .y = p.y / value, .z = p.z / value});
}
