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

# ifndef MBX_DEBUG
#  define MBX_DEBUG		0
# endif

# define MBX_TEXT_LAYOUT_QWERTY					\
	"abcdefghijklmnopqrstuvwxyz1234567890\n\0\b\t -=[]\\\0;'`,./"
# define MBX_TEXT_LAYOUT_QWERTY_SHIFT			\
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()\n\0\b\t _+{}|\0:\"~<>?"
# define MBX_TEXT_LAYOUT_QWERTY_FR_ALTGR		\
	"abceeeguiuilmnooqeatuvwxya123$$\0007890\n\0\b\t -=\"\"\\\0;\0\0,./"
# define MBX_TEXT_LAYOUT_QWERTY_FR_SHIFT_ALTGR	\
	"ABCEEEGUIUILMNOOQEATUVWXYA123$$\0007890\n\0\b\t -=\"\"\\\0;\0\0,./"

# define MBX_TEXT_LAYOUT_AZERTY_FR				\
	"qbcdefghijkl,noparstuvzxyw&e\"'(-e_ca\n\0\b\t )=^$*\0mu\0;:!"
# define MBX_TEXT_LAYOUT_AZERTY_FR_SHIFT		\
	"QBCDEFGHIJKL?NOPARSTUVZXYW1234567890\n\0\b\t \0+\0\0\0\0M%\0./\0"
# define MBX_TEXT_LAYOUT_AZERTY_FR_ALTGR		\
	"qbcd$fghijkl,noparstuvzxyw&~#{[|`\\^@\n\0\b\t ]}^\0*\0mu\0;:!"
# define MBX_TEXT_LAYOUT_AZERTY_FR_SHIFT_ALTGR	\
	"QBCD$FGHIJKL,NOPARSTUVZXYW&~#{[|`\\^@\n\0\b\t ]}^\0*\0MU\0;:!"

enum	e_mbx_scancode_section
{
	MBX_SCANCODES_START				= 0,
	MBX_SCANCODES_END				= 255,
	MBX_SCANCODES_KEYBOARD_START	= 0,
	MBX_SCANCODES_MOUSE_START		= 236,
	MBX_SCANCODES_WINDOW_START		= 244,
	MBX_SCANCODES_TEXT_START		= 4,
	MBX_SCANCODES_TEXT_END			= 56
};

# define MBX_TEXT_INPUT_ARRAY_SIZE	 8

// Simplified version of SLD2's scancodes
enum	e_mbx_scancode
{
	MBX_KEY_NONE			= 0,
	MBX_KEY_A				= 4,
	MBX_KEY_B				= 5,
	MBX_KEY_C				= 6,
	MBX_KEY_D				= 7,
	MBX_KEY_E				= 8,
	MBX_KEY_F				= 9,
	MBX_KEY_G				= 10,
	MBX_KEY_H				= 11,
	MBX_KEY_I				= 12,
	MBX_KEY_J				= 13,
	MBX_KEY_K				= 14,
	MBX_KEY_L				= 15,
	MBX_KEY_M				= 16,
	MBX_KEY_N				= 17,
	MBX_KEY_O				= 18,
	MBX_KEY_P				= 19,
	MBX_KEY_Q				= 20,
	MBX_KEY_R				= 21,
	MBX_KEY_S				= 22,
	MBX_KEY_T				= 23,
	MBX_KEY_U				= 24,
	MBX_KEY_V				= 25,
	MBX_KEY_W				= 26,
	MBX_KEY_X				= 27,
	MBX_KEY_Y				= 28,
	MBX_KEY_Z				= 29,
	MBX_KEY_1				= 30,
	MBX_KEY_2				= 31,
	MBX_KEY_3				= 32,
	MBX_KEY_4				= 33,
	MBX_KEY_5				= 34,
	MBX_KEY_6				= 35,
	MBX_KEY_7				= 36,
	MBX_KEY_8				= 37,
	MBX_KEY_9				= 38,
	MBX_KEY_0				= 39,
	MBX_KEY_RETURN			= 40,
	MBX_KEY_ENTER			= 40,
	MBX_KEY_ESCAPE			= 41,
	MBX_KEY_BACKSPACE		= 42,
	MBX_KEY_TAB				= 43,
	MBX_KEY_SPACE			= 44,
	MBX_KEY_MINUS			= 45,
	MBX_KEY_EQUALS			= 46,
	MBX_KEY_LEFTBRACKET		= 47,
	MBX_KEY_RIGHTBRACKET	= 48,
	MBX_KEY_BACKSLASH		= 49,
	MBX_KEY_SEMICOLON		= 51,
	MBX_KEY_APOSTROPHE		= 52,
	MBX_KEY_GRAVE			= 53,
	MBX_KEY_COMMA			= 54,
	MBX_KEY_PERIOD			= 55,
	MBX_KEY_SLASH			= 56,
	MBX_KEY_CAPSLOCK		= 57,
	MBX_KEY_F1				= 58,
	MBX_KEY_F2				= 59,
	MBX_KEY_F3				= 60,
	MBX_KEY_F4				= 61,
	MBX_KEY_F5				= 62,
	MBX_KEY_F6				= 63,
	MBX_KEY_F7				= 64,
	MBX_KEY_F8				= 65,
	MBX_KEY_F9				= 66,
	MBX_KEY_F10				= 67,
	MBX_KEY_F11				= 68,
	MBX_KEY_F12				= 69,
	MBX_KEY_PRINTSCREEN		= 70,
	MBX_KEY_SCROLLLOCK		= 71,
	MBX_KEY_PAUSE			= 72,
	MBX_KEY_INSERT			= 73,
	MBX_KEY_HOME			= 74,
	MBX_KEY_PAGEUP			= 75,
	MBX_KEY_DELETE			= 76,
	MBX_KEY_END				= 77,
	MBX_KEY_PAGEDOWN		= 78,
	MBX_KEY_RIGHT			= 79,
	MBX_KEY_LEFT			= 80,
	MBX_KEY_DOWN			= 81,
	MBX_KEY_UP				= 82,
	MBX_KEY_NUMLOCKCLEAR	= 83,
	MBX_KEY_KP_DIVIDE		= 84,
	MBX_KEY_KP_MULTIPLY		= 85,
	MBX_KEY_KP_MINUS		= 86,
	MBX_KEY_KP_PLUS			= 87,
	MBX_KEY_KP_ENTER		= 88,
	MBX_KEY_KP_1			= 89,
	MBX_KEY_KP_2			= 90,
	MBX_KEY_KP_3			= 91,
	MBX_KEY_KP_4			= 92,
	MBX_KEY_KP_5			= 93,
	MBX_KEY_KP_6			= 94,
	MBX_KEY_KP_7			= 95,
	MBX_KEY_KP_8			= 96,
	MBX_KEY_KP_9			= 97,
	MBX_KEY_KP_0			= 98,
	MBX_KEY_KP_PERIOD		= 99,
	MBX_KEY_LCTRL			= 224,
	MBX_KEY_LSHIFT			= 225,
	MBX_KEY_LALT			= 226,
	MBX_KEY_LGUI			= 227,
	MBX_KEY_RCTRL			= 228,
	MBX_KEY_RSHIFT			= 229,
	MBX_KEY_RALT			= 230,
	MBX_KEY_RGUI			= 231,
	MBX_MOUSE_LEFT			= 237,
	MBX_MOUSE_MIDDLE		= 238,
	MBX_MOUSE_RIGHT			= 239,
	MBX_MOUSE_4				= 240,
	MBX_MOUSE_5				= 241,
	MBX_WINDOW_CLOSE		= 244,
	MBX_WINDOW_MOVE			= 245,
	MBX_WINDOW_MINIMIZE		= 246,
	MBX_WINDOW_MAXIMIZE		= 247,
	MBX_WINDOW_ENTER		= 248,
	MBX_WINDOW_FOCUS		= 249,
	MBX_WINDOW_LEAVE		= 250,
	MBX_WINDOW_UNFOCUS		= 251,
	MBX_WINDOW_RESIZE		= 252
};

# define MBX_FRAME_SKIP_MARGIN_RATIO		0.95
# define MBX_MLX_FPS_CAP_RATIO				3
# define MBX_INIT_MAX_WINDOW_COVERAGE_RATIO	0.75
# define MBX_ALLOCATOR_INIT_SIZE		8
# define MBX_ALLOCATOR_CACHE_SIZE		4

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
	MBX_DEFAULT_HIDE_CURSOR				=	false,
	MBX_DEFAULT_USE_AZERTY				=	false,
}	t_mbx_setting_defaults;

#endif
