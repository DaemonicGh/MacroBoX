/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_s_vec2i.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:26:48 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 13:43:42 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECLC_S_VEC2I_H
# define VECLC_S_VEC2I_H

/**
 * 2D vector containing integers.
 */
typedef struct s_vec2i
{
	int	x;
	int	y;
}	t_vec2i;

/**
 * Creates a new 2D vector containing integers.
 */
t_vec2i		vec2i(int x, int y);

#endif
