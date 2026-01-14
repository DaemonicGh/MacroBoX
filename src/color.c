/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:35:12 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:19:12 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/modules/types/mbx_s_color.h"

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

t_mbxcolor	color_blend(t_mbxcolor bg, t_mbxcolor fg)
{
	const int	a = fg.a;
	t_mbxcolor	out;

	out.r = bg.r + ((fg.r - bg.r) * a) / 255;
	out.g = bg.g + ((fg.g - bg.g) * a) / 255;
	out.b = bg.b + ((fg.b - bg.b) * a) / 255;
	out.a = bg.a + a - (bg.a * a) / 255;
	return (out);
}
