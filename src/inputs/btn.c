/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:28:28 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_core.h"

bool	mbx_btnp(t_mbx *mbx, int key)
{
	return (mbx->keys[key].press == 0);
}

bool	mbx_btn(t_mbx *mbx, int key)
{
	return (mbx->keys[key].press <= mbx->keys[key].release);
}

bool	mbx_btnr(t_mbx *mbx, int key)
{
	return (mbx->keys[key].release == 0);
}
