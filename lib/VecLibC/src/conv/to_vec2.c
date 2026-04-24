/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_vec2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:23:44 by rprieur           #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vecn.h"

t_vec2i	vec3i_xy(t_vec3i p)
{
	return ((t_vec2i){.x = p.x, .y = p.y});
}

t_vec2i	vec3i_yz(t_vec3i p)
{
	return ((t_vec2i){.x = p.y, .y = p.z});
}

t_vec2	vec3_xy(t_vec3 p)
{
	return ((t_vec2){.x = p.x, .y = p.y});
}

t_vec2	vec3_yz(t_vec3 p)
{
	return ((t_vec2){.x = p.y, .y = p.z});
}
