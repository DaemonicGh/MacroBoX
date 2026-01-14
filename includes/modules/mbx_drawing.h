/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_drawing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:32:17 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:04:16 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_DRAWING_H
# define MBX_DRAWING_H

# include "../../VecLibC/includes/modules/types/veclc_s_vecnxn.h"
# include "types/mbx_s_mbx.h"

void			mbx_clear(t_mbx *mbx, t_mbxcolor col);
t_mbxcolor		mbx_get_pixel(t_mbx *mbx, t_vec2i pos);
t_mbxcolor		mbx_get_pixel_xy(t_mbx *mbx, int x, int y);
void			mbx_set_pixel(t_mbx *mbx, t_vec2i pos, t_mbxcolor col);
void			mbx_set_pixel_xy(t_mbx *mbx, int x, int y, t_mbxcolor col);
void			mbx_set_rect(t_mbx *mbx,
					t_vec2i pos, t_vec2i size, t_mbxcolor col);
void			mbx_set_rect_border(t_mbx *mbx,
					t_vec2i pos, t_vec2i size, t_mbxcolor col);
void			mbx_set_line(t_mbx *mbx, t_vec2ix2 pos, t_mbxcolor col);
void			mbx_set_line_thick(t_mbx *mbx,
					t_vec2ix2 pos, unsigned int thickness, t_mbxcolor col);
void			mbx_set_char(t_mbx *mbx,
					t_vec2i pos, char c, t_mbxcolor col_override);
void			mbx_set_text(t_mbx *mbx,
					t_vec2i pos, const char *str, t_mbxcolor col_override);
void			mbx_set_region(t_mbx *mbx, t_vec2i pos, t_mbxregion *region);
void			mbx_set_subregion(t_mbx *mbx,
					t_vec2i pos, t_vec2ix2 uvwh, t_mbxregion *region);

t_mbxcolor		mbx_get_region_pixel(t_mbxregion *region, t_vec2i pos);
t_mbxcolor		mbx_get_region_pixel_xy(t_mbxregion *region, int x, int y);
void			mbx_set_region_pixel(t_mbxregion *region,
					t_vec2i pos, t_mbxcolor col);
void			mbx_set_region_pixel_xy(t_mbxregion *region,
					int x, int y, t_mbxcolor col);
void			mbx_set_region_rect(t_mbxregion *region,
					t_vec2i pos, t_vec2i size, t_mbxcolor col);
void			mbx_set_region_rect_border(t_mbxregion *region,
					t_vec2i pos, t_vec2i size, t_mbxcolor col);
void			mbx_set_region_line(t_mbxregion *region,
					t_vec2ix2 pos, t_mbxcolor col);
void			mbx_set_region_line_thick(t_mbxregion *region,
					t_vec2ix2 pos, unsigned int thickness, t_mbxcolor col);
void			mbx_set_region_char(t_mbxregion *region,
					t_vec2i pos, char c, t_mbxfont *font);
void			mbx_set_region_text(t_mbxregion *region,
					t_vec2i pos, const char *str, t_mbxfont *font);
void			mbx_set_region_region(t_mbxregion *dest,
					t_vec2i pos, t_mbxregion *src);
void			mbx_set_region_subregion(t_mbxregion *dest,
					t_vec2i pos, t_vec2ix2 uvwh, t_mbxregion *src);

#endif
