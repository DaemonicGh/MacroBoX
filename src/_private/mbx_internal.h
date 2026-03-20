/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:50:15 by daemo             #+#    #+#             */
/*   Updated: 2026/02/08 08:54:24 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "modules/types/mbx_s_mbx.h"

typedef struct s__mbxloopcontext
{
	t_mbx	*mbx;
	void	(*update)(t_mbx *mbx, void *args);
	void	*args;
}	t__mbxloopcontext;

double	get_sec_since_epoch(void);
bool	should_skip_frame(t_mbx *mbx);
void	update_time_values(t_mbx *mbx);
void	refresh_deltatime(t_mbx *mbx);

void	enter_loop(t_mbx *mbx);
void	exit_loop(t_mbx *mbx);
void	refresh_cursor(t_mbx *mbx);
void	reset_inputs(t_mbx *mbx);
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
