/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:57:58 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/06 00:39:29 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*palloc(size_t size, int value)
{
	int	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	while (--size)
		ptr[size] = value;
	return (ptr);
}
