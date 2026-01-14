/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:00:07 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:23:09 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/modules/mbx_mlx.h"
#include "../includes/modules/mbx_region.h"
#include "../includes/modules/mbx_font.h"

void	mbx_exit(t_mbx *mbx)
{
	mlx_loop_end(mbx->mlx);
	mbx_destroy_region(mbx, &mbx->viewport);
	mbx_destroy_font(mbx, &mbx->font);
	mlx_destroy_window(mbx->mlx, mbx->window.win);
	mlx_destroy_context(mbx->mlx);
	free(mbx);
}
