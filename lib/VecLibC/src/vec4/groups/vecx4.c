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

#include "modules/types/veclc_s_vec4xn.h"

t_vec4x4	vec4x4(t_vec4 p1, t_vec4 p2, t_vec4 p3, t_vec4 p4)
{
	return ((t_vec4x4){
		.p1 = p1,
		.p2 = p2,
		.p3 = p3,
		.p4 = p4,
	});
}

t_vec4ix4	vec4ix4(t_vec4i p1, t_vec4i p2, t_vec4i p3, t_vec4i p4)
{
	return ((t_vec4ix4){
		.p1 = p1,
		.p2 = p2,
		.p3 = p3,
		.p4 = p4,
	});
}
