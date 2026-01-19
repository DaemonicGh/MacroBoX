/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_window.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:23:22 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 17:23:55 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_S_WINDOW_H
# define MBX_S_WINDOW_H

# include "../mbx_mlx.h"
# include "../../../VecLibC/includes/modules/types/veclc_s_vec2i.h"

/**
 * Wrapper struct for a MacroLibX window.
 *
 * @win		the MacroLibX window.
 * @image	the target image if one is provided, else NULL
 * @size	the size of the window.
 * @title	the title of the window.
 * @is_fullscreen	the fullscreen status of the window.
 * @is_resizable	the resizable status of the window.
 *
 * This struct must be destroyed manually using mbx_destroy_window().
 */
typedef struct s_mbxwindow
{
	mlx_window		win;
	mlx_image		image;
	t_vec2i			size;
	char			*title;
	bool			is_fullscreen;
	bool			is_resizable;
}	t_mbxwindow;

#endif
