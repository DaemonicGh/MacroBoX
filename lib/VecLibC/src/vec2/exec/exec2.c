/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 03:51:01 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 22:40:33 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec2.h"

t_vec2	vec2_exec2(double (*f) (double, double), t_vec2 p1, t_vec2 p2)
{
	return ((t_vec2){
		.x = f(p1.x, p2.x),
		.y = f(p1.y, p2.y),
	});
}

t_vec2i	vec2i_exec2(int (*f)(int, int), t_vec2i p1, t_vec2i p2)
{
	return ((t_vec2i){
		.x = f(p1.x, p2.x),
		.y = f(p1.y, p2.y),
	});
}
