/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecx2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 22:53:39 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 22:40:33 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec2xn.h"

t_vec2x2	vec2x2(t_vec2 p1, t_vec2 p2)
{
	return ((t_vec2x2){
		.p1 = p1,
		.p2 = p2,
	});
}

t_vec2ix2	vec2ix2(t_vec2i p1, t_vec2i p2)
{
	return ((t_vec2ix2){
		.p1 = p1,
		.p2 = p2,
	});
}

t_vec2x2	vec2x2_xy(double x1, double y1, double x2, double y2)
{
	return ((t_vec2x2){
		.p1 = vec2(x1, y1),
		.p2 = vec2(x2, y2),
	});
}

t_vec2ix2	vec2ix2_xy(int x1, int y1, int x2, int y2)
{
	return ((t_vec2ix2){
		.p1 = vec2i(x1, y1),
		.p2 = vec2i(x2, y2),
	});
}
