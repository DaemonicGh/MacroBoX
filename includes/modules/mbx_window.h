/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_window.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:23:22 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 13:16:34 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_WINDOW_H
# define MBX_WINDOW_H

# include "types/mbx_s_mbx.h"

/**
 * Creates and returns a MacroBoX window.
 *
 * @mbx			the MacroBoX context.
 * @size		the size in pixels of the window.
 * @title		the title of the window.
 * @flags		bit mask of the window's behavior flags, see MBX_WINDOW_FLAG_*
 *
 * @return 		the created MacroBoX window
 */
t_mbxwindow		mbx_make_window(t_mbx *mbx,
					t_vec2i size, char *title, int flags);

/**
 * Creates and returns a MacroBoX window that targets to a given image.
 *
 * @mbx			the MacroBoX context.
 * @image		the image to target.
 *
 * This is an abstraction of the MacroLibX's function,
 * it is not compatible with MacroBoX drawing system.
 *
 * @return 		the created MacroBoxwindow
 */
t_mbxwindow		mbx_make_window_target(t_mbx *mbx, t_mbximage image);

/**
 * Destroys and frees the contents of the given MacroBoX window.
 *
 * @mbx			the MacroBoX context.
 * @window		the window to destroy.
 */
void			mbx_destroy_window(t_mbx *mbx, t_mbxwindow window);

/**
 * Refreshes the given window's properties to match its values.
 *
 * @mbx			the MacroBoX context.
 * @window		the window to refresh.
 *
 * This function is very unstable and may result in unexpected behavior.
 */
void			mbx_refresh_window(t_mbx *mbx, t_mbxwindow *window);

/**
 * Centers the given window on the screen.
 *
 * @mbx			the MacroBoX context.
 * @window		the window to center.
 */
void			mbx_center_window(t_mbx *mbx, t_mbxwindow *window);

/**
 * Gets the size of the screen.
 *
 * @mbx			the MacroBoX context.
 * @window		the window to get the screen size from.
 *
 * @return 		a vector containing the size of the screen.
 */
t_vec2i			get_screen_size(t_mbx *mbx, t_mbxwindow *window);

#endif
