/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:13:49 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/02 14:36:02 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mbx.h"

void	mbx_warp_mouse(t_mbx *mbx, int x, int y)
{
	mlx_mouse_move(mbx->mlx, mbx->window.win,
		x * mbx->window.width / mbx->viewport.width,
		y * mbx->window.height / mbx->viewport.height);
}
