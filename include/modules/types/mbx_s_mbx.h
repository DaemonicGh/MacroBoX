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
#include "mbx_s_font.h"
#include "mbx_s_image.h"

/**
 * The context structure for the MacroBoX application.
 *
 * @window				the application window.
 * @viewport			the image where the application is rendered.
 * @screen_size			the size of the screen the window is on.
 * @mlx					the MacroLibX context.
 * @default_font		the base font used for rendering text.
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
typedef struct s_mbxcontext
{
	t_mbxregion		viewport;
	t_mbxwindow		window;
	t_vec2i			screen_size;
	mlx_context		mlx;
	t_mbxfont		default_font;

	double			key_presses[MBX_INPUT_ARRAY_LENGTH];
	double			key_releases[MBX_INPUT_ARRAY_LENGTH];
	double			last_press;
	double			last_release;
	t_vec2i			cursor;
	t_vec2			cursor_delta;
	int				scroll_delta;

	double			delta_time;
	double			seconds_per_frame;

	struct s_mbxtimestamps
	{
		double		frame_start;
		double		app_start;
	}				timestamps;
\
	unsigned long	frames_elapsed;

	struct s_mbxsettings
	{
		t_mbxcolor	background_color;
		int			fps_cap;
		bool		do_window_cross_exit;
		int			exit_key;
		int			fullscreen_toggle_key;
		bool		lock_cursor;
		bool		show_cursor;
	}				settings;
\
	bool			exiting;
}	t_mbx;
