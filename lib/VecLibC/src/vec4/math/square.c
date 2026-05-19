/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 01:59:08 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 22:40:30 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec4.h"

t_vec4	vec4_square(t_vec4 p)
{
	return ((t_vec4){
		.x = p.x * p.x,
		.y = p.y * p.y,
		.z = p.z * p.z,
		.w = p.w * p.w});
}

t_vec4i	vec4i_square(t_vec4i p)
{
	return ((t_vec4i){
		.x = p.x * p.x,
		.y = p.y * p.y,
		.z = p.z * p.z,
		.w = p.w * p.w});
}
