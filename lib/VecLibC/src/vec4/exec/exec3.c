/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 03:51:01 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 22:40:30 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec4.h"

t_vec4	vec4_exec3(double (*f) (double, double, double),
			t_vec4 p1, t_vec4 p2, t_vec4 p3)
{
	return ((t_vec4){
		.x = f(p1.x, p2.x, p3.x),
		.y = f(p1.y, p2.y, p3.y),
		.z = f(p1.z, p2.z, p3.z),
		.w = f(p1.w, p2.w, p3.w),
	});
}

t_vec4i	vec4i_exec3(int (*f)(int, int, int),
			t_vec4i p1, t_vec4i p2, t_vec4i p3)
{
	return ((t_vec4i){
		.x = f(p1.x, p2.x, p3.x),
		.y = f(p1.y, p2.y, p3.y),
		.z = f(p1.z, p2.z, p3.z),
		.w = f(p1.w, p2.w, p3.w),
	});
}
