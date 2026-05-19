/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:19:40 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 22:40:33 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "modules/types/veclc_s_vec2.h"

double	vec2_length(t_vec2 p)
{
	return (
		sqrt(
			p.x * p.x
			+ p.y * p.y
		)
	);
}

double	vec2i_length(t_vec2i p)
{
	return (
		sqrt(
			p.x * p.x
			+ p.y * p.y
		)
	);
}
