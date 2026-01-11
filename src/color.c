/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:35:12 by daemo             #+#    #+#             */
/*   Updated: 2026/01/10 14:20:23 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mbx.h"

mlx_color	color(unsigned int hex)
{
	return ((mlx_color){.rgba = hex << 8 | 0xFF});
}

mlx_color	color_rgba(unsigned int hex)
{
	return ((mlx_color){.rgba = hex});
}

mlx_color	color_opaque(mlx_color col)
{
	return ((mlx_color){.rgba = col.rgba | 0xFF});
}

mlx_color	color_blend(mlx_color bg, mlx_color fg)
{
	const int	a = fg.a;
	mlx_color	out;

	out.r = bg.r + ((fg.r - bg.r) * a) / 255;
	out.g = bg.g + ((fg.g - bg.g) * a) / 255;
	out.b = bg.b + ((fg.b - bg.b) * a) / 255;
	out.a = bg.a + a - (bg.a * a) / 255;
	return (out);
}
