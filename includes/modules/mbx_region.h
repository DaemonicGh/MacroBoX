/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_region.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:23:32 by rprieur           #+#    #+#             */
/*   Updated: 2026/02/05 05:35:36 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_REGION_H
# define MBX_REGION_H

# include "types/mbx_s_mbx.h"

/**
 * Creates and returns a new region with the given size.
 *
 * @size The size of the region to create.
 *
 * This function can fail allocation, then the returned region will be 0 padded.
 */
t_mbxregion		mbx_make_region(t_vec2i size);

/**
 * Creates and returns a new region with a linked image.
 *
 * @mbx The macrobox context.
 * @size The size of the region to create.
 *
 * This function can fail allocation, then the returned region will be 0 padded.
 */
t_mbxregion		mbx_make_region_with_image(t_mbx *mbx, t_vec2i size);

/**
 * Creates and returns a new region from the given image.
 *
 * @mbx The macrobox context.
 * @image The image to create the region from.
 *
 * This function can fail allocation, then the returned region will be 0 padded.
 */
t_mbxregion		mbx_make_region_from_image(t_mbx *mbx, t_mbximage *image);

/**
 * Destroys and frees the contents of the given region.
 *
 * @mbx The macrobox context.
 * @region The region to destroy.
 */
void			mbx_destroy_region(t_mbx *mbx, t_mbxregion *region);

#endif
