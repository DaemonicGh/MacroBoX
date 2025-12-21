/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:51:29 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/21 10:36:09 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

#include <stdio.h>

void	window_hook(int event, void *param)
{
	t_mbxcontext	*mbx;

	if (event < 0 || event > MBX_WINDOW_SCANCODE_LENGTH)
		return ;
	mbx = param;
	if (event == MBX_WINDOW_CLOSE)
		mbx->inputs.should_exit = true;
	mbx->inputs.window[event] = true;
}
