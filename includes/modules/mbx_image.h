/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:23:16 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:24:18 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_IMAGE_H
# define MBX_IMAGE_H

# include "types/mbx_s_mbx.h"

t_mbximage		mbx_make_image(t_mbx *mbx, int width, int height);
t_mbximage		mbx_make_image_from_file(t_mbx *mbx, char *path);
t_mbximage		mbx_make_image_from_mlx(mlx_image image, int width, int height);
void			mbx_destroy_image(t_mbx *mbx, t_mbximage *image);

#endif
