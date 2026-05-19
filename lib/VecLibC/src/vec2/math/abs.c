/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 02:09:15 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 22:40:33 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "modules/types/veclc_s_vec2.h"

t_vec2	vec2_abs(t_vec2 p)
{
	return ((t_vec2){
		.x = fabs(p.x),
		.y = fabs(p.y),
	});
}

t_vec2i	vec2i_abs(t_vec2i p)
{
	return ((t_vec2i){
		.x = abs(p.x),
		.y = abs(p.y),
	});
}
