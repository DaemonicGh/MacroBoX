/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 23:29:10 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 22:40:30 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "modules/types/veclc_s_vec4.h"

bool	vec4_is_zero(t_vec4 p)
{
	return (
		p.x == 0
		&& p.y == 0
		&& p.z == 0
		&& p.w == 0);
}

bool	vec4i_is_zero(t_vec4i p)
{
	return (
		p.x == 0
		&& p.y == 0
		&& p.z == 0
		&& p.w == 0);
}
