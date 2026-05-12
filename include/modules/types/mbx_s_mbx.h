/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_mbx.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:35:40 by rprieur           #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
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
 * @viewport/vp				the region where the application is rendered.
 * @window/win				the application window.
 * @mlx						the MacroLibX context.
 *
 * @keys					array containing each key's press/release timers.
 * @last_press				timestamp to last recorded key press.
 * @last_release			timestamp to last recorded key release.
 * @cursor					cursor position relative to the viewport.
 * @cursor_delta			cursor movement since last frame.
 * @scroll_delta			scroll wheel change since last frame.
 *
 * @delta_time/dt			seconds spent showing the last frame.
 * @seconds_per_frame/spf	seconds spent processing the last frame.
 * @frame_timestamp/now		timestamp of the start of the current frame.
 * @app_timestamp			timestamp of the start of the application.
 * @frames_elapsed			amount of frames processed since the app start.
 *
 * @settings				various modifiable values about the application.
 * @exiting					true if the application loop will stop next frame.
 */
typedef struct s_mbx_context
{
	union
	{
		t_mbx_region	*viewport;
		t_mbx_region	*vp;
	};
	union
	{
		t_mbx_window	window;
		t_mbx_window	win;
	};
	mlx_context			mlx;
	union
	{
		double			delta_time;
		double			dt;
	};
	union
	{
		double			seconds_per_frame;
		double			spf;
	};
	union
	{
		double			frame_timestamp;
		double			now;
	};
	double				app_timestamp;
	unsigned long		frames_elapsed;
	bool				exiting;
	struct s_mbx_settings
	{
		t_mbx_viewport_render	viewport_render;
		t_mbx_color				background_color;
		int						fps_cap;
		t_mbx_region_pipeline	default_pipeline;
		int						exit_key;
		int						fullscreen_toggle_key;
		bool					do_window_cross_exit;
		bool					lock_cursor;
		bool					show_cursor;
	}					settings;
	float				last_press;
	float				last_release;
	float				last_window_event;
	t_vec2i				cursor;
	t_vec2				cursor_delta;
	int					scroll_delta;
	struct s_mbx_key_timestamp
	{
		float			press;
		float			release;
	}					keys[MBX_SCANCODES_LENGTH];
}	t_mbx;
