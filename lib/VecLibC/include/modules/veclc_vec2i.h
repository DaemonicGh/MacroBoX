/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_vec2i.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:56:23 by rprieur           #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdbool.h>
#include <complex.h>

#include "types/veclc_s_vec2.h"

/**
 * Creates a new 2D vector containing zeros.
 */
t_vec2i		vec2i_zero(void);

/**
 * Creates a new 2D vector containing the given integer for both components.
 */
t_vec2i		vec2i_i(int xy);

/**
 * Adds two 2D vectors.
 */
t_vec2i		vec2i_add(t_vec2i p1, t_vec2i p2);

/**
 * Adds d to both components of a 2D vector.
 */
t_vec2i		vec2i_add_d(t_vec2i p, double d);

/**
 * Subtracts two 2D vectors.
 */
t_vec2i		vec2i_sub(t_vec2i p1, t_vec2i p2);

/**
 * Subtracts both components of a 2D vector by d.
 */
t_vec2i		vec2i_sub_d(t_vec2i p, double d);

/**
 * Subtracts d to both components of a 2D vector.
 */
t_vec2i		vec2i_sub_rd(double d, t_vec2i p);

/**
 * Multiplies two 2D vectors.
 */
t_vec2i		vec2i_mult(t_vec2i p1, t_vec2i p2);

/**
 * Multiplies both components of a 2D vector by d.
 */
t_vec2i		vec2i_mult_d(t_vec2i p, double d);

/**
 * Multiplies two 2D vectors, one having float precision.
 */
t_vec2i		vec2i_mult_vd(t_vec2i p1, t_vec2 p2);

/**
 * Divides two 2D vectors.
 */
t_vec2i		vec2i_div(t_vec2i p1, t_vec2i p2);

/**
 * Divides both components of a 2D vector by d.
 */
t_vec2i		vec2i_div_d(t_vec2i p, double d);

/**
 * Divides d by both components of a 2D vector.
 */
t_vec2i		vec2i_div_rd(double d, t_vec2i p);

/**
 * Divides two 2D vectors, one having float precision.
 */
t_vec2i		vec2i_div_vd(t_vec2i p1, t_vec2 p2);

/**
 * Divides two 2D vectors, one having float precision.
 */
t_vec2i		vec2i_div_rvd(t_vec2 p1, t_vec2i p2);

/**
 * Divides two 2D vectors and keeps the result's float precision.
 */
t_vec2		vec2i_truediv(t_vec2i p1, t_vec2i p2);

/**
 * Divides both components of a 2D vector by d
 * and keeps the result's float precision.
 */
t_vec2		vec2i_truediv_d(t_vec2i p, double d);

/**
 * Divides d by both components of a 2D vector
 * and keeps the result's float precision.
 */
t_vec2		vec2i_truediv_rd(double d, t_vec2i p);

/**
 * Returns the remainder of the division between two 2D vectors.
 */
t_vec2i		vec2i_mod(t_vec2i p1, t_vec2i p2);

/**
 * Returns the remainder of the division between
 * both components of a 2D vector and i.
 */
t_vec2i		vec2i_mod_i(t_vec2i p, int i);

/**
 * Returns the remainder of the division between
 * i and both components of a 2D vector.
 */
t_vec2i		vec2i_mod_ri(int i, t_vec2i p);

/**
 * Returns the remainder of the division between
 * both components of a 2D vector and d.
 */
t_vec2i		vec2i_mod_d(t_vec2i p, double d);

/**
 * Returns the remainder of the division between
 * d and both components of a 2D vector.
 */
t_vec2i		vec2i_mod_rd(double d, t_vec2i p);

/**
 * Negates a 2D vector.
 */
t_vec2i		vec2i_neg(t_vec2i p);

/**
 * Squares a 2D vector.
 */
t_vec2i		vec2i_square(t_vec2i p);

/**
 * Returns a 2D vector with absolute values
 * of both components of a vector.
 */
t_vec2i		vec2i_abs(t_vec2i p);

/**
 * Returns a 2D vector with the result
 * of both components of a vector through f.
 */
t_vec2i		vec2i_exec(int (*f)(int), t_vec2i p);

/**
 * Returns a 2D vector with the result
 * of both components of two vectors through f.
 */
t_vec2i		vec2i_exec2(int (*f)(int, int), t_vec2i p1, t_vec2i p2);

/**
 * Returns a 2D vector with the result
 * of both components of three vectors through f.
 */
t_vec2i		vec2i_exec3(int (*f)(int, int, int),
				t_vec2i p1, t_vec2i p2, t_vec2i p3);

/**
 * Returns the result of both components of a vector through f.
 */
int			vec2i_exec_xy(int (*f)(int, int), t_vec2i p1);

/**
 * Returns true if both components of two 2D vectors are equal.
 */
bool		vec2i_eq(t_vec2i p1, t_vec2i p2);

/**
 * Returns true if both components of a 2D vector are zero.
 */
bool		vec2i_is_zero(t_vec2i p);

/**
 * Returns the length(magnitude) of a 2D vector.
 */
double		vec2i_length(t_vec2i p);

/**
 * Normalizes a 2D vector.
 */
t_vec2		vec2i_normalize(t_vec2i p);

/**
 * Returns the euclidean distance between two 2D vectors.
 */
double		vec2i_dist(t_vec2i p1, t_vec2i p2);

/**
 * Returns the dot product of two 2D vectors.
 */
double		vec2i_dot(t_vec2i p1, t_vec2i p2);

/**
 * Converts a 2D vector to a complex number.
 */
complex int	vec2i_complex(t_vec2i p);
