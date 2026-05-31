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

#include "modules/types/veclc_s_vec3xn.h"

t_vec3x4	vec3x4(t_vec3 p1, t_vec3 p2, t_vec3 p3, t_vec3 p4)
{
	return ((t_vec3x4){
		.p1 = p1,
		.p2 = p2,
		.p3 = p3,
		.p4 = p4,
	});
}

t_vec3ix4	vec3ix4(t_vec3i p1, t_vec3i p2, t_vec3i p3, t_vec3i p4)
{
	return ((t_vec3ix4){
		.p1 = p1,
		.p2 = p2,
		.p3 = p3,
		.p4 = p4,
	});
}
