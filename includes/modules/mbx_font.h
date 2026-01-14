/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_font.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:27:39 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/14 23:28:40 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_FONT_H
# define MBX_FONT_H

# include "types/mbx_s_mbx.h"

t_mbxfont		mbx_make_font(t_mbxregion region,
					t_vec2i glyph_size, t_mbxcolor col);
t_mbxfont		mbx_make_font_from_file(t_mbx *mbx,
					char *path, t_vec2i glyph_size, t_mbxcolor col);
void			mbx_destroy_font(t_mbx *mbx, t_mbxfont *font);

#endif
