/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4vec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 22:53:52 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/10 00:05:37 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mbx.h"

t_4vec2	t4vec2(t_vec2 p1, t_vec2 p2, t_vec2 p3, t_vec2 p4)
{
	return ((t_4vec2){.p1 = p1, .p2 = p2, .p3 = p3, .p4 = p4});
}

t_4vec2i	t4vec2i(t_vec2i p1, t_vec2i p2, t_vec2i p3, t_vec2i p4)
{
	return ((t_4vec2i){.p1 = p1, .p2 = p2, .p3 = p3, .p4 = p4});
}

t_4vec3	t4vec3(t_vec3 p1, t_vec3 p2, t_vec3 p3, t_vec3 p4)
{
	return ((t_4vec3){.p1 = p1, .p2 = p2, .p3 = p3, .p4 = p4});
}

t_4vec3i	t4vec3i(t_vec3i p1, t_vec3i p2, t_vec3i p3, t_vec3i p4)
{
	return ((t_4vec3i){.p1 = p1, .p2 = p2, .p3 = p3, .p4 = p4});
}
