/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:55:33 by rprieur           #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_inputs.h"
#include "modules/mbx_handlers.h"
#include "../../_private/mbx_internal.h"

void	enter_loop(t_mbx *mbx)
{
	update_time_values(mbx);
	mbx_refresh_settings(mbx);
	if (mbx->settings.lock_cursor)
		mbx_warp_cursor(mbx, vec2i_div_d(mbx->viewport->size, 2));
}

void	exit_loop(t_mbx *mbx)
{
	(void)mbx;
}
