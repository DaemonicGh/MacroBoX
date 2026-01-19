/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_s_vec2xn.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:36:46 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 13:46:22 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECLC_S_VEC2XN_H
# define VECLC_S_VEC2XN_H

# include "veclc_s_vec2.h"

/**
 * Group of two 2D vectors containing doubles.
 */
typedef struct s_vec2x2
{
	t_vec2	p1;
	t_vec2	p2;
}	t_vec2x2;

/**
 * Group of three 2D vectors containing doubles.
 */
typedef struct s_vec2x3
{
	t_vec2	p1;
	t_vec2	p2;
	t_vec2	p3;
}	t_vec2x3;

/**
 * Group of four 2D vectors containing doubles.
 */
typedef struct s_vec2x4
{
	t_vec2	p1;
	t_vec2	p2;
	t_vec2	p3;
	t_vec2	p4;
}	t_vec2x4;

/**
 * Creates a group of two 2D vectors containing doubles.
 */
t_vec2x2	vec2x2(t_vec2 p1, t_vec2 p2);

/**
 * Creates a group of two 2D vectors containing doubles.
 */
t_vec2x2	vec2x2_xy(int x1, int y1, int x2, int y2);

/**
 * Creates a group of three 2D vectors containing doubles.
 */
t_vec2x3	vec2x3(t_vec2 p1, t_vec2 p2, t_vec2 p3);

/**
 * Creates a group of four 2D vectors containing doubles.
 */
t_vec2x4	vec2x4(t_vec2 p1, t_vec2 p2, t_vec2 p3, t_vec2 p4);

#endif
