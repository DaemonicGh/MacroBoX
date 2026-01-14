/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecx2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 22:53:39 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:42:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/types/veclc_s_vecnxn.h"

t_vec2x2	vec2x2(t_vec2 p1, t_vec2 p2)
{
	return ((t_vec2x2){.p1 = p1, .p2 = p2});
}

t_vec2ix2	vec2ix2(t_vec2i p1, t_vec2i p2)
{
	return ((t_vec2ix2){.p1 = p1, .p2 = p2});
}

t_vec3x2	vec3x2(t_vec3 p1, t_vec3 p2)
{
	return ((t_vec3x2){.p1 = p1, .p2 = p2});
}

t_vec3ix2	vec3ix2(t_vec3i p1, t_vec3i p2)
{
	return ((t_vec3ix2){.p1 = p1, .p2 = p2});
}
