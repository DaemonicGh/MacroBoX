/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_app.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:03:51 by daemo             #+#    #+#             */
/*   Updated: 2026/05/29 03:22:43 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "mbx_core.h"

/**
 * Initialize the MacroLibX, creates and returns the MacroBoX context
 * and opens a window.
 *
 * @viewport_size the size of the viewport.
 * @win_title the title of the window.
 * @flags the window flags, see MBX_WINDOW_FLAGS_*
 *
 * The actual window size will scale the viewport to fit the screen.
 */
t_mbx
*mbx_init(
	t_vec2i viewport_size, char *win_title, unsigned int flags);

/**
 * Initialize the MacroLibX, creates and returns the MacroBoX context
 * without opening a window.
 */
t_mbx
*mbx_init_windowless(void);

/**
 * Creates and returns the MacroBoX context using the given MacroLibX context.
 *
 * @mlx	the MacroLibX context.
 *
 * This function is supposed to be a rough bypass
 * to allow multiple MacroBoX instances at once.
 * This functions has been severely untested, use at your own risk.
 */
t_mbx
*mbx_init_from_mlx(
	mlx_context mlx);

/**
 * Initialize the main MacroBoX window.
 *
 * @viewport_size the size of the viewport.
 * @win_title the title of the window.
 * @flags the window flags, see MBX_WINDOW_FLAGS_*
 *
 * The actual window size will scale the viewport to fit the screen.
 * This function is meant to be used along mbx_init_windowless
 */
bool
mbx_create_main_window(
	t_mbx *mbx, t_vec2i viewport_size, char *win_title, unsigned int win_flags);

/**
 * Run the main loop of the application.
 *
 * @mbx the MacroBoX context.
 * @update the update function to call at each frame.
 * @args the arguments to pass to the update function.
 */
void
mbx_run(
	t_mbx *mbx, void (*update)(t_mbx *mbx, void *args), void *args);

/**
 * Exit the MacroLibX, closes the window and frees the MacroBoX context.
 *
 * @mbx the MacroBoX context.
 */
void
mbx_exit(
	t_mbx *mbx);
