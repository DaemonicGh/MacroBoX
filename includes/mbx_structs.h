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

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

t_vec2		vec2_new(double x, double y);
t_vec2		vec2_add(t_vec2 p1, t_vec2 p2);
t_vec2		vec2_addto(t_vec2 *p1, t_vec2 p2);
t_vec2		vec2_sub(t_vec2 p1, t_vec2 p2);

typedef struct s_vec2i
{
	int	x;
	int	y;
}	t_vec2i;

t_vec2i		vec2i_new(int x, int y);
t_vec2i		vec2i_add(t_vec2i p1, t_vec2i p2);
t_vec2i		vec2i_addto(t_vec2i *p1, t_vec2i p2);
t_vec2i		vec2i_sub(t_vec2i p1, t_vec2i p2);

t_vec2i		vec2_round(t_vec2 p);

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

t_vec3		vec3_new(double x, double y, double z);
t_vec3		vec3_add(t_vec3 p1, t_vec3 p2);
t_vec3		vec3_addto(t_vec3 *p1, t_vec3 p2);
t_vec3		vec3_sub(t_vec3 p1, t_vec3 p2);

typedef struct s_vec3i
{
	int	x;
	int	y;
	int	z;
}	t_vec3i;

t_vec3i		vec3i_new(int x, int y, int z);
t_vec3i		vec3i_add(t_vec3i p1, t_vec3i p2);
t_vec3i		vec3i_addto(t_vec3i *p1, t_vec3i p2);
t_vec3i		vec3i_sub(t_vec3i p1, t_vec3i p2);

t_vec3i		vec3_round(t_vec3 p);

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


typedef struct s_mbxcontext
{
	mlx_context		mlx;
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
