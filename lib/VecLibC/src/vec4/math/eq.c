/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eq.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 23:17:38 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 22:40:30 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "modules/types/veclc_s_vec4.h"

bool	vec4_eq(t_vec4 p1, t_vec4 p2)
{
	return (
		p1.x == p2.x
		&& p1.y == p2.y
		&& p1.z == p2.z
		&& p1.w == p2.w);
}

bool	vec4i_eq(t_vec4i p1, t_vec4i p2)
{
	return (
		p1.x == p2.x
		&& p1.y == p2.y
		&& p1.z == p2.z
		&& p1.w == p2.w);
}
