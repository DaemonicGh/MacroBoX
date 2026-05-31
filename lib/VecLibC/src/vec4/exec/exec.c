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

#include "modules/types/veclc_s_vec4.h"

t_vec4	vec4_exec(double (*f) (double), t_vec4 p)
{
	return ((t_vec4){
		.x = f(p.x),
		.y = f(p.y),
		.z = f(p.z),
		.w = f(p.w),
	});
}

t_vec4i	vec4i_exec(int (*f)(int), t_vec4i p)
{
	return ((t_vec4i){
		.x = f(p.x),
		.y = f(p.y),
		.z = f(p.z),
		.w = f(p.w),
	});
}
