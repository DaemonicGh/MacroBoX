/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 03:03:45 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_utils.h"

double	mbx_ease_in(double t)
{
	return (t * t);
}

double	mbx_ease_out(double t)
{
	return (1 - (1 - t) * (1 - t));
}

double	mbx_ease_in_out(double t)
{
	if (t < 0.5)
		return (2 * t * t);
	t -= 0.5;
	return (2 * t * (1 - t) + 0.5);
}
