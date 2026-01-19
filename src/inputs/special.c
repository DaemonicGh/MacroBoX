/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:07:36 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 17:45:43 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/types/mbx_s_mbx.h"
#include "../../includes/modules/consts/mbx_c_scancodes.h"
#include "../../includes/modules/consts/mbx_c_other.h"

void	special_key_handler(t_mbx *mbx, int key)
{
	if ((mbx->settings.do_window_cross_exit && key == MBX_WINDOW_CLOSE)
		|| mbx->settings.exit_key == key)
		mbx->inputs.should_exit = true;
	else if (mbx->settings.fullscreen_toggle_key == key)
	{
		mbx->window.is_fullscreen = !mbx->window.is_fullscreen;
		mlx_set_window_fullscreen(mbx->mlx, mbx->window.win,
			mbx->window.is_fullscreen);
	}
}
