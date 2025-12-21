/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:51:10 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/21 19:04:31 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

void	key_down_hook(int key, void *param)
{
	t_mbxcontext	*mbx;

	key += MBX_INPUT_ARRAY_KEYBOARD_START;
	if (key < MBX_INPUT_ARRAY_KEYBOARD_START || key > MBX_INPUT_ARRAY_KEYBOARD_END)
		return ;
	mbx = param;
	if (mbx->inputs.btn[key])
		return ;
	mbx->inputs.btn[key] = true;
	mbx->inputs.btnp[key] = true;
	mbx->inputs.last_key = key;
}

void	key_up_hook(int key, void *param)
{
	t_mbxcontext	*mbx;

	key += MBX_INPUT_ARRAY_KEYBOARD_START;
	if (key < MBX_INPUT_ARRAY_KEYBOARD_START || key > MBX_INPUT_ARRAY_KEYBOARD_END)
		return ;
	mbx = param;
	mbx->inputs.btn[key] = false;
	mbx->inputs.btnr[key] = true;
}
