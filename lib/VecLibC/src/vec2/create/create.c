/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:04:36 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 23:04:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec2.h"

t_vec2	vec2(double x, double y)
{
	return ((t_vec2){
		.x = x,
		.y = y,
	});
}

t_vec2i	vec2i(int x, int y)
{
	return ((t_vec2i){
		.x = x,
		.y = y,
	});
}

t_vec2	vec2_d(double xy)
{
	return ((t_vec2){
		.x = xy,
		.y = xy,
	});
}

t_vec2i	vec2i_i(int xy)
{
	return ((t_vec2i){
		.x = xy,
		.y = xy,
	});
}
