/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 23:29:10 by daemo             #+#    #+#             */
/*   Updated: 2026/05/18 23:04:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "modules/types/veclc_s_vec2.h"

bool	vec2_is_zero(t_vec2 p)
{
	return (
		p.x == 0
		&& p.y == 0
	);
}

bool	vec2i_is_zero(t_vec2i p)
{
	return (
		p.x == 0
		&& p.y == 0
	);
}
