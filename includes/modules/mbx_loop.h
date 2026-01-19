/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_loop.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:03:51 by daemo             #+#    #+#             */
/*   Updated: 2026/01/19 17:00:49 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_LOOP_H
# define MBX_LOOP_H

# include "types/mbx_s_mbx.h"

/**
 * Run the main loop of the application.
 *
 * @mbx the MacroBoX context.
 * @update the update function to call at each frame.
 * @args the arguments to pass to the update function.
 */
void			mbx_run(t_mbx *mbx,
					void (*update)(t_mbx *mbx, void *args), void *args);

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
t_mbx			*mbx_init(t_vec2i viewport_size,
					char *win_title, unsigned int flags);

/**
 * Exit the MacroLibX, closes the window and frees the MacroBoX context.
 *
 * @mbx the MacroBoX context.
 */
void			mbx_exit(t_mbx *mbx);

#endif
