/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:11:45 by daemo             #+#    #+#             */
/*   Updated: 2025/12/27 16:18:49 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

int	clamp(int val, int low, int high)
{
	return (max(min(val, high), low));
}

double	fclamp(double val, double low, double high)
{
	return (fmax(fmin(val, high), low));
}

float	fclampf(float val, float low, float high)
{
	return (fmaxf(fminf(val, high), low));
}

long double	fclampl(long double val, long double low, long double high)
{
	return (fmaxl(fminl(val, high), low));
}
