/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:02:20 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/10 14:04:04 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mbx.h"

t_mbxfont	mbx_make_font(t_mbxregion region,
	t_vec2i glyph_size, mlx_color col)
{
	t_mbxfont	font;

	font.region = region;
	font.glyph_size = glyph_size;
	font.color = col;
	font.grid_size = vec2i(
			region.width / glyph_size.x, region.height / glyph_size.y);
	return (font);
}

t_mbxfont	mbx_make_font_from_file(t_mbx *mbx,
	char *path, t_vec2i glyph_size, mlx_color col)
{
	t_mbximage	image;
	t_mbxregion	region;

	image = mbx_make_image_from_file(mbx, path);
	if (!image.img)
		return ((t_mbxfont){0});
	region = mbx_make_region_from_image(mbx, &image);
	if (!region.canvas)
		return ((t_mbxfont){0});
	return (mbx_make_font(region, glyph_size, col));
}

void	mbx_destroy_font(t_mbx *mbx, t_mbxfont *font)
{
	mbx_destroy_region(mbx, &font->region);
}
