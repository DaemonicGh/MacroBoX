/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:51:18 by daemo             #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_inputs.h"

void	mouse_down_hook(int button, void *param)
{
	t_mbx	*mbx;

	button += MBX_INPUT_ARRAY_MOUSE_START;
	if (button < MBX_INPUT_ARRAY_MOUSE_START
		|| button > MBX_INPUT_ARRAY_MOUSE_END)
		return ;
	mbx = param;
	if (mbx_key_held(mbx, button))
		return ;
	mbx_press_input(mbx, button);
}

void	mouse_up_hook(int button, void *param)
{
	t_mbx	*mbx;

	button += MBX_INPUT_ARRAY_MOUSE_START;
	if (button < MBX_INPUT_ARRAY_MOUSE_START
		|| button > MBX_INPUT_ARRAY_MOUSE_END)
		return ;
	mbx = param;
	mbx_release_input(mbx, button);
}

void	mouse_wheel_hook(int button, void *param)
{
	t_mbx	*mbx;

	if (button < 0 || button > 2)
		return ;
	mbx = param;
	if (button == 1)
		mbx->scroll_delta += 1;
	else if (button == 2)
		mbx->scroll_delta -= 1;
}
