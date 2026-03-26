/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 03:03:45 by rprieur           #+#    #+#             */
/*   Updated: 2026/03/26 03:03:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_utils.h"

double	mbx_ease_in(double x)
{
	return (x * x);
}

double	mbx_ease_out(double x)
{
	return (1 - (1 - x) * (1 - x));
}

double	mbx_ease_in_out(double x)
{
	if (x < 0.5)
		return (2 * x * x);
	else
		return ((-2 * x + 2) * (-2 * x + 2) / 2);
}
