/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_functions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:03:51 by daemo             #+#    #+#             */
/*   Updated: 2025/12/21 19:24:43 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_FUNCTIONS_H
# define MBX_FUNCTIONS_H

# include "mbx_structs.h"

t_mbximage		mbx_make_image(t_mbxcontext *mbx, int width, int height);
t_mbximage		mbx_make_image_from_mlx(mlx_image image, int width, int height);
void			mbx_fill_image(t_mbxcontext *mbx,
					t_mbximage image, mlx_color color);

t_mbxwindow		mbx_make_window(t_mbxcontext *mbx,
					t_vec2i size, char *title, int mode);
t_mbxwindow		mbx_make_window_target(t_mbxcontext *mbx, t_mbximage image);
void			mbx_refresh_window(t_mbxcontext *mbx);
void			mbx_center_window(t_mbxcontext *mbx);

void			mbx_run(t_mbxcontext *mbx,
					void (*update)(t_mbxcontext *mbx, void *args), void *args);
t_mbxcontext	*mbx_init(t_vec2i win_size, char *win_title, int win_mode);
void			mbx_exit(t_mbxcontext *mbx);

void			mbx_start_events(t_mbxcontext *mbx);
void			mbx_flush_inputs(t_mbxcontext *mbx);
void			key_down_hook(int key, void *param);
void			key_up_hook(int key, void *param);
void			mouse_down_hook(int button, void *param);
void			mouse_up_hook(int button, void *param);
void			mouse_wheel_hook(int button, void *param);
void			window_hook(int event, void *param);
void			mbx_warp_mouse(t_mbxcontext *mbx, int x, int y);

#endif