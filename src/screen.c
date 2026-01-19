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

#include "../includes/modules/types/mbx_s_mbx.h"

t_vec2i	get_screen_size(t_mbx *mbx, t_mbxwindow *window)
{
	t_vec2i	size;

	mlx_get_screen_size(mbx->mlx, window->win, &size.x, &size.y);
	return (size);
}
