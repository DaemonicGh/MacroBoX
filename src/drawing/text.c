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

#include "modules/mbx_drawing.h"

void	mbx_set_char(t_mbx_region *restrict region,
	char c, t_vec2i pos, t_mbx_atlas *font)
{
	const t_vec2i	uv = vec2i(
			c * font->region_size.x % font->atlas.size.x,
			c / (font->atlas.size.x / font->region_size.x)
			* font->region_size.y);

	if (uv.y > font->atlas.size.y)
		return ;
	mbx_set_subregion(region, &font->atlas, pos,
		vec2ix2(uv, font->region_size));
}

void	mbx_set_text(t_mbx_region *restrict region,
	const char *str, t_vec2i pos, t_mbx_atlas *font)
{
	const int	regx4 = font->region_size.x * 4;
	t_vec2i		cpos;
	int			i;

	cpos = pos;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			cpos = vec2i(pos.x, cpos.y + font->region_size.y);
		else if (str[i] == '\t')
			cpos.x = (((cpos.x - pos.x) / regx4 + 1) * regx4 + pos.x);
		else
		{
			mbx_set_char(region, str[i], cpos, font);
			cpos.x += font->region_size.x;
		}
		i++;
	}
}
