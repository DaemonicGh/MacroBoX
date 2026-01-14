/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_towards.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:08:43 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:18:26 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../includes/modules/mbx_math.h"

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

float	fmove_towardsf(float val, float goal, float incr)
{
	if (goal < val)
		val = fmaxf(val - incr, goal);
	else
		val = fminf(val + incr, goal);
	return (val);
}

long double	fmove_towardsl(long double val, long double goal, long double incr)
{
	if (goal < val)
		val = fmaxl(val - incr, goal);
	else
		val = fminl(val + incr, goal);
	return (val);
}
