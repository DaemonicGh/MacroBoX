/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 21:54:33 by daemo             #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_core.h"

t_vec2i	mbx_get_screen_size(t_mbx *mbx, t_mbx_window window)
{
	t_vec2i		size;

	mlx_get_screen_size(mbx->mlx, window.mlx, &size.x, &size.y);
	return (size);
}

t_vec2i	mbx_get_screen_size_windowless(t_mbx *mbx)
{
	mlx_window	temp_win;
	t_vec2i		size;

	temp_win = mlx_new_window(mbx->mlx,
			&(mlx_window_create_info){.title = "", 0});
	if (!temp_win)
		return (vec2i(0, 0));
	mlx_get_screen_size(mbx->mlx, temp_win, &size.x, &size.y);
	mlx_destroy_window(mbx->mlx, temp_win);
	return (size);
}
