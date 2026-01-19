/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:13:49 by daemo             #+#    #+#             */
/*   Updated: 2026/01/19 14:55:18 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/modules/types/mbx_s_mbx.h"

void	mbx_warp_mouse(t_mbx *mbx, t_vec2i pos)
{
	mlx_mouse_move(mbx->mlx, mbx->window.win,
		pos.x * mbx->window.size.x / mbx->viewport.size.x,
		pos.y * mbx->window.size.y / mbx->viewport.size.y);
}

void	mbx_warp_mouse_xy(t_mbx *mbx, int x, int y)
{
	mlx_mouse_move(mbx->mlx, mbx->window.win,
		x * mbx->window.size.x / mbx->viewport.size.x,
		y * mbx->window.size.y / mbx->viewport.size.y);
}
