/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_xyz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 03:51:01 by rprieur           #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vecn.h"

int	vec3i_exec_xyz(int (*f)(int, int, int), t_vec3i p1)
{
	return (f(p1.x, p1.y, p1.z));
}

double	vec3_exec_xyz(double (*f) (double, double, double), t_vec3 p1)
{
	return (f(p1.x, p1.y, p1.z));
}

int	vec3i_exec_xy_yz(int (*f)(int, int), t_vec3i p1)
{
	return (f(f(p1.x, p1.y), p1.z));
}

double	vec3_exec_xy_yz(double (*f) (double, double), t_vec3 p1)
{
	return (f(f(p1.x, p1.y), p1.z));
}
