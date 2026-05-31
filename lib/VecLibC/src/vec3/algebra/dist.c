/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 01:16:24 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 23:04:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/veclc_vec3.h"
#include "modules/veclc_vec3i.h"

double	vec3_dist(t_vec3 p1, t_vec3 p2)
{
	return (vec3_length(vec3_sub(p1, p2)));
}

double	vec3i_dist(t_vec3i p1, t_vec3i p2)
{
	return (vec3i_length(vec3i_sub(p1, p2)));
}
