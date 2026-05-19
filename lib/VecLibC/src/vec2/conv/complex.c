/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 21:33:03 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 22:48:41 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <complex.h>
#include "modules/types/veclc_s_vec2.h"

complex double	vec2_complex(t_vec2 p)
{
	return (p.x + p.y * I);
}

complex int	vec2i_complex(t_vec2i p)
{
	return (p.x + p.y * I);
}
