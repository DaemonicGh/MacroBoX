/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:35:12 by daemo             #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/mbx_s_color.h"

t_mbx_color	color(uint32_t hex)
{
	return ((t_mbx_color){.rgba = hex << 8 | 0xFF});
}

t_mbx_color	color_rgba(uint32_t hex)
{
	return ((t_mbx_color){.rgba = hex});
}

t_mbx_color	color_r_g_b_a(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return ((t_mbx_color){.r = r, .g = g, .b = b, .a = a});
}

t_mbx_color	color_opaque(t_mbx_color col)
{
	return ((t_mbx_color){.rgba = col.rgba | 0xFF});
}
