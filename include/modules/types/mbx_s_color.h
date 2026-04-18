/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_color.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:13:57 by rprieur           #+#    #+#             */
/*   Updated: 2026/02/08 08:54:24 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../mbx_mlx.h"

/**
 * Represents a color in the RGBA color space.
 * works the same way as MacroLibX's color.
 */
typedef mlx_color	t_mbx_color;

/**
 * Creates an opaque color from a hexadecimal value.
 *
 * @hex the hexadecimal value of the color.
 *
 * the hexadecimal value is expected to be in the format 0xRRGGBB.
 */
t_mbx_color		color(unsigned int hex);

/**
 * Creates a color from a hexadecimal value.
 *
 * @hex The hexadecimal value of the color.
 *
 * the hexadecimal value is expected to be in the format 0xRRGGBBAA.
 */
t_mbx_color		color_rgba(unsigned int hex);

/**
 * Creates a color from its four channels.
 *
 * @r	The red channel of the color.
 * @g	The green channel of the color.
 * @b	The blue channel of the color.
 * @a	The alpha channel of the color.
 */
t_mbx_color		color_r_g_b_a(
					uint8_t r, uint8_t g, uint8_t b, uint8_t a);
