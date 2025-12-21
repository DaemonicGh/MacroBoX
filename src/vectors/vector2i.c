/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:55:25 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/21 10:28:39 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

t_vec2i	vec2i_new(int x, int y)
{
	return ((t_vec2i){.x = x, .y = y});
}

t_vec2i	vec2i_add(t_vec2i p1, t_vec2i p2)
{
	return ((t_vec2i){.x = p1.x + p2.x, .y = p1.y + p2.y});
}

t_vec2i	vec2i_addto(t_vec2i *p1, t_vec2i p2)
{
	p1->x += p2.x;
	p1->y += p2.y;
	return (*p1);
}

t_vec2i	vec2i_sub(t_vec2i p1, t_vec2i p2)
{
	return ((t_vec2i){.x = p1.x - p2.x, .y = p1.y - p2.y});
}
