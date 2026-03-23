/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:24:40 by rprieur           #+#    #+#             */
/*   Updated: 2026/03/19 13:24:40 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/mbx_s_color.h"
#include "modules/mbx_math.h"

t_mbxcolor	color_add_fast(t_mbxcolor bg, t_mbxcolor fg)
{
	return ((t_mbxcolor){
		.r = min(bg.r + fg.r, 255),
		.g = min(bg.g + fg.g, 255),
		.b = min(bg.b + fg.b, 255),
		.a = min(bg.a + fg.a, 255)
	});
}

t_mbxcolor	color_sub_fast(t_mbxcolor bg, t_mbxcolor fg)
{
	return ((t_mbxcolor){
		.r = max(bg.r - fg.r, 0),
		.g = max(bg.g - fg.g, 0),
		.b = max(bg.b - fg.b, 0),
		.a = max(bg.a - fg.a, 0)
	});
}

t_mbxcolor	color_add(t_mbxcolor bg, t_mbxcolor fg)
{
	return ((t_mbxcolor){
		.r = min(bg.r + fg.r * fg.a, 255),
		.g = min(bg.g + fg.g * fg.a, 255),
		.b = min(bg.b + fg.b * fg.a, 255),
		.a = min(bg.a + fg.a, 255)
	});
}

t_mbxcolor	color_sub(t_mbxcolor bg, t_mbxcolor fg)
{
	return ((t_mbxcolor){
		.r = max(bg.r - fg.r * fg.a, 0),
		.g = max(bg.g - fg.g * fg.a, 0),
		.b = max(bg.b - fg.b * fg.a, 0),
		.a = max(bg.a - fg.a, 0)
	});
}

t_mbxcolor	color_average(t_mbxcolor col1, t_mbxcolor col2)
{
	return ((t_mbxcolor){
		.r = (col1.r + col2.r) / 2,
		.g = (col1.g + col2.g) / 2,
		.b = (col1.b + col2.b) / 2,
		.a = (col1.a + col2.a) / 2
	});
}
