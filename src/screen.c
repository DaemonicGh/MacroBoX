/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 21:54:33 by daemo             #+#    #+#             */
/*   Updated: 2025/12/27 21:56:47 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mbx.h"

t_vec2i	get_screen_size(t_mbxcontext *mbx)
{
	t_vec2i	size;

	mlx_get_screen_size(mbx->mlx, mbx->window.win, &size.x, &size.y);
	return (size);
}