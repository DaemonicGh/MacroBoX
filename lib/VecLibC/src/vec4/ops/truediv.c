/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truediv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:16:44 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 22:40:30 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec4.h"

t_vec4	vec4i_truediv(t_vec4i p1, t_vec4i p2)
{
	return ((t_vec4){
		.x = (double)p1.x / p2.x,
		.y = (double)p1.y / p2.y,
		.z = (double)p1.z / p2.z,
		.w = (double)p1.w / p2.w,
	});
}

t_vec4	vec4i_truediv_d(t_vec4i p, double d)
{
	return ((t_vec4){
		.x = (double)p.x / d,
		.y = (double)p.y / d,
		.z = (double)p.z / d,
		.w = (double)p.w / d,
	});
}

t_vec4	vec4i_truediv_rd(double d, t_vec4i p)
{
	return ((t_vec4){
		.x = d / (double)p.x,
		.y = d / (double)p.y,
		.z = d / (double)p.z,
		.w = d / (double)p.w,
	});
}
