/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:24:54 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:42:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <math.h>
#include "../../includes/modules/types/veclc_s_vecn.h"

static int	putunbr(int fd, long nbr)
{
	int	size;

	size = 0;
	if (nbr > 9)
		size += putunbr(fd, nbr / 10);
	nbr = nbr % 10 + '0';
	size += write(fd, &nbr, 1);
	return (size);
}

int	putnbrf(int fd, double nbr, int precision)
{
	int	size;
	int	i;
	int	d;

	size = 0;
	if (nbr < 0)
	{
		size += write(fd, "-", 1);
		nbr = -nbr;
	}
	size += putunbr(fd, nbr);
	size += write(fd, ".", 1);
	if (precision > 6 || precision < 0)
		precision = 6;
	i = 0;
	while (i < precision && nbr - (long)nbr > pow(0.1, precision - i))
	{
		nbr *= 10;
		d = (int)nbr % 10 + '0';
		size += write(fd, &d, 1);
		i++;
	}
	return (size);
}

int	vec2_print(int fd, t_vec2 p, int precision)
{
	int	size;

	size = 0;
	size += write(fd, "vec2(", 5);
	size += putnbrf(fd, p.x, precision);
	size += write(fd, ",", 1);
	size += putnbrf(fd, p.y, precision);
	size += write(fd, ")", 1);
	return (size);
}

int	vec3_print(int fd, t_vec3 p, int precision)
{
	int	size;

	size = 0;
	size += write(fd, "vec3(", 5);
	size += putnbrf(fd, p.x, precision);
	size += write(fd, ",", 1);
	size += putnbrf(fd, p.y, precision);
	size += write(fd, ",", 1);
	size += putnbrf(fd, p.z, precision);
	size += write(fd, ")", 1);
	return (size);
}
