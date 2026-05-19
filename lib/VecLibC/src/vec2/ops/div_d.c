/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:40:19 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 22:40:33 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec2.h"

t_vec2	vec2_div_d(t_vec2 p, double d)
{
	return ((t_vec2){
		.x = p.x / d,
		.y = p.y / d,
	});
}

t_vec2i	vec2i_div_d(t_vec2i p, double d)
{
	return ((t_vec2i){
		.x = p.x / d,
		.y = p.y / d,
	});
}

t_vec2	vec2_div_rd(double d, t_vec2 p)
{
	return ((t_vec2){
		.x = d / p.x,
		.y = d / p.y,
	});
}

t_vec2i	vec2i_div_rd(double d, t_vec2i p)
{
	return ((t_vec2i){
		.x = d / p.x,
		.y = d / p.y,
	});
}
