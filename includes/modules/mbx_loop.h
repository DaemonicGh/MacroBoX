/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_loop.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:03:51 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:07:13 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_LOOP_H
# define MBX_LOOP_H

# include "types/mbx_s_mbx.h"

void			mbx_run(t_mbx *mbx,
					void (*update)(t_mbx *mbx, void *args), void *args);
t_mbx			*mbx_init(t_vec2i viewport_size, char *win_title, int win_mode);
void			mbx_exit(t_mbx *mbx);
void			draw_viewport(t_mbx *mbx);

#endif
