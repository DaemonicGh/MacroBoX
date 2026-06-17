/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:24:40 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_structs.h"
#include "modules/mbx_utils.h"

t_mbx_color	color_add(t_mbx_color bg, t_mbx_color fg)
{
	return ((t_mbx_color){
		.r = min(bg.r + fg.r * fg.a, 255),
		.g = min(bg.g + fg.g * fg.a, 255),
		.b = min(bg.b + fg.b * fg.a, 255),
		.a = min(bg.a + fg.a, 255)
	});
}

t_mbx_color	color_sub(t_mbx_color bg, t_mbx_color fg)
{
	return ((t_mbx_color){
		.r = max(bg.r - fg.r * fg.a, 0),
		.g = max(bg.g - fg.g * fg.a, 0),
		.b = max(bg.b - fg.b * fg.a, 0),
		.a = max(bg.a - fg.a, 0)
	});
}

t_mbx_color	color_mult(t_mbx_color col1, t_mbx_color col2)
{
	return ((t_mbx_color){
		.r = col1.r * col2.r / 255,
		.g = col1.g * col2.g / 255,
		.b = col1.b * col2.b / 255,
		.a = col1.a * col2.a / 255
	});
}
