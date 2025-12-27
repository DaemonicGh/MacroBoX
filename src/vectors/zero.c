/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 00:14:43 by daemo             #+#    #+#             */
/*   Updated: 2025/12/24 00:18:04 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

t_vec2	vec2_zero(void)
{
	return ((t_vec2){.x = 0, .y = 0});
}

t_vec2i	vec2i_zero(void)
{
	return ((t_vec2i){.x = 0, .y = 0});
}

t_vec3	vec3_zero(void)
{
	return ((t_vec3){.x = 0, .y = 0, .z = 0});
}

t_vec3i	vec3i_zero(void)
{
	return ((t_vec3i){.x = 0, .y = 0, .z = 0});
}
