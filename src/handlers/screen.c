/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 21:54:33 by daemo             #+#    #+#             */
/*   Updated: 2026/01/18 11:44:01 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/mbx_s_mbx.h"

t_vec2i	get_screen_size_windowless(t_mbx *mbx)
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
