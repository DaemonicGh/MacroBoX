/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 23:29:10 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 18:29:40 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "modules/types/veclc_s_vec3.h"

bool	vec3_is_zero(t_vec3 p)
{
	return (
		p.x == 0
		&& p.y == 0
		&& p.z == 0
	);
}

bool	vec3i_is_zero(t_vec3i p)
{
	return (
		p.x == 0
		&& p.y == 0
		&& p.z == 0
	);
}
