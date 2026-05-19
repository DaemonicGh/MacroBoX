/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:23:44 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 18:28:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec2.h"
#include "modules/types/veclc_s_vec3.h"

t_vec2	vec3_xy(t_vec3 p)
{
	return ((t_vec2){
		.x = p.x,
		.y = p.y,
	});
}

t_vec2i	vec3i_xy(t_vec3i p)
{
	return ((t_vec2i){
		.x = p.x,
		.y = p.y,
	});
}
