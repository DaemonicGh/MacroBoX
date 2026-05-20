/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_constants.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 23:33:44 by rprieur           #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdbool.h>
#include "types/mbx_s_color.h"
#include "types/mbx_s_region.h"
#include "mbx_scancodes.h"

#define MBX_FRAME_SKIP_MARGIN_RATIO			0.95
#define MBX_MLX_FPS_CAP_RATIO				3
#define MBX_INIT_MAX_WINDOW_COVERAGE_RATIO	0.75

typedef enum u_mbx_window_flags
{
	MBX_WINDOW_FLAG_NONE				=	0b0,
	MBX_WINDOW_FLAG_RESIZABLE			=	0b1,
	MBX_WINDOW_FLAG_FULLSCREEN			=	0b10,
	MBX_WINDOW_FLAG_MINIMIZED			=	0b100,
}	t_mbx_window_flags;

typedef enum u_mbx_viewport_render
{
	MBX_VIEWPORT_RENDER_SKIP,
	MBX_VIEWPORT_RENDER_NO_SCALING,
	MBX_VIEWPORT_RENDER_KEEP,
	MBX_VIEWPORT_RENDER_KEEP_INT,
	MBX_VIEWPORT_RENDER_STRETCH,
}	t_mbx_viewport_render;

typedef enum u_mbx_setting_defaults
{
	MBX_DEFAULT_VIEWPORT_RENDER			=	MBX_VIEWPORT_RENDER_KEEP,
	MBX_DEFAULT_BACKGROUND_COLOR		=	0x020204,
	MBX_DEFAULT_FPS_CAP					=	60,
	MBX_DEFAULT_FPS_CAP_MINIMIZED		=	10,
	MBX_DEFAULT_FPS_CAP_UNFOCUSED		=	30,
	MBX_DEFAULT_EXIT_KEY				=	MBX_KEY_ESCAPE,
	MBX_DEFAULT_FULLSCREEN_TOGGLE_KEY	=	MBX_KEY_F11,
	MBX_DEFAULT_DO_WINDOW_CROSS_EXIT	=	true,
	MBX_DEFAULT_LOCK_CURSOR				=	false,
	MBX_DEFAULT_SHOW_CURSOR				=	true,
}	t_mbx_setting_defaults;
