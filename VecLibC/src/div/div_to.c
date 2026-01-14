/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_to.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:17:37 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:42:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/types/veclc_s_vecn.h"

t_vec2	vec2_div_to(t_vec2 *p1, t_vec2 p2)
{
	p1->x /= p2.x;
	p1->y /= p2.y;
	return (*p1);
}

t_vec2i	vec2i_div_to(t_vec2i *p1, t_vec2i p2)
{
	p1->x /= p2.x;
	p1->y /= p2.y;
	return (*p1);
}

t_vec3	vec3_div_to(t_vec3 *p1, t_vec3 p2)
{
	p1->x /= p2.x;
	p1->y /= p2.y;
	p1->z /= p2.z;
	return (*p1);
}

t_vec3i	vec3i_div_to(t_vec3i *p1, t_vec3i p2)
{
	p1->x /= p2.x;
	p1->y /= p2.y;
	p1->z /= p2.z;
	return (*p1);
}
