/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:42:32 by daemo             #+#    #+#             */
/*   Updated: 2025/12/27 17:39:51 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

int	loop(int val, int low, int high)
{
	while (val > high)
		val -= high;
	while (val < low)
		val += low;
	return (val);
}

double	floop(double val, double low, double high)
{
	while (val > high)
		val -= high;
	while (val < low)
		val += low;
	return (val);
}

float	floopf(float val, float low, float high)
{
	while (val > high)
		val -= high;
	while (val < low)
		val += low;
	return (val);
}

long double	floopl(long double val, long double low, long double high)
{
	while (val > high)
		val -= high;
	while (val < low)
		val += low;
	return (val);
}
