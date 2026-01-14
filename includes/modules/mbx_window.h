/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_window.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:23:22 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:24:28 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_WINDOW_H
# define MBX_WINDOW_H

# include "types/mbx_s_mbx.h"

t_mbxwindow		mbx_make_window(t_mbx *mbx,
					t_vec2i size, char *title, int flags);
t_mbxwindow		mbx_make_window_target(t_mbx *mbx, t_mbximage image);
void			mbx_refresh_window(t_mbx *mbx);
void			mbx_center_window(t_mbx *mbx);

t_vec2i			get_screen_size(t_mbx *mbx);

#endif
