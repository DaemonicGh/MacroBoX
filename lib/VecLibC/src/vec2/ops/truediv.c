/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truediv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:39:19 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 23:04:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec2.h"

t_vec2	vec2i_truediv(t_vec2i p1, t_vec2i p2)
{
	return ((t_vec2){
		.x = (double)p1.x / p2.x,
		.y = (double)p1.y / p2.y,
	});
}

t_vec2	vec2i_truediv_d(t_vec2i p, double d)
{
	return ((t_vec2){
		.x = (double)p.x / d,
		.y = (double)p.y / d,
	});
}

t_vec2	vec2i_truediv_rd(double d, t_vec2i p)
{
	return ((t_vec2){
		.x = d / (double)p.x,
		.y = d / (double)p.y,
	});
}
