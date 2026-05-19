/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:36:43 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 22:40:33 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/veclc_vec2.h"
#include "modules/veclc_vec2i.h"

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
	return (vec2_div_d(vec2_vi(p), l));
}
