/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:50:09 by daemo             #+#    #+#             */
/*   Updated: 2025/12/23 18:22:14 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mbx.h"

t_vec2	vec2_sub_d(t_vec2 p, double value)
{
	return ((t_vec2){.x = p.x - value, .y = p.y - value});
}

t_vec3	vec3_sub_d(t_vec3 p, double value)
{
	return ((t_vec3){.x = p.x - value, .y = p.y - value, .z = p.z - value});
}
