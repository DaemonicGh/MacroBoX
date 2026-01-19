/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:42:32 by daemo             #+#    #+#             */
/*   Updated: 2026/01/19 16:43:39 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	wrap(int val, int low, int high)
{
	while (val >= high)
		val -= high;
	while (val < low)
		val += low;
	return (val);
}

double	fwrap(double val, double low, double high)
{
	while (val >= high)
		val -= high;
	while (val < low)
		val += low;
	return (val);
}

float	fwrapf(float val, float low, float high)
{
	while (val >= high)
		val -= high;
	while (val < low)
		val += low;
	return (val);
}

long double	fwrapl(long double val, long double low, long double high)
{
	while (val >= high)
		val -= high;
	while (val < low)
		val += low;
	return (val);
}
