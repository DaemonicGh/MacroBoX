/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:51:29 by daemo             #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_inputs.h"

void	window_hook(int event, void *param)
{
	t_mbx	*mbx;

	event += MBX_SCANCODES_WINDOW_START;
	if (event < MBX_SCANCODES_START
		|| event > MBX_SCANCODES_END)
		return ;
	mbx = param;
	mbx_tap_input(mbx, event);
}
