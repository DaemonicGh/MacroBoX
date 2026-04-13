/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 01:40:28 by rprieur           #+#    #+#             */
/*   Updated: 2026/04/13 01:43:39 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_utils.h"

t_vec2	vec2_clamp(t_vec2 p, t_vec2 low, t_vec2 high)
{
	return ((t_vec2){
		.x = fclamp(p.x, low.x, high.x),
		.y = fclamp(p.y, low.y, high.y)
	});
}

t_vec2i	vec2i_clamp(t_vec2i p, t_vec2i low, t_vec2i high)
{
	return ((t_vec2i){
		.x = clamp(p.x, low.x, high.x),
		.y = clamp(p.y, low.y, high.y)
	});
}

t_vec3	vec3_clamp(t_vec3 p, t_vec3 low, t_vec3 high)
{
	return ((t_vec3){
		.x = fclamp(p.x, low.x, high.x),
		.y = fclamp(p.y, low.y, high.y),
		.z = fclamp(p.z, low.z, high.z)
	});
}

t_vec3i	vec3i_clamp(t_vec3i p, t_vec3i low, t_vec3i high)
{
	return ((t_vec3i){
		.x = clamp(p.x, low.x, high.x),
		.y = clamp(p.y, low.y, high.y),
		.z = clamp(p.z, low.z, high.z)
	});
}
