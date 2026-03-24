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

t_mbx_color	color_blend_quick(t_mbx_color bg, t_mbx_color fg)
{
	return ((t_mbx_color){
		.r = bg.r + (((fg.r - bg.r) * fg.a + 128) >> 8),
		.g = bg.g + (((fg.g - bg.g) * fg.a + 128) >> 8),
		.b = bg.b + (((fg.b - bg.b) * fg.a + 128) >> 8),
		.a = fg.a + ((bg.a * (255 - fg.a) + 128) >> 8)
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
