/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 02:09:15 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 23:04:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "modules/types/veclc_s_vec2.h"

t_vec2	vec2_mod_d(t_vec2 p, double d)
{
	return ((t_vec2){
		.x = fmod(p.x, d),
		.y = fmod(p.y, d),
	});
}

t_vec2i	vec2i_mod_d(t_vec2i p, double d)
{
	return ((t_vec2i){
		.x = fmod(p.x, d),
		.y = fmod(p.y, d),
	});
}

t_vec2	vec2_mod_rd(double d, t_vec2 p)
{
	return ((t_vec2){
		.x = fmod(d, p.x),
		.y = fmod(d, p.y),
	});
}

t_vec2i	vec2i_mod_rd(double d, t_vec2i p)
{
	return ((t_vec2i){
		.x = fmod(d, p.x),
		.y = fmod(d, p.y),
	});
}
