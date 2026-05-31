/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_constants.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 23:33:44 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:43 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_CONSTANTS_H
# define MBX_CONSTANTS_H
# pragma once

# include <stdbool.h>

# include "mbx_scancodes.h"

# ifndef MBX_DEBUG
#  define MBX_DEBUG		0
# endif

# define MBX_FRAME_SKIP_MARGIN_RATIO		0.95
# define MBX_MLX_FPS_CAP_RATIO				3
# define MBX_INIT_MAX_WINDOW_COVERAGE_RATIO	0.75

typedef enum e_mbx_allocation_data
{
	MBX_ALLOC_EMPTY				= 0x00000000,
	MBX_ALLOC_TYPE_MASK			= 0x0000000F,
	MBX_ALLOC_TYPE_MEMORY		= 0x00000001,
	MBX_ALLOC_TYPE_MBX_REGION	= 0x00000002,
	MBX_ALLOC_TYPE_MLX_IMAGE	= 0x00000004,
	MBX_ALLOC_TYPE_MLX_WINDOW	= 0x00000008,
	MBX_ALLOC_FREE_MASK			= 0x000000F0,
	MBX_ALLOC_FREE_ON_MBX_EXIT	= 0x00000000,
	MBX_ALLOC_FREE_ON_RUN_END	= 0x00000010,
	MBX_ALLOC_FREE_THIS_FRAME	= 0x00000020,
	MBX_ALLOC_FREE_NEXT_FRAME	= 0x00000040,
	MBX_ALLOC_GROUP_MASK		= 0x0FFFFF00,
	MBX_ALLOC_GROUP_MLX			= 0x00000100,
	MBX_ALLOC_GROUP_MBX			= 0x00000200,
	MBX_ALLOC_GROUP_1			= 0x00001000,
	MBX_ALLOC_GROUP_2			= 0x00002000,
	MBX_ALLOC_GROUP_3			= 0x00004000,
	MBX_ALLOC_GROUP_4			= 0x00008000,
	MBX_ALLOC_GROUP_5			= 0x00010000,
	MBX_ALLOC_GROUP_6			= 0x00020000,
	MBX_ALLOC_GROUP_7			= 0x00040000,
	MBX_ALLOC_GROUP_8			= 0x00080000,
	MBX_ALLOC_GROUP_9			= 0x00100000,
	MBX_ALLOC_GROUP_10			= 0x00200000,
	MBX_ALLOC_GROUP_11			= 0x00400000,
	MBX_ALLOC_GROUP_12			= 0x00800000,
	MBX_ALLOC_GROUP_13			= 0x01000000,
	MBX_ALLOC_GROUP_14			= 0x02000000,
	MBX_ALLOC_GROUP_15			= 0x04000000,
	MBX_ALLOC_GROUP_16			= 0x08000000,
}	t_mbx_alloc_flags;

# define MBX_ALLOCATOR_INIT_SIZE		8
# define MBX_ALLOCATOR_CACHE_SIZE	4

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
	MBX_DEFAULT_ALLOC_FLAGS				=	(
			MBX_ALLOC_TYPE_MEMORY | MBX_ALLOC_FREE_ON_MBX_EXIT),
	MBX_DEFAULT_EXIT_KEY				=	MBX_KEY_ESCAPE,
	MBX_DEFAULT_FULLSCREEN_TOGGLE_KEY	=	MBX_KEY_F11,
	MBX_DEFAULT_DO_WINDOW_CROSS_EXIT	=	true,
	MBX_DEFAULT_LOCK_CURSOR				=	false,
	MBX_DEFAULT_SHOW_CURSOR				=	true,
}	t_mbx_setting_defaults;

#endif
