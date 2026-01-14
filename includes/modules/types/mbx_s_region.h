/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_region.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:23:32 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/14 23:24:51 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_S_REGION_H
# define MBX_S_REGION_H

# include "mbx_s_color.h"

typedef struct s_mbxregion
{
	t_mbxcolor	*canvas;
	mlx_image	image;
	int			width;
	int			height;
}	t_mbxregion;

#endif
