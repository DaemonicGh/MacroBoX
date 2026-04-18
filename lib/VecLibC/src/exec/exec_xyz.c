/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_xyz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 03:51:01 by rprieur           #+#    #+#             */
/*   Updated: 2026/04/18 03:51:01 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vecn.h"

int	vec3i_exec_xyz(t_vec3i p1, int (*f)(int, int, int))
{
	return (f(p1.x, p1.y, p1.z));
}

double	vec3_exec_xyz(t_vec3 p1, double (*f) (double, double, double))
{
	return (f(p1.x, p1.y, p1.z));
}

int	vec3i_exec_xy_yz(t_vec3i p1, int (*f)(int, int))
{
	return (f(f(p1.x, p1.y), p1.z));
}

double	vec3_exec_xy_yz(t_vec3 p1, double (*f) (double, double))
{
	return (f(f(p1.x, p1.y), p1.z));
}
