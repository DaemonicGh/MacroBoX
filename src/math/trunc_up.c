/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trunc_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:30:28 by rprieur           #+#    #+#             */
/*   Updated: 2026/03/11 14:30:28 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_math.h"

double	trunc_up(double val)
{
	if (val < 0)
		return (floor(val));
	return (ceil(val));
}

float	trunc_upf(float val)
{
	if (val < 0)
		return (floorf(val));
	return (ceilf(val));
}

long double	trunc_upl(long double val)
{
	if (val < 0)
		return (floorl(val));
	return (ceill(val));
}
