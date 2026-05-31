/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 22:02:44 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 23:04:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec4.h"

double	vec4_dot(t_vec4 p1, t_vec4 p2)
{
	return (
		p1.x * p2.x
		+ p1.y * p2.y
		+ p1.z * p2.z
		+ p1.w * p2.w
	);
}

double	vec4i_dot(t_vec4i p1, t_vec4i p2)
{
	return (
		p1.x * p2.x
		+ p1.y * p2.y
		+ p1.z * p2.z
		+ p1.w * p2.w
	);
}
