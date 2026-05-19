/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:19:40 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 22:40:30 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "modules/types/veclc_s_vec4.h"

double	vec4_length(t_vec4 p)
{
	return (
		sqrt(p.x * p.x
			+ p.y * p.y
			+ p.z * p.z
			+ p.w * p.w
		)
	);
}

double	vec4i_length(t_vec4i p)
{
	return (
		sqrt(p.x * p.x
			+ p.y * p.y
			+ p.z * p.z
			+ p.w * p.w
		)
	);
}
