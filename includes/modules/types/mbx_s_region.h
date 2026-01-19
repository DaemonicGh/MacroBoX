/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_region.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:23:32 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 13:13:22 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_S_REGION_H
# define MBX_S_REGION_H

# include "mbx_s_color.h"
# include "../../../VecLibC/includes/modules/types/veclc_s_vec2i.h"

/**
 * Struct to represent a MacroBoX image.
 *
 * @canvas	the array containing the image data.
 * @image	(optional) a mlx_image slot to store the image as a MacroLibX image.
 * @size	the size of the image.
 *
 * This struct must be destroyed manually using mbx_destroy_region().
 */
typedef struct s_mbxregion
{
	t_mbxcolor	*canvas;
	mlx_image	image;
	t_vec2i		size;
}	t_mbxregion;

#endif
