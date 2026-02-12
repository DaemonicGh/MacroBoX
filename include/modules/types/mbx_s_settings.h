/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_settings.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:41:05 by rprieur           #+#    #+#             */
/*   Updated: 2026/02/08 08:54:24 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "mbx_s_color.h"

/**
 * Struct to store a MacroBox application settings.
 *
 * @background_color	background color of the application window.
 * @fps_cap				FPS cap of the application.
 * @exit_key			key to exit the application.
 * @fullscreen_toggle_key	key to toggle fullscreen mode.
 */
typedef struct s_mbxsettings
{
	t_mbxcolor	background_color;
	int			fps_cap;
	bool		do_window_cross_exit;
	int			exit_key;
	int			fullscreen_toggle_key;
}	t_mbxsettings;
