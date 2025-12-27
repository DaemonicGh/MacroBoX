/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:28:29 by daemo             #+#    #+#             */
/*   Updated: 2025/12/27 21:24:29 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mbx.h"

void	mbx_reset_settings(t_mbxcontext *mbx)
{
	mbx->settings.fps_cap = 60;
	mbx->settings.viewport_mode = MBX_VIEWPORT_MODE_KEEP;
}

void	mbx_refresh_settings(t_mbxcontext *mbx)
{
	mlx_set_fps_goal(mbx->mlx, mbx->settings.fps_cap);
}
