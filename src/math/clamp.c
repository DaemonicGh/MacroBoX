/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:11:45 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:17:41 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../includes/modules/mbx_math.h"

int	clamp(int val, int low, int high)
{
	return (max(min(val, high), low));
}

double	fclamp(double val, double low, double high)
{
	return (fmax(fmin(val, high), low));
}

float	fclampf(float val, float low, float high)
{
	return (fmaxf(fminf(val, high), low));
}

long double	fclampl(long double val, long double low, long double high)
{
	return (fmaxl(fminl(val, high), low));
}
