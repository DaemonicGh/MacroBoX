/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3vec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 22:53:48 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/10 00:09:28 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mbx.h"

t_3vec2	t3vec2(t_vec2 p1, t_vec2 p2, t_vec2 p3)
{
	return ((t_3vec2){.p1 = p1, .p2 = p2, .p3 = p3});
}

t_3vec2i	t3vec2i(t_vec2i p1, t_vec2i p2, t_vec2i p3)
{
	return ((t_3vec2i){.p1 = p1, .p2 = p2, .p3 = p3});
}

t_3vec3	t3vec3(t_vec3 p1, t_vec3 p2, t_vec3 p3)
{
	return ((t_3vec3){.p1 = p1, .p2 = p2, .p3 = p3});
}

t_3vec3i	t3vec3i(t_vec3i p1, t_vec3i p2, t_vec3i p3)
{
	return ((t_3vec3i){.p1 = p1, .p2 = p2, .p3 = p3});
}
