/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:08:43 by daemo             #+#    #+#             */
/*   Updated: 2025/12/27 20:23:53 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

int	conv(int val, int goal, int incr)
{
	if (goal < val)
		val = max(val - incr, goal);
	else
		val = min(val + incr, goal);
	return (val);
}

double	fconv(double val, double goal, double incr)
{
	if (goal < val)
		val = fmax(val - incr, goal);
	else
		val = fmin(val + incr, goal);
	return (val);
}

float	fconvf(float val, float goal, float incr)
{
	if (goal < val)
		val = fmaxf(val - incr, goal);
	else
		val = fminf(val + incr, goal);
	return (val);
}

long double	fconvl(long double val, long double goal, long double incr)
{
	if (goal < val)
		val = fmaxl(val - incr, goal);
	else
		val = fminl(val + incr, goal);
	return (val);
}
