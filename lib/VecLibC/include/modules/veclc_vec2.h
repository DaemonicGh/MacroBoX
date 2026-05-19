/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_vec2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:56:08 by rprieur           #+#    #+#             */
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
t_vec2			vec2_zero(void);

/**
 * Creates a new 2D vector containing the given double for both components.
 */
t_vec2			vec2_d(double xy);

/**
 * Adds two 2D vectors.
 */
t_vec2			vec2_add(t_vec2 p1, t_vec2 p2);

/**
 * Adds d to both components of a 2D vector.
 */
t_vec2			vec2_add_d(t_vec2 p, double d);

/**
 * Subtracts two 2D vectors.
 */
t_vec2			vec2_sub(t_vec2 p1, t_vec2 p2);

/**
 * Subtracts both components of a 2D vector by d.
 */
t_vec2			vec2_sub_d(t_vec2 p, double d);

/**
 * Subtracts d to both components of a 2D vector.
 */
t_vec2			vec2_sub_rd(double d, t_vec2 p);

/**
 * Multiplies two 2D vectors.
 */
t_vec2			vec2_mult(t_vec2 p1, t_vec2 p2);

/**
 * Multiplies both components of a 2D vector by d.
 */
t_vec2			vec2_mult_d(t_vec2 p, double d);

/**
 * Divides two 2D vectors.
 */
t_vec2			vec2_div(t_vec2 p1, t_vec2 p2);

/**
 * Divides both components of a 2D vector by d.
 */
t_vec2			vec2_div_d(t_vec2 p, double d);

/**
 * Divides d by both components of a 2D vector.
 */
t_vec2			vec2_div_rd(double d, t_vec2 p);

/**
 * Returns the remainder of the division between two 2D vectors.
 */
t_vec2			vec2_mod(t_vec2 p1, t_vec2 p2);

/**
 * Returns the remainder of the division between
 * both components of a 2D vector and d.
 */
t_vec2			vec2_mod_d(t_vec2 p, double d);

/**
 * Returns the remainder of the division between
 * d and both components of a 2D vector.
 */
t_vec2			vec2_mod_rd(double d, t_vec2 p);

/**
 * Negates a 2D vector.
 */
t_vec2			vec2_neg(t_vec2 p);

/**
 * Squares a 2D vector.
 */
t_vec2			vec2_square(t_vec2 p);

/**
 * Returns a 2D vector with absolute values
 * of both components of a vector.
 */
t_vec2			vec2_abs(t_vec2 p);

/**
 * Rounds the components of a 2D vector to the nearest integer.
 */
t_vec2i			vec2_round(t_vec2 p);

/**
 * Returns a 2D vector with the result
 * of both components of a vector through f.
 */
t_vec2			vec2_exec(double (*f)(double), t_vec2 p);

/**
 * Returns a 2D vector with the result
 * of both components of two vectors through f.
 */
t_vec2			vec2_exec2(double (*f)(double, double), t_vec2 p1, t_vec2 p2);

/**
 * Returns a 2D vector with the result
 * of both components of three vectors through f.
 */
t_vec2			vec2_exec3(double (*f)(double, double, double),
					t_vec2 p1, t_vec2 p2, t_vec2 p3);

/**
 * Returns the result of both components of a vector through f.
 */
double			vec2_exec_xy( double (*f)(double, double), t_vec2 p1);

/**
 * Returns true if both components of two 2D vectors are equal.
 */
bool			vec2_eq(t_vec2 p1, t_vec2 p2);

/**
 * Returns true if both components of a 2D vector are zero.
 */
bool			vec2_is_zero(t_vec2 p);

/**
 * Returns the length(magnitude) of a 2D vector.
 */
double			vec2_length(t_vec2 p);

/**
 * Normalizes a 2D vector.
 */
t_vec2			vec2_normalize(t_vec2 p);

/**
 * Returns the euclidean distance between two 2D vectors.
 */
double			vec2_dist(t_vec2 p1, t_vec2 p2);

/**
 * Rotates a 2D vector by a given angle in radians.
 */
t_vec2			vec2_rotate(t_vec2 p, double radians);

/**
 * Returns the dot product of two 2D vectors.
 */
double			vec2_dot(t_vec2 p1, t_vec2 p2);

/**
 * Converts a 2D vector to a complex number.
 */
complex double	vec2_complex(t_vec2 p);
