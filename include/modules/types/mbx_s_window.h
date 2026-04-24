/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_window.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:23:22 by rprieur           #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../../lib/VecLibC/include/veclc.h"
#include "../mbx_mlx.h"

/**
 * Wrapper struct for a MacroLibX window.
 *
 * @win				the MacroLibX window.
 * @image			the target image if one is provided.
 * @pos				the position of the window.
 * @limits			the minimum and maximum size of the window.
 * @size			the size of the window.
 * @title			the title of the window.
 * @screen_size		the size of the screen the window is on.
 * @is_fullscreen	true if the window is fullscreen.
 * @is_resizable	true if the window is resizable.
 * @is_minimized	true if the window is minimized.
 * @is_maximized	true if the window is maximized.
 *
 * This struct must be destroyed manually using mbx_destroy_window().
 * WARNING: Resizing is VERY unsafe !
 */
typedef struct s_mbx_window
{
	mlx_window		mlx;
	mlx_image		mlx_image;
	t_vec2i			pos;
	t_vec2i			size;
	t_vec2ix2		limits;
	t_vec2i			screen_size;
	char			*title;
	bool			is_fullscreen;
	bool			is_resizable;
	bool			is_minimized;
	bool			is_maximized;
	bool			is_focused;
}	t_mbx_window;
