/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_color.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:13:57 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 13:12:34 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_S_COLOR_H
# define MBX_S_COLOR_H

# include "../mbx_mlx.h"

/**
 * Represents a color in the RGBA color space.
 * works the same way as MacroLibX's color.
 */
typedef mlx_color	t_mbxcolor;

/**
 * Creates an opaque color from a hexadecimal value.
 *
 * @hex the hexadecimal value of the color.
 *
 * the hexadecimal value is expected to be in the format 0xRRGGBB.
 */
t_mbxcolor		color(unsigned int hex);

/**
 * Creates a color from a hexadecimal value.
 *
 * @hex The hexadecimal value of the color.
 *
 * the hexadecimal value is expected to be in the format 0xRRGGBBAA.
 */
t_mbxcolor		color_rgba(unsigned int hex);

#endif
