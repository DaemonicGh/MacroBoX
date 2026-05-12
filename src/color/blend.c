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

t_mbx_color	color_blend_quick(t_mbx_color bg, t_mbx_color fg)
{
	const double	fga = fg.a / 255.0;
	const double	bga = bg.a / 255.0 * (1.0 - fga);
	const double	blend = fga + bga;

	return ((t_mbx_color){
		.r = (fg.r * fga + bg.r * bga) / blend,
		.g = (fg.g * fga + bg.g * bga) / blend,
		.b = (fg.b * fga + bg.b * bga) / blend,
		.a = blend * 255
	});
}

t_mbx_color	color_blend(t_mbx_color bg, t_mbx_color fg)
{
	if (fg.a == 0)
		return (bg);
	if (fg.a == 255 || bg.a == 0)
		return (fg);
	return (color_blend_quick(bg, fg));
}
