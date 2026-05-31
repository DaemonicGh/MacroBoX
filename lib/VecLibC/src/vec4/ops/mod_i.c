/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 02:09:15 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 23:04:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec4.h"

t_vec4i	vec4i_mod_i(t_vec4i p, int i)
{
	return ((t_vec4i){
		.x = p.x % i,
		.y = p.y % i,
		.z = p.z % i,
		.w = p.w % i,
	});
}

t_vec4i	vec4i_mod_ri(int i, t_vec4i p)
{
	return ((t_vec4i){
		.x = i % p.x,
		.y = i % p.y,
		.z = i % p.z,
		.w = i % p.w,
	});
}
