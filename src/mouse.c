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

#include "modules/types/mbx_s_mbx.h"

void	mbx_warp_mouse(t_mbx *mbx, t_vec2i pos)
{
	mlx_mouse_move(mbx->mlx, mbx->window.win,
		pos.x * mbx->window.size.x / mbx->viewport.size.x,
		pos.y * mbx->window.size.y / mbx->viewport.size.y);
}
