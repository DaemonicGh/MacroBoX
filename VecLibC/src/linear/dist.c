/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 01:16:24 by daemo             #+#    #+#             */
/*   Updated: 2026/01/14 22:49:01 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/veclc_vecn.h"

double	vec2_dist(t_vec2 p1, t_vec2 p2)
{
	return (vec2_length(vec2_sub(p1, p2)));
}

double	vec2i_dist(t_vec2i p1, t_vec2i p2)
{
	return (vec2i_length(vec2i_sub(p1, p2)));
}

double	vec3_dist(t_vec3 p1, t_vec3 p2)
{
	return (vec3_length(vec3_sub(p1, p2)));
}

double	vec3i_dist(t_vec3i p1, t_vec3i p2)
{
	return (vec3i_length(vec3i_sub(p1, p2)));
}
