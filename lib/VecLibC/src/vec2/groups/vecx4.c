/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecx4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 22:53:52 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 23:04:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec2xn.h"

t_vec2x4	vec2x4(t_vec2 p1, t_vec2 p2, t_vec2 p3, t_vec2 p4)
{
	return ((t_vec2x4){
		.p1 = p1,
		.p2 = p2,
		.p3 = p3,
		.p4 = p4,
	});
}

t_vec2ix4	vec2ix4(t_vec2i p1, t_vec2i p2, t_vec2i p3, t_vec2i p4)
{
	return ((t_vec2ix4){
		.p1 = p1,
		.p2 = p2,
		.p3 = p3,
		.p4 = p4,
	});
}
