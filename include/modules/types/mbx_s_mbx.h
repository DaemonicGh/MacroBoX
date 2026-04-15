/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_mbx.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:35:40 by rprieur           #+#    #+#             */
/*   Updated: 2026/02/08 08:54:24 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>

#include "modules/mbx_constants.h"
#include "mbx_s_window.h"
#include "mbx_s_region.h"
#include "mbx_s_image.h"
#include "modules/types/mbx_s_color.h"

/**
 * The context structure for the MacroBoX application.
 *
 * @window				the application window.
 * @viewport			the region where the application is rendered.
 * @mlx					the MacroLibX context.
 *
 * @key_presses			array containing the time passed since each key press.
 * @key_releases		array containing the time passed since each key release.
 * @last_press			timestamp to last recorded key press.
 * @last_release			timestamp to last recorded key release.
 * @cursor				cursor position relative to the viewport.
 * @cursor_delta		cursor movement since last frame.
 * @scroll_delta		scroll wheel change since last frame.
 *
 * @delta_time			seconds spent showing the last frame.
 * @seconds_per_frame	seconds spent processing the last frame.
 * @timestamps			timestamps recording occurence of various elements.
 * @frames_elapsed		amount of frames processed since the application's start.
 *
 * @settings			various modifiable values about the application.
 * @exiting				true if the application will stop next frame.
 */
typedef struct s_mbx_context
{
	t_mbx_region			*viewport;
	t_mbx_window			window;
	mlx_context				mlx;

	float					key_presses[MBX_INPUT_ARRAY_LENGTH];
	float					key_releases[MBX_INPUT_ARRAY_LENGTH];
	float					last_press;
	float					last_release;
	t_vec2i					cursor;
	t_vec2					cursor_delta;
	int						scroll_delta;

	double					delta_time;
	double					seconds_per_frame;

	struct s_mbx_timestamps
	{
		double					frame_start;
		double					app_start;
	}						timestamps;
\
	unsigned long			frames_elapsed;

	struct s_mbx_settings
	{
		t_mbx_viewport_render	viewport_render;
		t_mbx_color				background_color;
		int						fps_cap;
		t_mbx_color				(*default_color_getter)(
			void *data, t_mbx_region * region, int i);
		t_mbx_color				(*default_color_setter)(
			void *data, t_mbx_color col);
		void					*default_color_modifier_data;
		int						exit_key;
		int						fullscreen_toggle_key;
		bool					do_window_cross_exit;
		bool					lock_cursor;
		bool					show_cursor;
	}						settings;
\
	bool					exiting;
}	t_mbx;
