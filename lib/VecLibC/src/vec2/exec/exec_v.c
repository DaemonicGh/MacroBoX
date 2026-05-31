/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:43:29 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 23:04:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec2.h"

double	vec2_exec_xy(double (*f) (double, double), t_vec2 p1)
{
	return (f(p1.x, p1.y));
}

int	vec2i_exec_xy(int (*f)(int, int), t_vec2i p1)
{
	return (f(p1.x, p1.y));
}
