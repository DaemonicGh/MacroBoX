/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:51:10 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:12:36 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/types/mbx_s_mbx.h"

void	key_down_hook(int key, void *param)
{
	t_mbx	*mbx;

	key += MBX_INPUT_ARRAY_KEYBOARD_START;
	if (key < MBX_INPUT_ARRAY_KEYBOARD_START
		|| key > MBX_INPUT_ARRAY_KEYBOARD_END)
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
	t_mbx	*mbx;

	key += MBX_INPUT_ARRAY_KEYBOARD_START;
	if (key < MBX_INPUT_ARRAY_KEYBOARD_START
		|| key > MBX_INPUT_ARRAY_KEYBOARD_END)
		return ;
	mbx = param;
	mbx->inputs.btn[key] = false;
	mbx->inputs.btnr[key] = true;
}
