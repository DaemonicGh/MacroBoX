/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:14:40 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/10 01:50:28 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_STRUCTS_H
# define MBX_STRUCTS_H

# include <sys/time.h>
# include "../MacroLibX-2.2.2/includes/mlx.h"
# include "mbx_scancodes.h"
# include "mbx_vectors.h"

typedef struct s_mbximage
{
	mlx_image	img;
	int			width;
	int			height;
}	t_mbximage;

typedef struct s_mbxwindow
{
	mlx_window	win;
	mlx_image	image;
	int			width;
	int			height;
	char		*title;
	bool		is_fullscreen;
	bool		is_resizable;

}	t_mbxwindow;

typedef struct s_mbxregion
{
	mlx_color	*canvas;
	mlx_image	image;
	int			width;
	int			height;
}	t_mbxregion;

typedef struct s_mbxfont
{
	t_mbxregion	region;
	t_vec2i		glyph_size;
	t_vec2i		grid_size;
	mlx_color	color;
}	t_mbxfont;

typedef struct s_mbxinputs
{
	bool		btn[MBX_INPUT_ARRAY_LENGTH];
	bool		btnp[MBX_INPUT_ARRAY_LENGTH];
	bool		btnr[MBX_INPUT_ARRAY_LENGTH];
	int			last_key;
	t_vec2i		mouse;
	t_vec2i		prev_mouse;
	int			mouse_wheel;
	bool		should_exit;
}	t_mbxinputs;

typedef struct s_mbxtime
{
	unsigned long	frames_elapsed;
	double			delta;
	double			frame_start;
	double			sec_per_frame;
}	t_mbxtime;

typedef struct s_mbxsettings
{
	mlx_color	background_color;
	int			fps_cap;
}	t_mbxsettings;

typedef struct s_mbxcontext
{
	mlx_context		mlx;
	t_mbxsettings	settings;
	t_mbxwindow		window;
	t_mbxregion		viewport;
	t_mbxfont		font;
	t_mbxinputs		inputs;
	t_mbxtime		time;
}	t_mbx;

typedef struct s__mbxloopcontext
{
	t_mbx	*mbx;
	void	(*update)(t_mbx *mbx, void *args);
	void	*args;
}	t__mbxloopcontext;

#endif
