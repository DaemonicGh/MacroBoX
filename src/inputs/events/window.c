/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:51:29 by daemo             #+#    #+#             */
/*   Updated: 2026/01/19 17:14:28 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/modules/types/mbx_s_mbx.h"
#include "../../../includes/modules/consts/mbx_c_scancodes.h"
#include "../../headers/mbx_internal.h"

void	window_hook(int event, void *param)
{
	t_mbx	*mbx;

	event += MBX_INPUT_ARRAY_WINDOW_START;
	if (event < MBX_INPUT_ARRAY_WINDOW_START
		|| event > MBX_INPUT_ARRAY_WINDOW_END)
		return ;
	mbx = param;
	mbx->inputs.btnp[event] = true;
	special_key_handler(mbx, event);
}
