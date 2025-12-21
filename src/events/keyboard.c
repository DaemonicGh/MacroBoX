/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:51:10 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/21 10:36:09 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

void	key_down_hook(int key, void *param)
{
	t_mbxcontext	*mbx;

	if (key < 0 || key > MBX_KEY_SCANCODE_LENGTH)
		return ;
	mbx = param;
	if (mbx->inputs.key[key])
		return ;
	mbx->inputs.key[key] = true;
	mbx->inputs.keyp[key] = true;
	mbx->inputs.last_key = key;
}

void	key_up_hook(int key, void *param)
{
	t_mbxcontext	*mbx;

	if (key < 0 || key > MBX_KEY_SCANCODE_LENGTH)
		return ;
	mbx = param;
	mbx->inputs.key[key] = false;
	mbx->inputs.keyr[key] = true;
}
