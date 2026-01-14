/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:13:49 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:39:26 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/modules/types/mbx_s_mbx.h"

void	mbx_warp_mouse(t_mbx *mbx, int x, int y)
{
	mlx_mouse_move(mbx->mlx, mbx->window.win,
		x * mbx->window.width / mbx->viewport.width,
		y * mbx->window.height / mbx->viewport.height);
}
