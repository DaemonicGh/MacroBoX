/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 22:02:44 by daemo             #+#    #+#             */
/*   Updated: 2025/12/24 00:29:45 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

double	vec2_dot(t_vec2 p1, t_vec2 p2)
{
	return (p1.x * p2.x + p1.y * p2.y);
}

double	vec2i_dot(t_vec2i p1, t_vec2i p2)
{
	return (p1.x * p2.x + p1.y * p2.y);
}

double	vec3_dot(t_vec3 p1, t_vec3 p2)
{
	return (p1.x * p2.x + p1.y * p2.y + p1.z * p2.z);
}

double	vec3i_dot(t_vec3i p1, t_vec3i p2)
{
	return (p1.x * p2.x + p1.y * p2.y + p1.z * p2.z);
}
