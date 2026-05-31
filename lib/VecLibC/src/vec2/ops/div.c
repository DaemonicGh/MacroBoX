/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:38:22 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 23:04:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec2.h"

t_vec2	vec2_div(t_vec2 p1, t_vec2 p2)
{
	return ((t_vec2){
		.x = p1.x / p2.x,
		.y = p1.y / p2.y,
	});
}

t_vec2i	vec2i_div(t_vec2i p1, t_vec2i p2)
{
	return ((t_vec2i){
		.x = p1.x / p2.x,
		.y = p1.y / p2.y,
	});
}

t_vec2i	vec2i_div_vd(t_vec2i p1, t_vec2 p2)
{
	return ((t_vec2i){
		.x = p1.x / p2.x,
		.y = p1.y / p2.y,
	});
}

t_vec2i	vec2i_div_rvd(t_vec2 p1, t_vec2i p2)
{
	return ((t_vec2i){
		.x = p1.x / p2.x,
		.y = p1.y / p2.y,
	});
}
