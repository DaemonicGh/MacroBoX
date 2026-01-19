/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:23:16 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 15:18:33 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_IMAGE_H
# define MBX_IMAGE_H

# include "types/mbx_s_mbx.h"

/**
 * Creates an returns a MacroBoX image.
 *
 * @mbx the MacroBoX context.
 * @size the size of the image.
 */
t_mbximage		mbx_make_image(t_mbx *mbx, t_vec2i size);

/**
 * Creates an returns a MacroBoX image from a file.
 *
 * @mbx the MacroBoX context.
 * @path the path to the image file.
 */
t_mbximage		mbx_make_image_from_file(t_mbx *mbx, char *path);

/**
 * Creates an returns a MacroBoX image from its MacroLibX equivalent.
 *
 * @mbx the MacroBoX context.
 * @image the MacroLibX image.
 * @width the width of the image.
 * @height the height of the image.
 */
t_mbximage		mbx_make_image_from_mlx(mlx_image image, int width, int height);

/**
 * Destroys and frees the content of a MacroBoX image.
 *
 * @mbx the MacroBoX context.
 * @image the MacroBoX image to destroy.
 */
void			mbx_destroy_image(t_mbx *mbx, t_mbximage *image);

#endif
