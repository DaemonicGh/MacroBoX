/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 03:51:01 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 23:04:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec3.h"

t_vec3i	vec3i_exec2(int (*f)(int, int), t_vec3i p1, t_vec3i p2)
{
	return ((t_vec3i){
		.x = f(p1.x, p2.x),
		.y = f(p1.y, p2.y),
		.z = f(p1.z, p2.z)
	});
}

t_vec3	vec3_exec2(double (*f) (double, double), t_vec3 p1, t_vec3 p2)
{
	return ((t_vec3){
		.x = f(p1.x, p2.x),
		.y = f(p1.y, p2.y),
		.z = f(p1.z, p2.z)
	});
}
