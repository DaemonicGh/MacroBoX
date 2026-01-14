/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:24:30 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:18:32 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sign(int val)
{
	if (val > 0)
		return (1);
	if (val < 0)
		return (-1);
	return (0);
}

int	fsign(double val)
{
	if (val > 0)
		return (1);
	if (val < 0)
		return (-1);
	return (0);
}

int	fsignf(float val)
{
	if (val > 0)
		return (1);
	if (val < 0)
		return (-1);
	return (0);
}

int	fsignl(long double val)
{
	if (val > 0)
		return (1);
	if (val < 0)
		return (-1);
	return (0);
}
