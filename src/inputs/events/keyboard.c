/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:51:10 by daemo             #+#    #+#             */
/*   Updated: 2026/01/19 17:13:39 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_inputs.h"

void	key_down_hook(int key, void *param)
{
	t_mbx	*mbx;

	key += MBX_INPUT_ARRAY_KEYBOARD_START;
	if (key < MBX_INPUT_ARRAY_KEYBOARD_START
		|| key > MBX_INPUT_ARRAY_KEYBOARD_END)
		return ;
	mbx = param;
	if (mbx->presses[key] > 0)
		return ;
	mbx_press_input(mbx, key);
}

void	key_up_hook(int key, void *param)
{
	t_mbx	*mbx;

	key += MBX_INPUT_ARRAY_KEYBOARD_START;
	if (key < MBX_INPUT_ARRAY_KEYBOARD_START
		|| key > MBX_INPUT_ARRAY_KEYBOARD_END)
		return ;
	mbx = param;
	mbx_release_input(mbx, key);
}
