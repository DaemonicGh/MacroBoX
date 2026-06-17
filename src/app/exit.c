/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:00:07 by daemo             #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../_private/mbx_internal.h"

void	mbx_exit(t_mbx *mbx)
{
	if (!mbx)
		return ;
	mlx_loop_end(mbx->mlx);
	destroy_allocator(mbx);
	mbx_report_nbr(mbx, "Cleared ", mbx->allocator.alloc_count,
		" memory blocks upon exit");
	mlx_destroy_context(mbx->mlx);
	mbx_report(mbx, "Successfully exited");
	free(mbx);
}
