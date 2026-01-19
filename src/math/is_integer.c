/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 05:09:19 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 11:56:26 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

bool	is_integer(double val)
{
	return (val == floor(val));
}

bool	is_integerf(float val)
{
	return (val == floorf(val));
}

bool	is_integerl(long double val)
{
	return (val == floorl(val));
}
