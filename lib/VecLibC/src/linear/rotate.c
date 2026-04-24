/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:21:33 by daemo             #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "modules/types/veclc_s_vecn.h"

t_vec2	vec2_rotate(t_vec2 p, double radians)
{
	const double	c = cos(radians);
	const double	s = sin(radians);

	return ((t_vec2){
		.x = p.x * c - p.y * s,
		.y = p.x * s + p.y * c
	});
}

t_vec2i	vec2i_rotate(t_vec2i p, double radians)
{
	const double	c = cos(radians);
	const double	s = sin(radians);

	return ((t_vec2i){
		.x = p.x * c - p.y * s,
		.y = p.x * s + p.y * c
	});
}
