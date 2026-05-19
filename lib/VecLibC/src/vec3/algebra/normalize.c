/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:36:43 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 18:10:55 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/veclc_vec3.h"
#include "modules/veclc_vec3i.h"

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
	return (vec3_div_d(vec3_vi(p), l));
}
