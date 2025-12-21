/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:55:25 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/21 10:38:01 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

t_vec2	vec2_new(double x, double y)
{
	return ((t_vec2){.x = x, .y = y});
}

t_vec2i	vec2_round(t_vec2 p)
{
	return ((t_vec2i){.x = roundf(p.x), .y = roundf(p.y)});
}

t_vec2	vec2_add(t_vec2 p1, t_vec2 p2)
{
	return ((t_vec2){.x = p1.x + p2.x, .y = p1.y + p2.y});
}

t_vec2	vec2_addto(t_vec2 *p1, t_vec2 p2)
{
	p1->x += p2.x;
	p1->y += p2.y;
	return (*p1);
}

t_vec2	vec2_sub(t_vec2 p1, t_vec2 p2)
{
	return ((t_vec2){.x = p1.x - p2.x, .y = p1.y - p2.y});
}
