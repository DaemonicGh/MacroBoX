/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_c_constants.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 23:33:44 by rprieur           #+#    #+#             */
/*   Updated: 2026/02/08 08:55:11 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "mbx_scancodes.h"

#define MBX_INPUT_ARRAY_START				0
#define MBX_INPUT_ARRAY_END					559
#define MBX_INPUT_ARRAY_LENGTH				560
#define MBX_INPUT_ARRAY_KEYBOARD_START		0
#define MBX_INPUT_ARRAY_KEYBOARD_END		511
#define MBX_INPUT_ARRAY_MOUSE_START			512
#define MBX_INPUT_ARRAY_MOUSE_END			527
#define MBX_INPUT_ARRAY_WINDOW_START		528
#define MBX_INPUT_ARRAY_WINDOW_END			559

#define MBX_WINDOW_FLAG_NONE				0b0
#define MBX_WINDOW_FLAG_RESIZABLE			0b1
#define MBX_WINDOW_FLAG_FULLSCREEN			0b10
#define MBX_WINDOW_FLAG_MINIMIZED			0b100

#define MBX_FRAME_SKIP_MARGIN_RATIO			0.95
#define MBX_MLX_FPS_CAP						-1
#define MBX_INIT_MAX_WINDOW_COVERAGE_RATIO	0.75

#define MBX_BASE_BACKGROUND_COLOR			0x020204
#define MBX_BASE_FPS_CAP					60
#define MBX_BASE_DO_WINDOW_CROSS_EXIT		true
#define MBX_BASE_EXIT_KEY					MBX_KEY_ESCAPE
#define MBX_BASE_FULLSCREEN_TOGGLE_KEY		MBX_KEY_F11
#define MBX_BASE_LOCK_CURSOR				false
#define MBX_BASE_SHOW_CURSOR				true
