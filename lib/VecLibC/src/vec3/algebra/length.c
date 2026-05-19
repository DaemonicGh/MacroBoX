/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:19:40 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 18:31:47 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "modules/types/veclc_s_vec3.h"

double	vec3_length(t_vec3 p)
{
	return (
		sqrt(
			p.x * p.x
			+ p.y * p.y
			+ p.z * p.z
		)
	);
}

double	vec3i_length(t_vec3i p)
{
	return (
		sqrt(
			p.x * p.x
			+ p.y * p.y
			+ p.z * p.z
		)
	);
}
