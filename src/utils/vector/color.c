/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:43:48 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/19 00:43:48 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/mbx_s_color.h"
#include "modules/mbx_utils.h"

t_vec4	vec4_from_color(t_mbx_color	col)
{
	return ((t_vec4){
		.r = col.r / 255.0,
		.g = col.g / 255.0,
		.b = col.b / 255.0,
		.a = col.a / 255.0
	});
}

t_mbx_color	vec4_to_color(t_vec4 p)
{
	return ((t_mbx_color){
		.r = p.r * 255.0,
		.g = p.g * 255.0,
		.b = p.b * 255.0,
		.a = p.a * 255.0
	});
}

t_vec4i	vec4i_from_color(t_mbx_color col)
{
	return ((t_vec4i){
		.r = col.r,
		.g = col.g,
		.b = col.b,
		.a = col.a
	});
}

t_mbx_color	vec4i_to_color(t_vec4i p)
{
	return ((t_mbx_color){
		.r = p.r,
		.g = p.g,
		.b = p.b,
		.a = p.a
	});
}
