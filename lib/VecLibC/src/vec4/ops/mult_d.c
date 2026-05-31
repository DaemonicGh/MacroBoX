/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:49:42 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 23:04:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec4.h"

t_vec4	vec4_mult_d(t_vec4 p, double d)
{
	return ((t_vec4){
		.x = p.x * d,
		.y = p.y * d,
		.z = p.z * d,
		.w = p.w * d,
	});
}

t_vec4i	vec4i_mult_d(t_vec4i p, double d)
{
	return ((t_vec4i){
		.x = p.x * d,
		.y = p.y * d,
		.z = p.z * d,
		.w = p.w * d,
	});
}
