/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:35:12 by daemo             #+#    #+#             */
/*   Updated: 2026/01/10 00:24:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mbx.h"

mlx_color	color(unsigned int hex)
{
	return ((mlx_color){.rgba = hex});
}

mlx_color	color_opaque(mlx_color color)
{
	return ((mlx_color){.rgba = color.rgba | 0xFF});
}

mlx_color	color_blend(mlx_color bg, mlx_color fg)
{
	const int	a = fg.a;
	mlx_color	out;

	if (a == 0)
		return (bg);
	if (a == 255)
		return (fg);
	out.r = bg.r + ((fg.r - bg.r) * a) / 255;
	out.g = bg.g + ((fg.g - bg.g) * a) / 255;
	out.b = bg.b + ((fg.b - bg.b) * a) / 255;
	out.a = bg.a + a - (bg.a * a) / 255;
	return (out);
}
