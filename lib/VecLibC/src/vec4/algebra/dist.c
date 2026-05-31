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

#include "modules/veclc_vec4.h"
#include "modules/veclc_vec4i.h"

double	vec4_dist(t_vec4 p1, t_vec4 p2)
{
	return (vec4_length(vec4_sub(p1, p2)));
}

double	vec4i_dist(t_vec4i p1, t_vec4i p2)
{
	return (vec4i_length(vec4i_sub(p1, p2)));
}
