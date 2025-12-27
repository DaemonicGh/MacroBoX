/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 01:59:08 by daemo             #+#    #+#             */
/*   Updated: 2025/12/27 15:23:42 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

t_vec2	vec2_square(t_vec2 p)
{
	return ((t_vec2){.x = p.x * p.x, .y = p.y * p.y});
}

t_vec2i	vec2i_square(t_vec2i p)
{
	return ((t_vec2i){.x = p.x * p.x, .y = p.y * p.y});
}

t_vec3	vec3_square(t_vec3 p)
{
	return ((t_vec3){.x = p.x * p.x, .y = p.y * p.y, .z = p.z * p.z});
}

t_vec3i	vec3i_square(t_vec3i p)
{
	return ((t_vec3i){.x = p.x * p.x, .y = p.y * p.y, .z = p.z * p.z});
}
