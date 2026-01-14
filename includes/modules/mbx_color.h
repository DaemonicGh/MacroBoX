/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_color.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:13:57 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:07:34 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_COLOR_H
# define MBX_COLOR_H

# include "types/mbx_s_color.h"

t_mbxcolor		color_opaque(t_mbxcolor col);
t_mbxcolor		color_blend(t_mbxcolor col1, t_mbxcolor col2);

#endif
