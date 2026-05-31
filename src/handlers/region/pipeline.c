/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:09:31 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_drawing.h"

void	mbx_default_pipeline_set(
	void *data, t_mbx_region *region, int index, t_mbx_color col)
{
	(void)data;
	region->pixels[index] = col;
}

t_mbx_color	mbx_pipeline_blend_ignore(
	void *data, t_mbx_color bg, t_mbx_color fg)
{
	(void)data;
	(void)bg;
	return (fg);
}

t_mbx_color	mbx_default_pipeline_blend(
	void *data, t_mbx_color bg, t_mbx_color fg)
{
	(void)data;
	return (color_blend_quick(bg, fg));
}

t_mbx_color	mbx_default_pipeline_get(
	void *data, t_mbx_region *region, int index)
{
	(void)data;
	return (region->pixels[index]);
}
