/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:35:12 by daemo             #+#    #+#             */
/*   Updated: 2026/01/19 15:14:38 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../includes/modules/types/mbx_s_color.h"

t_mbxcolor	color(unsigned int hex)
{
	return ((t_mbxcolor){.rgba = hex << 8 | 0xFF});
}

t_mbxcolor	color_rgba(unsigned int hex)
{
	return ((t_mbxcolor){.rgba = hex});
}

t_mbxcolor	color_opaque(t_mbxcolor col)
{
	return ((t_mbxcolor){.rgba = col.rgba | 0xFF});
}

t_mbxcolor	color_blend_quick(t_mbxcolor bg, t_mbxcolor fg)
{
	const int	ia = 255 - fg.a;
	t_mbxcolor	out;

	out.r = fg.r + ((bg.r - fg.r) * ia) / 255;
	out.g = fg.g + ((bg.g - fg.g) * ia) / 255;
	out.b = fg.b + ((bg.b - fg.b) * ia) / 255;
	out.a = fg.a + (bg.a * ia) / 255;
	return (out);
}

t_mbxcolor	color_blend(t_mbxcolor bg, t_mbxcolor fg)
{
	if (fg.a == 0)
		return (bg);
	if (fg.a == 255)
		return (fg);
	return (color_blend_quick(bg, fg));
}
