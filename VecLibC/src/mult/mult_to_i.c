/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_to_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:04:59 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:42:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/types/veclc_s_vecn.h"

t_vec2i	vec2i_mult_to_i(t_vec2i *p, int val)
{
	p->x *= val;
	p->y *= val;
	return (*p);
}

t_vec3i	vec3i_mult_to_i(t_vec3i *p, int val)
{
	p->x *= val;
	p->y *= val;
	p->z *= val;
	return (*p);
}
