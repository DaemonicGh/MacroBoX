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

#include "modules/types/veclc_s_vec3.h"

double	vec3_dot(t_vec3 p1, t_vec3 p2)
{
	return (
		p1.x * p2.x
		+ p1.y * p2.y
		+ p1.z * p2.z
	);
}

double	vec3i_dot(t_vec3i p1, t_vec3i p2)
{
	return (
		p1.x * p2.x
		+ p1.y * p2.y
		+ p1.z * p2.z
	);
}
