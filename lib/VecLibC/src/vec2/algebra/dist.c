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

#include "modules/veclc_vec2.h"
#include "modules/veclc_vec2i.h"

double	vec2_dist(t_vec2 p1, t_vec2 p2)
{
	return (vec2_length(vec2_sub(p1, p2)));
}

double	vec2i_dist(t_vec2i p1, t_vec2i p2)
{
	return (vec2i_length(vec2i_sub(p1, p2)));
}
