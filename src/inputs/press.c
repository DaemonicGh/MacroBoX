/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:20:38 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 17:13:03 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/types/mbx_s_mbx.h"
#include "../../includes/modules/consts/mbx_c_input_arrays.h"
#include "../headers/mbx_internal.h"

void	mbx_press_key(t_mbx *mbx, int key)
{
	if (key < MBX_INPUT_ARRAY_KEYBOARD_START
		|| key > MBX_INPUT_ARRAY_KEYBOARD_END)
		return ;
	mbx->inputs.btnp[key] = true;
	mbx->inputs.btnr[key] = true;
	mbx->inputs.last_key = key;
	special_key_handler(mbx, key);
}

void	mbx_hold_key(t_mbx *mbx, int key)
{
	if (key < MBX_INPUT_ARRAY_KEYBOARD_START
		|| key > MBX_INPUT_ARRAY_KEYBOARD_END)
		return ;
	if (mbx->inputs.btn[key])
		mbx->inputs.btnr[key] = true;
	mbx->inputs.btnp[key] = true;
	mbx->inputs.btn[key] = true;
	mbx->inputs.last_key = key;
	special_key_handler(mbx, key);
}

void	mbx_release_key(t_mbx *mbx, int key)
{
	if (key < MBX_INPUT_ARRAY_KEYBOARD_START
		|| key > MBX_INPUT_ARRAY_KEYBOARD_END)
		return ;
	if (mbx->inputs.btn[key])
		mbx->inputs.btnr[key] = true;
	mbx->inputs.btn[key] = false;
}
