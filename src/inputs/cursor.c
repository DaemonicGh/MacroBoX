/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:13:49 by daemo             #+#    #+#             */
/*   Updated: 2026/02/05 04:25:48 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "veclc.h"
#include "modules/types/mbx_s_mbx.h"

void	mbx_warp_cursor(t_mbx *mbx, t_vec2i pos)
{
	mbx->cursor = pos;
	mlx_mouse_move(mbx->mlx, mbx->window.mlx,
		round((double)pos.x * mbx->window.size.x / mbx->viewport.size.x),
		round((double)pos.y * mbx->window.size.y / mbx->viewport.size.y));
}

void	refresh_cursor(t_mbx *mbx)
{
	const t_vec2i	prev_pos = mbx->cursor;
	t_vec2			pos;

	mlx_mouse_get_pos(mbx->mlx, &mbx->cursor.x, &mbx->cursor.y);
	pos = vec2_mult(vec2i_to_vec2(mbx->cursor),
			vec2i_truediv(mbx->viewport.size, mbx->window.size));
	mbx->cursor = vec2_to_vec2i(pos);
	mbx->cursor_delta.x = pos.x - prev_pos.x;
	mbx->cursor_delta.y = pos.y - prev_pos.y;
	if (mbx->settings.lock_cursor)
		mbx_warp_cursor(mbx, vec2i_div_i(mbx->viewport.size, 2));
}
