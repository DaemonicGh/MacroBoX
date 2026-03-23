/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:28:28 by rprieur           #+#    #+#             */
/*   Updated: 2026/03/19 10:28:28 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/mbx_s_mbx.h"

bool	mbx_btnp(t_mbx *mbx, int key)
{
	return (mbx->key_presses[key] == 0);
}

bool	mbx_btn(t_mbx *mbx, int key)
{
	return (mbx->key_presses[key] <= mbx->key_releases[key]);
}

bool	mbx_btnr(t_mbx *mbx, int key)
{
	return (mbx->key_releases[key] == 0);
}
