/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:00:07 by daemo             #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "modules/mbx_handlers.h"
#include "modules/mbx_mlx.h"

void	mbx_exit(t_mbx *mbx)
{
	mlx_loop_end(mbx->mlx);
	mbx_destroy_region(mbx, mbx->viewport);
	if (mbx->window.mlx)
		mlx_destroy_window(mbx->mlx, mbx->window.mlx);
	mlx_destroy_context(mbx->mlx);
	free(mbx);
}
