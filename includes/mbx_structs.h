/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:14:40 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/03 16:14:42 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_STRUCTS_H
# define MBX_STRUCTS_H

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
	struct timeval	frame_start;
}	t_mbxtime;

typedef struct s_mbxsettings
{
	int		fps_cap;
}	t_mbxsettings;

typedef struct s_mbxcontext
{
	mlx_context		mlx;
	t_mbxsettings	settings;
	t_mbxwindow		window;
	t_mbxwindow		viewport;
	t_mbxinputs		inputs;
	t_mbxtime		time;
}	t_mbxcontext;

typedef struct s__mbxloopcontext
{
	t_mbxcontext	*mbx;
	void			(*update)(t_mbxcontext *mbx, void *args);
	void			*args;
}	t__mbxloopcontext;

#endif
