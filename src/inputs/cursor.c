/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:13:49 by daemo             #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/mbx_s_mbx.h"
#include "modules/mbx_utils.h"

void	mbx_warp_cursor(t_mbx *mbx, t_vec2i pos)
{
	t_vec2i	new_pos;

	mlx_mouse_move(mbx->mlx, mbx->window.mlx,
		round((double)pos.x * mbx->window.size.x / mbx->viewport->size.x),
		round((double)pos.y * mbx->window.size.y / mbx->viewport->size.y));
	mlx_mouse_get_pos(mbx->mlx, &new_pos.x, &new_pos.y);
	mbx->cursor = vec2_mult(vec2_vi(new_pos),
			vec2i_truediv(mbx->viewport->size, mbx->window.size));
}

void	mbx_move_cursor(t_mbx *mbx, t_vec2i pos)
{
	mbx_warp_cursor(mbx, pos);
	mbx->cursor_delta = vec2_add(mbx->cursor_delta,
			vec2_sub(vec2_vi(pos), mbx->cursor));
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
				pos, mbx->viewport->size), mbx->window.size));
}

void	refresh_cursor(t_mbx *mbx)
{
	const t_vec2	prev_pos = mbx->cursor;
	t_vec2i			new_pos;

	mlx_mouse_get_pos(mbx->mlx, &new_pos.x, &new_pos.y);
	mbx->cursor = vec2_mult(vec2_vi(new_pos),
			vec2i_truediv(mbx->viewport->size, mbx->window.size));
	mbx->cursor_delta.x = mbx->cursor.x - prev_pos.x;
	mbx->cursor_delta.y = mbx->cursor.y - prev_pos.y;
	if (mbx->settings.lock_cursor && mbx->window.is_focused)
		mbx_center_cursor(mbx);
}
