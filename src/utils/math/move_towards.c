/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_towards.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 03:18:45 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_utils.h"

int	move_towards(int val, int goal, int incr)
{
	if (goal < val)
		val = max(val - incr, goal);
	else
		val = min(val + incr, goal);
	return (val);
}

double	fmove_towards(double val, double goal, double incr)
{
	if (goal < val)
		val = fmax(val - incr, goal);
	else
		val = fmin(val + incr, goal);
	return (val);
}
