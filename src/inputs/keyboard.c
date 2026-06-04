/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 03:13:31 by rprieur           #+#    #+#             */
/*   Updated: 2026/06/03 03:13:31 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_constants.h"
#include "modules/mbx_inputs.h"
#include <stddef.h>
#include <stdio.h>

static bool	text_input_add_char(t_mbx *mbx, char c)
{
	size_t		i;

	if (!c)
		return (false);
	i = 0;
	while (i < MBX_TEXT_INPUT_ARRAY_SIZE)
	{
		if (!mbx->text_input[i])
		{
			mbx->text_input[i] = c;
			return (true);
		}
		i++;
	}
	return (false);
}

bool	mbx_text_input_add(t_mbx *mbx, int key)
{
	const char	*layouts[8] = {
		MBX_TEXT_LAYOUT_QWERTY, MBX_TEXT_LAYOUT_QWERTY_SHIFT,
		MBX_TEXT_LAYOUT_QWERTY_FR_ALTGR, MBX_TEXT_LAYOUT_QWERTY_FR_SHIFT_ALTGR,
		MBX_TEXT_LAYOUT_AZERTY_FR, MBX_TEXT_LAYOUT_AZERTY_FR_SHIFT,
		MBX_TEXT_LAYOUT_AZERTY_FR_ALTGR, MBX_TEXT_LAYOUT_AZERTY_FR_SHIFT_ALTGR
	};
	int			layout;

	if (key < MBX_SCANCODES_TEXT_START
		|| key > MBX_SCANCODES_TEXT_END)
		return (false);
	key -= MBX_SCANCODES_TEXT_START;
	layout = 0;
	if (mbx->settings.use_azerty)
		layout += 4;
	if (mbx_key_held(mbx, MBX_KEY_RALT))
		layout += 2;
	if (mbx_key_held(mbx, MBX_KEY_LSHIFT)
		|| mbx_key_held(mbx, MBX_KEY_RSHIFT)
		|| mbx->caps_lock_on)
		layout += 1;
	return (text_input_add_char(mbx, layouts[layout][key]));
}
