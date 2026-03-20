/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:24:40 by rprieur           #+#    #+#             */
/*   Updated: 2026/03/19 13:24:40 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/mbx_s_color.h"
#include "modules/mbx_math.h"

t_mbxcolor	color_blend_quick(t_mbxcolor bg, t_mbxcolor fg)
{
	const double	v = (fg.a + (255 - bg.a)) / 255.0;

	return ((t_mbxcolor){
		.r = bg.r + (fg.r - bg.r) * v,
		.g = bg.g + (fg.g - bg.g) * v,
		.b = bg.b + (fg.b - bg.b) * v,
		.a = bg.a + fg.a * (255 - bg.a) / 255
	});
}

t_mbxcolor	color_blend(t_mbxcolor bg, t_mbxcolor fg)
{
	if (fg.a == 0)
		return (bg);
	if (fg.a == 255)
		return (fg);
	return (color_blend_quick(bg, fg));
}
