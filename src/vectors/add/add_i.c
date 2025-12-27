/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:43:33 by daemo             #+#    #+#             */
/*   Updated: 2025/12/23 18:21:18 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mbx.h"

t_vec2i	vec2i_add_i(t_vec2i p, int value)
{
	return ((t_vec2i){.x = p.x + value, .y = p.y + value});
}

t_vec3i	vec3i_add_i(t_vec3i p, int value)
{
	return ((t_vec3i){.x = p.x + value, .y = p.y + value, .z = p.z + value});
}
