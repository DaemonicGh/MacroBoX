/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_loopcontext.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:08:05 by rprieur           #+#    #+#             */
/*   Updated: 2026/02/08 08:54:24 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../../includes/modules/types/mbx_s_mbx.h"

typedef struct s__mbxloopcontext
{
	t_mbx	*mbx;
	void	(*update)(t_mbx *mbx, void *args);
	void	*args;
}	t__mbxloopcontext;
