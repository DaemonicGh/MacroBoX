/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:36:43 by daemo             #+#    #+#             */
/*   Updated: 2025/12/24 01:13:43 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

t_vec2	vec2_normalize(t_vec2 p)
{
	if (vec2_is_zero(p))
		return (vec2_zero());
	return (vec2_div_d(p, vec2_length(p)));
}

t_vec2	vec2i_normalize(t_vec2i p)
{
	if (vec2i_is_zero(p))
		return (vec2_zero());
	return (vec2_div_d(vec2i_to_vec2(p), vec2i_length(p)));
}

t_vec3	vec3_normalize(t_vec3 p)
{
	if (vec3_is_zero(p))
		return (vec3_zero());
	return (vec3_div_d(p, vec3_length(p)));
}

t_vec3	vec3i_normalize(t_vec3i p)
{
	if (vec3i_is_zero(p))
		return (vec3_zero());
	return (vec3_div_d(vec3i_to_vec3(p), vec3i_length(p)));
}
