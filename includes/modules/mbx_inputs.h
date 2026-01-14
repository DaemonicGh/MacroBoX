/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_inputs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:34:58 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:27:04 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_INPUTS_H
# define MBX_INPUTS_H

# include "types/mbx_s_mbx.h"

void			mbx_start_events(t_mbx *mbx);
void			mbx_flush_inputs(t_mbx *mbx);
void			key_down_hook(int key, void *param);
void			key_up_hook(int key, void *param);
void			mouse_down_hook(int button, void *param);
void			mouse_up_hook(int button, void *param);
void			mouse_wheel_hook(int button, void *param);
void			window_hook(int event, void *param);
void			mbx_warp_mouse(t_mbx *mbx, int x, int y);

#endif
