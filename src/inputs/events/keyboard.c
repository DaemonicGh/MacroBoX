/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:51:10 by daemo             #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_inputs.h"

void	key_down_hook(int key, void *param)
{
	t_mbx	*mbx;

	key += MBX_SCANCODES_KEYBOARD_START;
	if (key < MBX_SCANCODES_START
		|| key > MBX_SCANCODES_END)
		return ;
	mbx = param;
	if (!mbx_key_held(mbx, key))
		mbx_press_input(mbx, key);
	mbx_text_input_add(mbx, key);
}

void	key_up_hook(int key, void *param)
{
	t_mbx	*mbx;

	key += MBX_SCANCODES_KEYBOARD_START;
	if (key < MBX_SCANCODES_START
		|| key > MBX_SCANCODES_END)
		return ;
	mbx = param;
	mbx_release_input(mbx, key);
}
