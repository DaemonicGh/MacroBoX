/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:27:37 by daemo             #+#    #+#             */
/*   Updated: 2026/01/15 00:42:45 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

static int	putnbr(int fd, long nbr)
{
	int	size;

	size = 0;
	if (nbr < 0)
	{
		size += write(fd, "-", 1);
		nbr = -nbr;
	}
	size += putunbr(fd, nbr);
	return (size);
}

int	vec2i_print(int fd, t_vec2i p)
{
	int	size;

	size = 0;
	size += write(fd, "vec2i(", 6);
	size += putnbr(fd, p.x);
	size += write(fd, ",", 1);
	size += putnbr(fd, p.y);
	size += write(fd, ")", 1);
	return (size);
}

int	vec3i_print(int fd, t_vec3i p)
{
	int	size;

	size = 0;
	size += write(fd, "vec3i(", 6);
	size += putnbr(fd, p.x);
	size += write(fd, ",", 1);
	size += putnbr(fd, p.y);
	size += write(fd, ",", 1);
	size += putnbr(fd, p.z);
	size += write(fd, ")", 1);
	return (size);
}
