/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_c_other.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 23:33:44 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 17:35:44 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_C_OTHER_H
# define MBX_C_OTHER_H

# include "mbx_c_scancodes.h"

# define MBX_WINDOW_FLAG_NONE 0b0
# define MBX_WINDOW_FLAG_RESIZABLE 0b1
# define MBX_WINDOW_FLAG_FULLSCREEN 0b10

# define MBX_FRAME_SKIP_MARGIN_RATIO 0.95
# define MBX_INIT_MAX_WINDOW_COVERAGE_RATIO 0.75

# define MBX_BASE_BACKGROUND_COLOR 0x020204
# define MBX_BASE_FPS_CAP 60
# define MBX_BASE_DO_WINDOW_CROSS_EXIT true
# define MBX_BASE_EXIT_KEY MBX_KEY_ESCAPE
# define MBX_BASE_FULLSCREEN_TOGGLE_KEY MBX_KEY_F11

#endif
