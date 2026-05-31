/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eq.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 23:17:38 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 23:04:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "modules/types/veclc_s_vec2.h"

bool	vec2_eq(t_vec2 p1, t_vec2 p2)
{
	return (
		p1.x == p2.x
		&& p1.y == p2.y
	);
}

bool	vec2i_eq(t_vec2i p1, t_vec2i p2)
{
	return (
		p1.x == p2.x
		&& p1.y == p2.y
	);
}
