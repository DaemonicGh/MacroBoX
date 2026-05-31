/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:46:18 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_drawing.h"
#include "modules/mbx_handlers.h"

void	mbx_set_char(t_mbx_region *restrict region,
	char c, t_vec2i pos, t_mbx_atlas *font)
{
	t_vec2i	uv;

	if (!mbx_is_atlas(font) || c < 0)
		return ;
	uv = vec2i(
			c * font->subregion_size.x % font->size.x,
			c / (font->size.x / font->subregion_size.x)
			* font->subregion_size.y);
	if (uv.y + font->subregion_size.y > font->size.y)
		return ;
	mbx_set_subregion(region, font, pos,
		vec2ix2(uv, font->subregion_size));
}

void	mbx_set_char_scaled(t_mbx_region *restrict region,
	char c, t_vec2ix2 pos_scale, t_mbx_atlas *font)
{
	t_vec2i	uv;

	if (!mbx_is_atlas(font) || c < 0)
		return ;
	uv = vec2i(
			c * font->subregion_size.x % font->size.x,
			c / (font->size.x / font->subregion_size.x)
			* font->subregion_size.y);
	if (uv.y + font->subregion_size.y > font->size.y)
		return ;
	mbx_set_subregion_scaled(region, font,
		vec2ix3(pos_scale.p1, uv, font->subregion_size),
		vec2_vi(pos_scale.p2));
}

void	mbx_set_text(t_mbx_region *restrict region,
	const char *str, t_vec2i pos, t_mbx_atlas *font)
{
	const int	regx4 = font->subregion_size.x * 4;
	t_vec2i		cpos;
	int			i;

	if (!mbx_is_atlas(font))
		return ;
	cpos = pos;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			cpos = vec2i(pos.x, cpos.y + font->subregion_size.y);
		else if (str[i] == '\t')
			cpos.x = (((cpos.x - pos.x) / regx4 + 1) * regx4 + pos.x);
		else
		{
			mbx_set_char(region, str[i], cpos, font);
			cpos.x += font->subregion_size.x;
		}
		i++;
	}
}

void	mbx_set_text_scaled(t_mbx_region *restrict region,
	const char *str, t_vec2ix2 pos_scale, t_mbx_atlas *font)
{
	const t_vec2i	size = vec2i_mult(font->subregion_size, pos_scale.p2);
	const int		sizex4 = font->subregion_size.x * 4;
	t_vec2i			cpos;
	int				i;

	if (!mbx_is_atlas(font))
		return ;
	cpos = pos_scale.p1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			cpos = vec2i(pos_scale.p1.x, cpos.y + size.y);
		else if (str[i] == '\t')
			cpos.x = (((cpos.x - pos_scale.p1.x) / sizex4 + 1)
					* sizex4 + pos_scale.p1.x);
		else
		{
			mbx_set_char_scaled(region, str[i],
				vec2ix2(cpos, pos_scale.p2), font);
			cpos.x += size.x;
		}
		i++;
	}
}
