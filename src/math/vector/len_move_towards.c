/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_move_towards.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:08:43 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:18:26 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_math.h"

t_vec2	vec2_len_move_towards(t_vec2 p, t_vec2 goal, double incr)
{
	const t_vec2	diff = vec2_sub(goal, p);
	const double	dist = vec2_length(diff);

	if (dist <= incr)
		return (goal);
	return ((t_vec2){
		.x = p.x + diff.x * (incr / dist),
		.y = p.y + diff.y * (incr / dist)
	});
}

t_vec2i	vec2i_len_move_towards(t_vec2i p, t_vec2i goal, double incr)
{
	const t_vec2i	diff = vec2i_sub(goal, p);
	const double	dist = vec2i_length(diff);

	if (dist <= incr)
		return (goal);
	return ((t_vec2i){
		.x = p.x + diff.x * (incr / dist),
		.y = p.y + diff.y * (incr / dist)
	});
}

t_vec3	vec3_len_move_towards(t_vec3 p, t_vec3 goal, double incr)
{
	const t_vec3	diff = vec3_sub(goal, p);
	const double	dist = vec3_length(diff);

	if (dist <= incr)
		return (goal);
	return ((t_vec3){
		.x = p.x + diff.x * (incr / dist),
		.y = p.y + diff.y * (incr / dist),
		.z = p.z + diff.z * (incr / dist)
	});
}

t_vec3i	vec3i_len_move_towards(t_vec3i p, t_vec3i goal, double incr)
{
	const t_vec3i	diff = vec3i_sub(goal, p);
	const double	dist = vec3i_length(diff);

	if (dist <= incr)
		return (goal);
	return ((t_vec3i){
		.x = p.x + diff.x * (incr / dist),
		.y = p.y + diff.y * (incr / dist),
		.z = p.z + diff.z * (incr / dist)
	});
}
