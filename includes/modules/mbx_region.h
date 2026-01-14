/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_region.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:23:32 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:24:24 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_REGION_H
# define MBX_REGION_H

# include "types/mbx_s_mbx.h"

t_mbxregion		mbx_make_region(t_vec2i size);
t_mbxregion		mbx_make_region_wh(int width, int height);
t_mbxregion		mbx_make_region_from_image(t_mbx *mbx, t_mbximage *image);
void			mbx_destroy_region(t_mbx *mbx, t_mbxregion *region);

#endif
