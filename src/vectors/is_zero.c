/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 23:29:10 by daemo             #+#    #+#             */
/*   Updated: 2025/12/27 20:28:23 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

bool	vec2_is_zero(t_vec2 p)
{
	return (p.x == 0 && p.y == 0);
}

bool	vec2i_is_zero(t_vec2i p)
{
	return (p.x == 0 && p.y == 0);
}

bool	vec3_is_zero(t_vec3 p)
{
	return (p.x == 0 && p.y == 0 && p.z == 0);
}

bool	vec3i_is_zero(t_vec3i p)
{
	return (p.x == 0 && p.y == 0 && p.z == 0);
}
