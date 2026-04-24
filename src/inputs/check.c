/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:29:38 by rprieur           #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/mbx_s_mbx.h"

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
