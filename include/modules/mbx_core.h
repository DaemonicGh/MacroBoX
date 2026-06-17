/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_core.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:35:40 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:43 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>

#include "mbx_structs.h"

/**
 * The context structure for the MacroBoX application.
 *
 * This struct is allocated on the heap and should be freed by mbx_exit.
 */
typedef struct s_mbx_context
{
	union
	{
		// Region where the application is rendered.
		t_mbx_region	*viewport;
		// Region where the application is rendered.
		t_mbx_region	*vp;
	};
	union
	{
		// Application window.
		t_mbx_window	window;
		// Application window.
		t_mbx_window	win;
	};
	// MacroLibX context.
	mlx_context		mlx;
	union
	{
		// Seconds spent processing and displaying the last frame.
		double			delta_time;
		// Seconds spent processing and displaying the last frame.
		double			dt;
	};
	union
	{
		// Seconds spent processing the last frame.
		double			seconds_per_frame;
		// Seconds spent processing the last frame.
		double			spf;
	};
	union
	{
		// Timestamp of the start of the current frame.
		double			frame_timestamp;
		// Timestamp of the start of the current frame.
		double			now;
	};
	// Timestamp of the start of the application.
	double			app_timestamp;
	// Amount of frames processed since the application start.
	uint64_t		frames_elapsed;
	// True if the application loop will stop next frame.
	bool			exiting;
	// Contains various modifiable values about the application.
	t_mbx_settings	settings;
	// Contains pre-initialized assets ready for usage.
	struct s_mbx_default_fonts
	{
		t_mbx_atlas		*font_small;
		t_mbx_atlas		*font_large;
		t_mbx_region	*placeholder;
	}				assets;
	// The application's memory manager.
	t_mbx_allocator	allocator;
	// Seconds elapsed since the last recorded input press.
	float			last_press;
	// Seconds elapsed since the last recorded input release.
	float			last_release;
	// Seconds elapsed since the last recorded window event.
	float			last_window_event;
	// Cursor position relative to the viewport.
	t_vec2			cursor;
	// Cursor movement since last frame.
	t_vec2			cursor_delta;
	// Scroll wheel change since last frame.
	int				scroll_delta;
	// True if caps lock is enabled. Initial state might be incorrect.
	bool			caps_lock_on;
	// Array containing the characters typed this frame.
	char			text_input[MBX_TEXT_INPUT_ARRAY_SIZE];
	struct s_mbx_input_timestamp
	{
		// Seconds elapsed since the input's last press.
		float			press;
		// Seconds elapsed since the input's last release.
		float			release;
	}
	// Array containing each key's press/release timers.
					inputs[MBX_SCANCODES_END - MBX_SCANCODES_START + 1];
}	t_mbx;
