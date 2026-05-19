/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:17:12 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 17:34:37 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_all.h"

t_vec2	vec2_sign(t_vec2 p)
{
	return ((t_vec2){.x = (p.x > 0) - (p.x < 0), .y = (p.y > 0) - (p.y < 0)});
}

t_vec2i	vec2i_sign(t_vec2i p)
{
	return ((t_vec2i){.x = (p.x > 0) - (p.x < 0), .y = (p.y > 0) - (p.y < 0)});
}

t_vec3	vec3_sign(t_vec3 p)
{
	return ((t_vec3){
		.x = (p.x > 0) - (p.x < 0),
		.y = (p.y > 0) - (p.y < 0),
		.z = (p.z > 0) - (p.z < 0)
	});
}

t_vec3i	vec3i_sign(t_vec3i p)
{
	return ((t_vec3i){
		.x = (p.x > 0) - (p.x < 0),
		.y = (p.y > 0) - (p.y < 0),
		.z = (p.z > 0) - (p.z < 0)
	});
}
