/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:51:29 by daemo             #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_inputs.h"

void	window_hook(int event, void *param)
{
	t_mbx	*mbx;

	event += MBX_INPUT_ARRAY_WINDOW_START;
	if (event < MBX_INPUT_ARRAY_WINDOW_START
		|| event > MBX_INPUT_ARRAY_WINDOW_END)
		return ;
	mbx = param;
	mbx_tap_input(mbx, event);
}
