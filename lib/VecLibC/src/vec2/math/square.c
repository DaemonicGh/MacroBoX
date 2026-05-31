/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 01:59:08 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 23:04:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec2.h"

t_vec2	vec2_square(t_vec2 p)
{
	return ((t_vec2){
		.x = p.x * p.x,
		.y = p.y * p.y,
	});
}

t_vec2i	vec2i_square(t_vec2i p)
{
	return ((t_vec2i){
		.x = p.x * p.x,
		.y = p.y * p.y,
	});
}
