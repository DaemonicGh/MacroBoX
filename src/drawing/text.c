/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:46:18 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:11:57 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/mbx_drawing.h"

static void	colored_subregion(t_mbxregion *dest,
	t_vec2ix3 posuvwh, t_mbxregion *src, t_mbxcolor col)
{
	t_mbxcolor	pixel;
	int			x;
	int			y;

	x = 0;
	while (x < posuvwh.p3.x)
	{
		y = 0;
		while (y < posuvwh.p3.y)
		{
			pixel = mbx_get_region_pixel_xy(
					src, posuvwh.p2.x + x, posuvwh.p2.y + y);
			pixel.r *= col.r / 255.0;
			pixel.g *= col.g / 255.0;
			pixel.b *= col.b / 255.0;
			pixel.a *= col.a / 255.0;
			mbx_set_region_pixel_xy(
				dest, posuvwh.p1.x + x, posuvwh.p1.y + y, pixel);
			y++;
		}
		x++;
	}
}

void	mbx_set_region_char(t_mbxregion *region,
	t_vec2i pos, char c, t_mbxfont *font)
{
	if (c < 0)
		return ;
	colored_subregion(region, vec2ix3(pos,
			vec2i(c % font->grid_size.x * font->glyph_size.x,
				c / font->grid_size.x * font->glyph_size.y),
			font->glyph_size), &font->region, font->color);
}

void	mbx_set_region_text(t_mbxregion *region,
	t_vec2i pos, const char *str, t_mbxfont *font)
{
	t_vec2i	cpos;
	int		i;

	cpos = pos;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			cpos = vec2i(pos.x, cpos.y + font->glyph_size.y);
		else if (str[i] == '\t')
			cpos.x += font->glyph_size.x * 4;
		else
		{
			mbx_set_region_char(region, cpos, str[i], font);
			cpos.x += font->glyph_size.x;
		}
		i++;
	}
}

void	mbx_set_char(t_mbx *mbx, t_vec2i pos, char c, t_mbxcolor col_override)
{
	const t_mbxcolor	original_color = mbx->font.color;

	mbx->font.color = col_override;
	mbx_set_region_char(&mbx->viewport, pos, c, &mbx->font);
	mbx->font.color = original_color;
}

void	mbx_set_text(t_mbx *mbx,
	t_vec2i pos, const char *str, t_mbxcolor col_override)
{
	const t_mbxcolor	original_color = mbx->font.color;

	mbx->font.color = col_override;
	mbx_set_region_text(&mbx->viewport, pos, str, &mbx->font);
	mbx->font.color = original_color;
}
