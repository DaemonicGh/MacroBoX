/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:51:29 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/21 19:07:23 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

void	window_hook(int event, void *param)
{
	t_mbxcontext	*mbx;

	event += MBX_INPUT_ARRAY_WINDOW_START;
	if (event < MBX_INPUT_ARRAY_WINDOW_START || event > MBX_INPUT_ARRAY_WINDOW_END)
		return ;
	mbx = param;
	if (event == MBX_WINDOW_CLOSE)
		mbx->inputs.should_exit = true;
	mbx->inputs.btnp[event] = true;
}
