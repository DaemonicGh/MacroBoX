/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_s_vec2.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:26:43 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 13:43:50 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECLC_S_VEC2_H
# define VECLC_S_VEC2_H

/**
 * 2D vector containing doubles.
 */
typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

/**
 * Creates a new 2D vector containing doubles.
 */
t_vec2		vec2(double x, double y);

#endif
