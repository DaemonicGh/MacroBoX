/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   average.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 22:55:57 by rprieur           #+#    #+#             */
/*   Updated: 2026/06/15 22:55:57 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_structs.h"
#include "modules/mbx_utils.h"

t_mbx_color	color_average(t_mbx_color col1, t_mbx_color col2)
{
	return ((t_mbx_color){
		.r = (col1.r + col2.r) / 2,
		.g = (col1.g + col2.g) / 2,
		.b = (col1.b + col2.b) / 2,
		.a = (col1.a + col2.a) / 2
	});
}

t_mbx_color	color_average_weighted(
	t_mbx_color col1, t_mbx_color col2, double weight_ratio)
{
	const double	total_weight = (weight_ratio + 1);

	return ((t_mbx_color){
		.r = (col1.r * weight_ratio + col2.r) / total_weight,
		.g = (col1.g * weight_ratio + col2.g) / total_weight,
		.b = (col1.b * weight_ratio + col2.b) / total_weight,
		.a = (col1.a * weight_ratio + col2.a) / total_weight
	});
}

t_mbx_color	color_lerp(
	t_mbx_color col1, t_mbx_color col2, double delta)
{
	const double	ndelta = 1 - delta;

	return ((t_mbx_color){
		.r = col1.r * ndelta + col2.r * delta,
		.g = col1.g * ndelta + col2.g * delta,
		.b = col1.b * ndelta + col2.b * delta,
		.a = col1.a * ndelta + col2.a * delta
	});
}
