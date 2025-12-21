/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:00:09 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/21 10:38:17 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

t_vec3i	vec3i_new(int x, int y, int z)
{
	return ((t_vec3i){.x = x, .y = y, .z = z});
}

t_vec3i	vec3i_add(t_vec3i p1, t_vec3i p2)
{
	return ((t_vec3i){.x = p1.x + p2.x, .y = p1.y + p2.y, .z = p1.z + p2.z});
}

t_vec3i	vec3i_addto(t_vec3i *p1, t_vec3i p2)
{
	p1->x += p2.x;
	p1->y += p2.y;
	p1->z += p2.z;
	return (*p1);
}

t_vec3i	vec3i_sub(t_vec3i p1, t_vec3i p2)
{
	return ((t_vec3i){.x = p1.x - p2.x, .y = p1.y - p2.y, .z = p1.z - p2.z});
}
