/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:13:41 by daemo             #+#    #+#             */
/*   Updated: 2025/12/23 18:22:09 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mbx.h"

t_vec2	vec2_mult(t_vec2 p1, t_vec2 p2)
{
	return ((t_vec2){.x = p1.x * p2.x, .y = p1.y * p2.y});
}

t_vec2i	vec2i_mult(t_vec2i p1, t_vec2i p2)
{
	return ((t_vec2i){.x = p1.x * p2.x, .y = p1.y * p2.y});
}

t_vec3	vec3_mult(t_vec3 p1, t_vec3 p2)
{
	return ((t_vec3){.x = p1.x * p2.x, .y = p1.y * p2.y, .z = p1.z * p2.z});
}

t_vec3i	vec3i_mult(t_vec3i p1, t_vec3i p2)
{
	return ((t_vec3i){.x = p1.x * p2.x, .y = p1.y * p2.y, .z = p1.z * p2.z});
}
