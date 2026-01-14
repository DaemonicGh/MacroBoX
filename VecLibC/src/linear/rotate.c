/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:21:33 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:42:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../includes/modules/types/veclc_s_vecn.h"

t_vec2	vec2_rotate(t_vec2 p, double radians)
{
	return ((t_vec2){.x = p.x * sin(radians), .y = p.y * cos(radians)});
}

t_vec2i	vec2i_rotate(t_vec2i p, double radians)
{
	return ((t_vec2i){.x = p.x * sin(radians), .y = p.y * cos(radians)});
}
