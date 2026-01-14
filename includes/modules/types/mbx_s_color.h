/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_color.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:13:57 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:07:40 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_S_COLOR_H
# define MBX_S_COLOR_H

# include "../mbx_mlx.h"

typedef mlx_color	t_mbxcolor;

t_mbxcolor		color(unsigned int hex);
t_mbxcolor		color_rgba(unsigned int hex);

#endif
