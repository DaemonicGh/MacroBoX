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

#include "veclc.h"
#include "modules/types/mbx_s_mbx.h"
#include "modules/mbx_utils.h"

void	mbx_warp_cursor(t_mbx *mbx, t_vec2i pos)
{
	mbx->cursor = pos;
	mlx_mouse_move(mbx->mlx, mbx->window.mlx,
		round((double)pos.x * mbx->window.size.x / mbx->viewport.size.x),
		round((double)pos.y * mbx->window.size.y / mbx->viewport.size.y));
}

void	mbx_move_cursor(t_mbx *mbx, t_vec2i pos)
{
	t_vec2i	prev;

	prev = mbx->cursor;
	mbx_warp_cursor(mbx, pos);
	mbx->cursor_delta = vec2_add(mbx->cursor_delta,
			vec2i_to_vec2(vec2i_sub(pos, mbx->cursor)));
}

void	mbx_center_cursor(t_mbx *mbx)
{
	const t_vec2i	pos = vec2i(
			lerp(clamp(mbx->window.pos.x, 0, mbx->window.screen_size.x),
				clamp(mbx->window.pos.x + mbx->window.size.x,
					0, mbx->window.screen_size.x), 0.5) - mbx->window.pos.x,
			lerp(clamp(mbx->window.pos.y, 0, mbx->window.screen_size.y),
				clamp(mbx->window.pos.y + mbx->window.size.y,
					0, mbx->window.screen_size.y), 0.5) - mbx->window.pos.y);

	mbx_warp_cursor(mbx, vec2i_div(vec2i_mult(
				pos, mbx->viewport.size), mbx->window.size));
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
	if (mbx->settings.lock_cursor && mbx->window.is_focused)
		mbx_center_cursor(mbx);
}
