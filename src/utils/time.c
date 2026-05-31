/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 21:37:13 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

double	mbx_get_timestamp(void)
{
	struct timeval	time;

	if (gettimeofday(&time, 0) == -1)
		return (-1);
	return ((double)time.tv_sec + (double)time.tv_usec / 1000000.0);
}
