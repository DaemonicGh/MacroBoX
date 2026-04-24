/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:04:36 by daemo             #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vecn.h"

t_vec2	vec2_d(double xy)
{
	return ((t_vec2){.x = xy, .y = xy});
}

t_vec2i	vec2i_i(int xy)
{
	return ((t_vec2i){.x = xy, .y = xy});
}

t_vec3	vec3_d(double xyz)
{
	return ((t_vec3){.x = xyz, .y = xyz, .z = xyz});
}

t_vec3i	vec3i_i(int xyz)
{
	return ((t_vec3i){.x = xyz, .y = xyz, .z = xyz});
}
