/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:11:45 by daemo             #+#    #+#             */
/*   Updated: 2026/04/29 23:26:08 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_utils.h"

int	clamp(int val, int low, int high)
{
	return (max(min(val, high), low));
}

double	fclamp(double val, double low, double high)
{
	return (fmax(fmin(val, high), low));
}
