/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_functions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:03:51 by daemo             #+#    #+#             */
/*   Updated: 2026/01/10 02:07:53 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_FUNCTIONS_H
# define MBX_FUNCTIONS_H

# include "mbx_structs.h"
# include "mbx_vectors.h"

t_mbximage		mbx_make_image(t_mbx *mbx, int width, int height);
t_mbximage		mbx_make_image_from_file(t_mbx *mbx, char *path);
t_mbximage		mbx_make_image_from_mlx(mlx_image image, int width, int height);
void			mbx_fill_image(t_mbx *mbx, t_mbximage image, mlx_color color);
void			mbx_destroy_image(t_mbx *mbx, t_mbximage *image);

t_mbxwindow		mbx_make_window(t_mbx *mbx,
					t_vec2i size, char *title, int flags);
t_mbxwindow		mbx_make_window_target(t_mbx *mbx, t_mbximage image);
void			mbx_refresh_window(t_mbx *mbx);
void			mbx_center_window(t_mbx *mbx);

t_mbxregion		mbx_make_region(t_vec2i size);
t_mbxregion		mbx_make_region_wh(int width, int height);
t_mbxregion		mbx_make_region_from_image(t_mbx *mbx, t_mbximage *image);
void			mbx_destroy_region(t_mbx *mbx, t_mbxregion *region);

t_mbxfont		mbx_make_font(t_mbxregion region,
					t_vec2i glyph_size, mlx_color color);
t_mbxfont		mbx_make_font_from_file(t_mbx *mbx,
					char *path, t_vec2i glyph_size, mlx_color color);
void			mbx_destroy_font(t_mbx *mbx, t_mbxfont *font);

t_vec2i			get_screen_size(t_mbx *mbx);

void			mbx_run(t_mbx *mbx,
					void (*update)(t_mbx *mbx, void *args), void *args);
t_mbx			*mbx_init(t_vec2i viewport_size, char *win_title, int win_mode);
void			mbx_exit(t_mbx *mbx);
void			draw_viewport(t_mbx *mbx);
void			mbx_reset_settings(t_mbx *mbx);
void			mbx_refresh_settings(t_mbx *mbx);

mlx_color		color(unsigned int hex);
mlx_color		color_opaque(mlx_color color);
mlx_color		color_blend(mlx_color col1, mlx_color col2);

// Drawing

void			mbx_clear(t_mbx *mbx, mlx_color color);
mlx_color		mbx_get_pixel(t_mbx *mbx, t_vec2i pos);
mlx_color		mbx_get_pixel_xy(t_mbx *mbx, int x, int y);
void			mbx_set_pixel(t_mbx *mbx, t_vec2i pos, mlx_color color);
void			mbx_set_pixel_xy(t_mbx *mbx, int x, int y, mlx_color color);
void			mbx_set_rect(t_mbx *mbx,
					t_vec2i pos, t_vec2i size, mlx_color color);
void			mbx_set_rect_border(t_mbx *mbx,
					t_vec2i pos, t_vec2i size, mlx_color color);
void			mbx_set_line(t_mbx *mbx, t_2vec2i pos, mlx_color color);
void			mbx_set_line_thick(t_mbx *mbx,
					t_2vec2i pos, unsigned int thickness, mlx_color color);
void			mbx_set_char(t_mbx *mbx,
					t_vec2i pos, char c, mlx_color color_override);
void			mbx_set_text(t_mbx *mbx,
					t_vec2i pos, const char *str, mlx_color color_override);
void			mbx_set_region(t_mbx *mbx, t_vec2i pos, t_mbxregion *region);
void			mbx_set_subregion(t_mbx *mbx,
					t_vec2i pos, t_2vec2i uvwh, t_mbxregion *region);

mlx_color		mbx_get_region_pixel(t_mbxregion *region, t_vec2i pos);
mlx_color		mbx_get_region_pixel_xy(t_mbxregion *region, int x, int y);
void			mbx_set_region_pixel(t_mbxregion *region,
					t_vec2i pos, mlx_color color);
void			mbx_set_region_pixel_xy(t_mbxregion *region,
					int x, int y, mlx_color color);
void			mbx_set_region_rect(t_mbxregion *region,
					t_vec2i pos, t_vec2i size, mlx_color color);
void			mbx_set_region_rect_border(t_mbxregion *region,
					t_vec2i pos, t_vec2i size, mlx_color color);
void			mbx_set_region_line(t_mbxregion *region,
					t_2vec2i pos, mlx_color color);
void			mbx_set_region_line_thick(t_mbxregion *region,
					t_2vec2i pos, unsigned int thickness, mlx_color color);
void			mbx_set_region_char(t_mbxregion *region,
					t_vec2i pos, char c, t_mbxfont *font);
void			mbx_set_region_text(t_mbxregion *region,
					t_vec2i pos, const char *str, t_mbxfont *font);
void			mbx_set_region_region(t_mbxregion *dest,
					t_vec2i pos, t_mbxregion *src);
void			mbx_set_region_subregion(t_mbxregion *dest,
					t_vec2i pos, t_2vec2i uvwh, t_mbxregion *src);

// Events and Inputs

void			mbx_start_events(t_mbx *mbx);
void			mbx_flush_inputs(t_mbx *mbx);
void			key_down_hook(int key, void *param);
void			key_up_hook(int key, void *param);
void			mouse_down_hook(int button, void *param);
void			mouse_up_hook(int button, void *param);
void			mouse_wheel_hook(int button, void *param);
void			window_hook(int event, void *param);
void			mbx_warp_mouse(t_mbx *mbx, int x, int y);

#endif
