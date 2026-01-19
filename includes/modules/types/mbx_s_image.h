/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_image.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:23:16 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 13:08:46 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_S_IMAGE_H
# define MBX_S_IMAGE_H

# include "../mbx_mlx.h"
# include "../../../VecLibC/includes/modules/types/veclc_s_vec2i.h"

/**
 * Wrapper struct for a MacroLibX image.
 *
 * @img 	the MacroLibX image.
 * @size	the size of the image.
 *
 * Do not confuse images with regions, which are MacroBoX actual images.
 * This struct must be destroyed manually using mbx_destroy_image().
 */
typedef struct s_mbximage
{
	mlx_image	img;
	t_vec2i		size;
}	t_mbximage;

#endif
