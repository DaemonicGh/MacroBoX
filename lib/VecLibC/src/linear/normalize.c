/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:36:43 by daemo             #+#    #+#             */
/*   Updated: 2026/01/14 22:48:56 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/veclc_vecn.h"

t_vec2	vec2_normalize(t_vec2 p)
{
	const double	l = vec2_length(p);

	if (l == 0)
		return (vec2_zero());
	return (vec2_div_d(p, l));
}

t_vec2	vec2i_normalize(t_vec2i p)
{
	const double	l = vec2i_length(p);

	if (l == 0)
		return (vec2_zero());
	return (vec2_div_d(vec2i_to_vec2(p), l));
}

t_vec3	vec3_normalize(t_vec3 p)
{
	const double	l = vec3_length(p);

	if (l == 0)
		return (vec3_zero());
	return (vec3_div_d(p, l));
}

t_vec3	vec3i_normalize(t_vec3i p)
{
	const double	l = vec3i_length(p);

	if (l == 0)
		return (vec3_zero());
	return (vec3_div_d(vec3i_to_vec3(p), l));
}
