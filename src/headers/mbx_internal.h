/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:50:15 by daemo             #+#    #+#             */
/*   Updated: 2026/01/19 17:12:49 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_INTERNAL_H
# define MBX_INTERNAL_H

# include "../../includes/modules/types/mbx_s_mbx.h"

int		bsign(bool positive);
void	*palloc(unsigned long size, int value);
double	get_sec_since_epoch(void);

void	mbx_start_events(t_mbx *mbx);
void	mbx_start_frame(t_mbx *mbx);
void	mbx_end_frame(t_mbx *mbx);
void	draw_viewport(t_mbx *mbx);

void	key_down_hook(int key, void *param);
void	key_up_hook(int key, void *param);
void	mouse_down_hook(int button, void *param);
void	mouse_up_hook(int button, void *param);
void	mouse_wheel_hook(int button, void *param);
void	window_hook(int event, void *param);

void	special_key_handler(t_mbx *mbx, int key);

#endif
