/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 00:46:09 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/09 01:55:08 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

double	get_sec_since_epoch(void)
{
	struct timeval	time;

	if (gettimeofday(&time, 0) == -1)
		return (-1);
	return ((double)time.tv_sec + (double)time.tv_usec / 1000000.0);
}
