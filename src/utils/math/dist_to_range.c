/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_to_range.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 01:58:23 by rprieur           #+#    #+#             */
/*   Updated: 2026/03/07 01:58:23 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	range_dist(int x, int low, int high)
{
	if (x < low)
		return (low - x);
	if (x > high)
		return (x - high);
	return (0);
}

double	frange_dist(double x, double low, double high)
{
	if (x < low)
		return (low - x);
	if (x > high)
		return (x - high);
	return (0);
}
