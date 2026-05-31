/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:36:43 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 23:04:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/veclc_vec4.h"
#include "modules/veclc_vec4i.h"

t_vec4	vec4_normalize(t_vec4 p)
{
	const double	l = vec4_length(p);

	if (l == 0)
		return (vec4_zero());
	return (vec4_div_d(p, l));
}

t_vec4	vec4i_normalize(t_vec4i p)
{
	const double	l = vec4i_length(p);

	if (l == 0)
		return (vec4_zero());
	return (vec4_div_d(vec4_vi(p), l));
}
