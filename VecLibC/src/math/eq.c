/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eq.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 23:17:38 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:42:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../../includes/modules/types/veclc_s_vecn.h"

bool	vec2_eq(t_vec2 p1, t_vec2 p2)
{
	return (p1.x == p2.x && p1.y == p2.y);
}

bool	vec2i_eq(t_vec2i p1, t_vec2i p2)
{
	return (p1.x == p2.x && p1.y == p2.y);
}

bool	vec3_eq(t_vec3 p1, t_vec3 p2)
{
	return (p1.x == p2.x && p1.y == p2.y && p1.z == p2.z);
}

bool	vec3i_eq(t_vec3i p1, t_vec3i p2)
{
	return (p1.x == p2.x && p1.y == p2.y && p1.z == p2.z);
}
