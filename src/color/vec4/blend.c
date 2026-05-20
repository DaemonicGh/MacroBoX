/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:24:40 by rprieur           #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/mbx_s_color.h"
#include "modules/mbx_utils.h"

t_vec4	vec4_blend_quick(t_vec4 bg, t_vec4 fg)
{
	const double	bga = bg.a * (1.0 - fg.a);
	const double	blend = fg.a + bga;

	return ((t_vec4){
		.r = (fg.r * fg.a + bg.r * bga) / blend,
		.g = (fg.g * fg.a + bg.g * bga) / blend,
		.b = (fg.b * fg.a + bg.b * bga) / blend,
		.a = blend
	});
}

t_vec4	vec4_blend(t_vec4 bg, t_vec4 fg)
{
	if (fg.a == 0)
		return (bg);
	if (fg.a == 1 || bg.a == 0)
		return (fg);
	return (vec4_blend_quick(bg, fg));
}
