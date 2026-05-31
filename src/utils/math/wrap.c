/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 03:17:11 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	wrap(int val, int low, int high)
{
	while (val >= high)
		val -= high - low;
	while (val < low)
		val += high - low;
	return (val);
}

double	fwrap(double val, double low, double high)
{
	while (val >= high)
		val -= high - low;
	while (val < low)
		val += high - low;
	return (val);
}
