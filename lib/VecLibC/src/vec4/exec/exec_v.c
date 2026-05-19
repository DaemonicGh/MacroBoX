/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 03:51:01 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 22:40:30 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec4.h"

double	vec4_exec_xyzw(double (*f) (double, double, double, double), t_vec4 p1)
{
	return (f(p1.x, p1.y, p1.z, p1.w));
}

int	vec4i_exec_xyzw(int (*f)(int, int, int, int), t_vec4i p1)
{
	return (f(p1.x, p1.y, p1.z, p1.w));
}

double	vec4_exec_xy_zw(double (*f) (double, double), t_vec4 p1)
{
	return (f(f(p1.x, p1.y), f(p1.z, p1.w)));
}

int	vec4i_exec_xy_zw(int (*f)(int, int), t_vec4i p1)
{
	return (f(f(p1.x, p1.y), f(p1.z, p1.w)));
}
