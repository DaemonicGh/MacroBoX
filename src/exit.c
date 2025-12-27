/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:00:07 by rprieur           #+#    #+#             */
/*   Updated: 2025/12/22 22:32:35 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mbx.h"

void	mbx_exit(t_mbxcontext *mbx)
{
	mlx_loop_end(mbx->mlx);
	mlx_destroy_image(mbx->mlx, mbx->viewport.image);
	mlx_destroy_window(mbx->mlx, mbx->viewport.win);
	mlx_destroy_window(mbx->mlx, mbx->window.win);
	mlx_destroy_context(mbx->mlx);
	free(mbx);
}
