/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:29:38 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 16:42:20 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/types/mbx_s_mbx.h"

bool	mbx_key_pressed(t_mbx *mbx, int key)
{
	return (mbx->inputs.btnp[key]);
}

bool	mbx_key_held(t_mbx *mbx, int key)
{
	return (mbx->inputs.btn[key] || mbx->inputs.btnp[key]);
}

bool	mbx_key_released(t_mbx *mbx, int key)
{
	return (mbx->inputs.btnp[key]);
}
