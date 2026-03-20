/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_image.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:23:16 by rprieur           #+#    #+#             */
/*   Updated: 2026/02/08 08:54:24 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../../lib/VecLibC/include/veclc.h"
#include "../mbx_mlx.h"

/**
 * Wrapper struct for a MacroLibX image.
 *
 * @mlx 	the MacroLibX image.
 * @size	the size of the image.
 *
 * Do not confuse images with regions, which are MacroBoX actual images.
 * This struct must be destroyed manually using mbx_destroy_image().
 */
typedef struct s_mbximage
{
	mlx_image	mlx;
	t_vec2i		size;
}	t_mbximage;
