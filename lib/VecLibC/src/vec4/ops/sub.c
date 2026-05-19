/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:07:26 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 22:40:30 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec4.h"

t_vec4	vec4_sub(t_vec4 p1, t_vec4 p2)
{
	return ((t_vec4){
		.x = p1.x - p2.x,
		.y = p1.y - p2.y,
		.z = p1.z - p2.z,
		.w = p1.w - p2.w,
	});
}

t_vec4i	vec4i_sub(t_vec4i p1, t_vec4i p2)
{
	return ((t_vec4i){
		.x = p1.x - p2.x,
		.y = p1.y - p2.y,
		.z = p1.z - p2.z,
		.w = p1.w - p2.w,
	});
}
