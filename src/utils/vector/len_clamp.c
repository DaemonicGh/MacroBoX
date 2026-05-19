/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_clamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:11:45 by daemo             #+#    #+#             */
/*   Updated: 2026/04/29 23:28:16 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_utils.h"

t_vec2	vec2_len_clamp(t_vec2 p, double low, double high)
{
	const double	l = vec2_length(p);

	if (l < low)
		return (vec2_mult_d(p, low / l));
	if (l > high)
		return (vec2_mult_d(p, high / l));
	return (p);
}

t_vec2i	vec2i_len_clamp(t_vec2i p, double low, double high)
{
	const double	l = vec2i_length(p);

	if (l < low)
		return (vec2i_mult_d(p, low / l));
	if (l > high)
		return (vec2i_mult_d(p, high / l));
	return (p);
}

t_vec3	vec3_len_clamp(t_vec3 p, double low, double high)
{
	const double	l = vec3_length(p);

	if (l < low)
		return (vec3_mult_d(p, low / l));
	if (l > high)
		return (vec3_mult_d(p, high / l));
	return (p);
}

t_vec3i	vec3i_len_clamp(t_vec3i p, double low, double high)
{
	const double	l = vec3i_length(p);

	if (l < low)
		return (vec3i_mult_d(p, low / l));
	if (l > high)
		return (vec3i_mult_d(p, high / l));
	return (p);
}
