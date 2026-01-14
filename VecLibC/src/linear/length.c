/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:19:40 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:42:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../includes/modules/types/veclc_s_vecn.h"

double	vec2_length(t_vec2 p)
{
	return (sqrt(p.x * p.x + p.y * p.y));
}

double	vec2i_length(t_vec2i p)
{
	return (sqrt(p.x * p.x + p.y * p.y));
}

double	vec3_length(t_vec3 p)
{
	return (sqrt(p.x * p.x + p.y * p.y + p.z * p.z));
}

double	vec3i_length(t_vec3i p)
{
	return (sqrt(p.x * p.x + p.y * p.y + p.z * p.z));
}
