/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 03:51:01 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 23:04:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec3.h"

t_vec3i	vec3i_exec(int (*f)(int), t_vec3i p)
{
	return ((t_vec3i){
		.x = f(p.x),
		.y = f(p.y),
		.z = f(p.z),
	});
}

t_vec3	vec3_exec(double (*f) (double), t_vec3 p)
{
	return ((t_vec3){
		.x = f(p.x),
		.y = f(p.y),
		.z = f(p.z),
	});
}
