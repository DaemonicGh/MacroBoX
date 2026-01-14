/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:51:29 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:13:52 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/types/mbx_s_mbx.h"
#include "../../includes/modules/consts/mbx_c_scancodes.h"

void	window_hook(int event, void *param)
{
	t_mbx	*mbx;

	event += MBX_INPUT_ARRAY_WINDOW_START;
	if (event < MBX_INPUT_ARRAY_WINDOW_START
		|| event > MBX_INPUT_ARRAY_WINDOW_END)
		return ;
	mbx = param;
	if (event == MBX_WINDOW_CLOSE)
		mbx->inputs.should_exit = true;
	mbx->inputs.btnp[event] = true;
}
