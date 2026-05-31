/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:56:25 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_drawing.h"
#include "modules/mbx_handlers.h"
#include "modules/mbx_utils.h"

bool	mbx_resize_viewport(t_mbx *mbx, t_vec2i size)
{
	t_mbx_region	*new;

	size = vec2i_clamp(size, vec2i_zero(), mbx->window.size);
	new = mbx_create_region_with_image(mbx, size);
	if (!new)
		return (false);
	mbx->cursor = vec2_mult(mbx->cursor,
			vec2i_truediv(size, mbx->viewport->size));
	mbx_destroy_region(mbx, mbx->viewport);
	mbx->viewport = new;
	return (true);
}

bool	mbx_resize_viewport_with_content(t_mbx *mbx, t_vec2i size)
{
	t_mbx_region	*new;

	size = vec2i_clamp(size, vec2i_zero(), mbx->window.size);
	new = mbx_create_region_with_image(mbx, size);
	if (!new)
		return (false);
	mbx->cursor = vec2_mult(mbx->cursor,
			vec2i_truediv(size, mbx->viewport->size));
	mbx_set_region_scaled(new, mbx->viewport, vec2i(0, 0),
		vec2i_truediv(size, mbx->viewport->size));
	mbx_destroy_region(mbx, mbx->viewport);
	mbx->viewport = new;
	return (true);
}
