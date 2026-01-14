/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecx3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 22:53:48 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:42:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/types/veclc_s_vecnxn.h"

t_vec2x3	vec2x3(t_vec2 p1, t_vec2 p2, t_vec2 p3)
{
	return ((t_vec2x3){.p1 = p1, .p2 = p2, .p3 = p3});
}

t_vec2ix3	vec2ix3(t_vec2i p1, t_vec2i p2, t_vec2i p3)
{
	return ((t_vec2ix3){.p1 = p1, .p2 = p2, .p3 = p3});
}

t_vec3x3	vec3x3(t_vec3 p1, t_vec3 p2, t_vec3 p3)
{
	return ((t_vec3x3){.p1 = p1, .p2 = p2, .p3 = p3});
}

t_vec3ix3	vec3ix3(t_vec3i p1, t_vec3i p2, t_vec3i p3)
{
	return ((t_vec3ix3){.p1 = p1, .p2 = p2, .p3 = p3});
}
