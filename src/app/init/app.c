/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:20:24 by daemo             #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "modules/mbx_app.h"
#include "modules/mbx_handlers.h"
#include "../../_private/mbx_internal.h"

t_mbx	*mbx_init_windowless(void)
{
	t_mbx	*mbx;

	mbx = malloc(sizeof(t_mbx));
	if (!mbx)
		return (NULL);
	*mbx = (t_mbx){0};
	mbx->mlx = mlx_init();
	if (!mbx->mlx)
	{
		free(mbx);
		return (NULL);
	}
	mbx_reset_settings(mbx);
	reset_inputs(mbx);
	init_values(mbx);
	mbx_report(mbx, "Successfully initialized in debug mode");
	return (mbx);
}

t_mbx	*mbx_init_from_mlx(mlx_context mlx)
{
	t_mbx	*mbx;

	mbx = malloc(sizeof(t_mbx));
	if (!mbx)
		return (NULL);
	*mbx = (t_mbx){0};
	mbx->mlx = mlx;
	mbx_reset_settings(mbx);
	reset_inputs(mbx);
	init_values(mbx);
	return (mbx);
}

t_mbx	*mbx_init(t_vec2i viewport_size, char *win_title, unsigned int flags)
{
	t_mbx	*mbx;

	mbx = mbx_init_windowless();
	if (!mbx)
		return (NULL);
	if (!mbx_create_main_window(mbx, viewport_size, win_title, flags))
	{
		mlx_destroy_context(mbx->mlx);
		free(mbx);
		return (NULL);
	}
	return (mbx);
}
