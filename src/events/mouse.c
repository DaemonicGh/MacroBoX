/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:51:18 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/21 10:36:09 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

void	mouse_down_hook(int button, void *param)
{
	t_mbxcontext	*mbx;

	if (button < 0 || button > MBX_BUTTON_SCANCODE_LENGTH)
		return ;
	mbx = param;
	if (mbx->inputs.btn[button])
		return ;
	mbx->inputs.btn[button] = true;
	mbx->inputs.btnp[button] = true;
}

void	mouse_up_hook(int button, void *param)
{
	t_mbxcontext	*mbx;

	if (button < 0 || button > MBX_BUTTON_SCANCODE_LENGTH)
		return ;
	mbx = param;
	mbx->inputs.btn[button] = false;
	mbx->inputs.btnr[button] = true;
}

void	mouse_wheel_hook(int button, void *param)
{
	t_mbxcontext	*mbx;

	if (button < 0 || button > 2)
		return ;
	mbx = param;
	if (button == 1)
		mbx->inputs.mouse_wheel = MBX_SCROLL_UP;
	else if (button == 2)
		mbx->inputs.mouse_wheel = MBX_SCROLL_DOWN;
}
