/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lerp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 15:39:34 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:17:51 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	lerp(int start, int end, double delta)
{
	return ((1 - delta) * start + delta * end);
}

double	flerp(double start, double end, double delta)
{
	return ((1 - delta) * start + delta * end);
}

float	flerpf(float start, float end, double delta)
{
	return ((1 - delta) * start + delta * end);
}

long double	flerpl(long double start, long double end, long double delta)
{
	return ((1 - delta) * start + delta * end);
}
