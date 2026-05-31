/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 02:09:15 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 23:04:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "modules/types/veclc_s_vec2.h"

t_vec2	vec2_mod(t_vec2 p1, t_vec2 p2)
{
	return ((t_vec2){
		.x = fmod(p1.x, p2.x),
		.y = fmod(p1.y, p2.y),
	});
}

t_vec2i	vec2i_mod(t_vec2i p1, t_vec2i p2)
{
	return ((t_vec2i){
		.x = p1.x % p2.x,
		.y = p1.y % p2.y,
	});
}
