/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:00:09 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/21 10:38:16 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

t_vec3	vec3_new(double x, double y, double z)
{
	return ((t_vec3){.x = x, .y = y, .z = z});
}

t_vec3i	vec3_round(t_vec3 p)
{
	return ((t_vec3i){.x = roundf(p.x), .y = roundf(p.y), .z = roundf(p.z)});
}

t_vec3	vec3_add(t_vec3 p1, t_vec3 p2)
{
	return ((t_vec3){.x = p1.x + p2.x, .y = p1.y + p2.y, .z = p1.z + p2.z});
}

t_vec3	vec3_addto(t_vec3 *p1, t_vec3 p2)
{
	p1->x += p2.x;
	p1->y += p2.y;
	p1->z += p2.z;
	return (*p1);
}

t_vec3	vec3_sub(t_vec3 p1, t_vec3 p2)
{
	return ((t_vec3){.x = p1.x - p2.x, .y = p1.y - p2.y, .z = p1.z - p2.z});
}
