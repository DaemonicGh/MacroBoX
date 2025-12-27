/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:04:36 by daemo             #+#    #+#             */
/*   Updated: 2025/12/22 23:06:07 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

t_vec2	vec2_new(double x, double y)
{
	return ((t_vec2){.x = x, .y = y});
}

t_vec2i	vec2i_new(int x, int y)
{
	return ((t_vec2i){.x = x, .y = y});
}

t_vec3	vec3_new(double x, double y, double z)
{
	return ((t_vec3){.x = x, .y = y, .z = z});
}

t_vec3i	vec3i_new(int x, int y, int z)
{
	return ((t_vec3i){.x = x, .y = y, .z = z});
}
