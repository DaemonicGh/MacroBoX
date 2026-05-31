/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_vec4i.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:56:27 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 18:19:37 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdbool.h>

#include "types/veclc_s_vec4.h"

/**
 * Creates a new 4D vector containing zeros.
 */
t_vec4i		vec4i_zero(void);

/**
 * Creates a new 4D vector containing the given integer for all components.
 */
t_vec4i		vec4i_i(int xyzw);

/**
 * Adds two 4D vectors.
 */
t_vec4i		vec4i_add(t_vec4i p1, t_vec4i p2);

/**
 * Adds d to all components of a 4D vector.
 */
t_vec4i		vec4i_add_d(t_vec4i p, double d);

/**
 * Subtracts two 4D vectors.
 */
t_vec4i		vec4i_sub(t_vec4i p1, t_vec4i p2);

/**
 * Subtracts all components of a 4D vector by d.
 */
t_vec4i		vec4i_sub_d(t_vec4i p, double d);

/**
 * Subtracts d to all components of a 4D vector.
 */
t_vec4i		vec4i_sub_rd(double d, t_vec4i p);

/**
 * Multiplies two 4D vectors.
 */
t_vec4i		vec4i_mult(t_vec4i p1, t_vec4i p2);

/**
 * Multiplies all components of a 4D vector by d.
 */
t_vec4i		vec4i_mult_d(t_vec4i p, double d);

/**
 * Multiplies two 4D vectors, one having float precision.
 */
t_vec4i		vec4i_mult_vd(t_vec4i p1, t_vec4 p2);

/**
 * Divides two 4D vectors.
 */
t_vec4i		vec4i_div(t_vec4i p1, t_vec4i p2);

/**
 * Divides all components of a 4D vector by d.
 */
t_vec4i		vec4i_div_d(t_vec4i p, double d);

/**
 * Divides d by all components of a 4D vector.
 */
t_vec4i		vec4i_div_rd(double value, t_vec4i p);

/**
 * Divides two 4D vectors, one having float precision.
 */
t_vec4i		vec4i_div_vd(t_vec4i p1, t_vec4 p2);

/**
 * Divides two 4D vectors, one having float precision.
 */
t_vec4i		vec4i_div_rvd(t_vec4 p1, t_vec4i p2);

/**
 * Divides two 4D vectors and keeps the result's float precision.
 */
t_vec4		vec4i_truediv(t_vec4i p1, t_vec4i p2);

/**
 * Divides all components of a 4D vector by d
 * and keeps the result's float precision.
 */
t_vec4		vec4i_truediv_d(t_vec4i p, double d);

/**
 * Divides d by all components of a 4D vector
 * and keeps the result's float precision.
 */
t_vec4		vec4i_truediv_rd(double d, t_vec4i p);

/**
 * Returns the remainder of the division between two 4D vectors.
 */
t_vec4i		vec4i_mod(t_vec4i p1, t_vec4i p2);

/**
 * Returns the remainder of the division between
 * all components of a 4D vector and i.
 */
t_vec4i		vec4i_mod_i(t_vec4i p, int i);

/**
 * Returns the remainder of the division between
 * i and all components of a 4D vector.
 */
t_vec4i		vec4i_mod_ri(int i, t_vec4i p);

/**
 * Returns the remainder of the division between
 * all components of a 4D vector and d.
 */
t_vec4i		vec4i_mod_d(t_vec4i p, double d);

/**
 * Returns the remainder of the division between
 * d and all components of a 4D vector.
 */
t_vec4i		vec4i_mod_rd(double d, t_vec4i p);

/**
 * Negates a 4D vector.
 */
t_vec4i		vec4i_neg(t_vec4i p);

/**
 * Squares a 4D vector.
 */
t_vec4i		vec4i_square(t_vec4i p);

/**
 * Returns a 4D vector with absolute values
 * of all components of a vector.
 */
t_vec4i		vec4i_abs(t_vec4i p);

/**
 * Returns a 4D vector with the result
 * of all components of a vector through f.
 */
t_vec4i		vec4i_exec(int (*f)(int), t_vec4i p);

/**
 * Returns a 4D vector with the result
 * of all components of two vectors through f.
 */
t_vec4i		vec4i_exec2(int (*f)(int, int), t_vec4i p1, t_vec4i p2);

/**
 * Returns a 4D vector with the result
 * of all components of three vectors through f.
 */
t_vec4i		vec4i_exec3(int (*f)(int, int, int),
				t_vec4i p1, t_vec4i p2, t_vec4i p3);

/**
 * Returns the result all components of a vector through f.
 */
int			vec4i_exec_xyzw(int (*f)(int, int, int, int), t_vec4i p1);

/**
 * Returns the result all components of a vector through f ((x, y), (z, w)).
 */
int			vec4i_exec_xy_zw(int (*f)(int, int), t_vec4i p1);

/**
 *  Returns true if all components of two 4D vectors are equal.
 */
bool		vec4i_eq(t_vec4i p1, t_vec4i p2);

/**
 * Returns true if all components of a 4D vector are zero.
 */
bool		vec4i_is_zero(t_vec4i p);

/**
 * Returns the length(magnitude) of a 4D vector.
 */
double		vec4i_length(t_vec4i p);

/**
 * Normalizes a 4D vector.
 */
t_vec4		vec4i_normalize(t_vec4i p);

/**
 * Returns the euclidean distance between two 4D vectors.
 */
double		vec4i_dist(t_vec4i p1, t_vec4i p2);

/**
 * Returns the dot product of two 4D vectors.
 */
double		vec4i_dot(t_vec4i p1, t_vec4i p2);
