/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:29:38 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_core.h"

bool	mbx_key_pressed(t_mbx *mbx, int key)
{
	return (mbx->keys[key].press == 0);
}

bool	mbx_key_held(t_mbx *mbx, int key)
{
	return (mbx->keys[key].press <= mbx->keys[key].release);
}

bool	mbx_key_released(t_mbx *mbx, int key)
{
	return (mbx->keys[key].release == 0);
}
