/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecx2_xy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 22:54:00 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:42:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/modules/types/veclc_s_vecnxn.h"

t_vec2x2	vec2x2_xy(int x1, int y1, int x2, int y2)
{
	return ((t_vec2x2){.p1 = vec2(x1, y1), .p2 = vec2(x2, y2)});
}

t_vec2ix2	vec2ix2_xy(int x1, int y1, int x2, int y2)
{
	return ((t_vec2ix2){.p1 = vec2i(x1, y1), .p2 = vec2i(x2, y2)});
}
