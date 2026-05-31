/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 20:56:16 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "modules/mbx_utils.h"

void	seedrand(unsigned long seed)
{
	static bool	seeded = false;

	if (seed)
	{
		seed <<= 16;
		seed48((unsigned short *)(&seed));
		return ;
	}
	if (!seeded)
	{
		seed48((unsigned short *)"#mbxRD");
		seeded = true;
	}
}

int	randi(int min, int max)
{
	seedrand(0);
	return (lerp(min, max + 1, drand48()));
}

double	randf(double min, double max)
{
	seedrand(0);
	return (flerp(min, max, drand48()));
}
