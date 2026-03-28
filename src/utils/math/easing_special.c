/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easing_special.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 01:05:58 by rprieur           #+#    #+#             */
/*   Updated: 2026/03/27 01:05:58 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_utils.h"

double	mbx_ease_poly(double t, double strength)
{
	if (strength >= 0)
		return (pow(t, strength + 1));
	return (1 - pow(1 - t, -strength + 1));
}

double	mbx_ease_bias(double t, double bias, double tension)
{
	const double	f = bias * 0.5 + 0.5;

	if (t == f)
		return (t);
	if (t < f)
		return (t + t * tension * (t / f - 1));
	t = 1 - t;
	return (1 - (t + t * tension * (t / (1 - f) - 1)));
}

double	mbx_ease_poly_bias(double t, double bias, double tension)
{
	const double	f = bias * 0.5 + 0.5;

	if (t < f)
		return (t + t * tension * (pow(t, fmax(bias, 1)) / fmin(f, 1) - 1));
	t = 1 - t;
	return (1 - (t + t * tension
			* (pow(t, fmax(-bias, 1)) / fmin(1 - f, 1) - 1)));
}
