/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_vec4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:56:19 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 18:21:14 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdbool.h>

#include "types/veclc_s_vec4.h"

/**
 * Creates a new 4D vector containing zeros.
 */
t_vec4		vec4_zero(void);

/**
 * Creates a new 4D vector containing the given double for all components.
 */
t_vec4		vec4_d(double xyzw);

/**
 * Adds two 4D vectors.
 */
t_vec4		vec4_add(t_vec4 p1, t_vec4 p2);

/**
 * Adds d to all components of a 4D vector.
 */
t_vec4		vec4_add_d(t_vec4 p, double d);

/**
 * Subtracts two 4D vectors.
 */
t_vec4		vec4_sub(t_vec4 p1, t_vec4 p2);

/**
 * Subtracts all components of a 4D vector by d.
 */
t_vec4		vec4_sub_d(t_vec4 p, double d);

/**
 * Subtracts d to all components of a 4D vector.
 */
t_vec4		vec4_sub_rd(double d, t_vec4 p);

/**
 * Multiplies two 4D vectors.
 */
t_vec4		vec4_mult(t_vec4 p1, t_vec4 p2);

/**
 * Multiplies all components of a 4D vector by d.
 */
t_vec4		vec4_mult_d(t_vec4 p, double d);

/**
 * Divides two 4D vectors.
 */
t_vec4		vec4_div(t_vec4 p1, t_vec4 p2);

/**
 * Divides all components of a 4D vector by d.
 */
t_vec4		vec4_div_d(t_vec4 p, double d);

/**
 * Divides d by all components of a 4D vector.
 */
t_vec4		vec4_div_rd(double d, t_vec4 p);

/**
 * Returns the remainder of the division between two 4D vectors.
 */
t_vec4		vec4_mod(t_vec4 p1, t_vec4 p2);

/**
 * Returns the remainder of the division between
 * all components of a 4D vector and d.
 */
t_vec4		vec4_mod_d(t_vec4 p, double d);

/**value
 * Returns the remainder of the division between
 * d and all components of a 4D vector.
 */
t_vec4		vec4_mod_rd(double d, t_vec4 p);

/**
 * Negates a 4D vector.
 */
t_vec4		vec4_neg(t_vec4 p);

/**
 * Squares a 4D vector.
 */
t_vec4		vec4_square(t_vec4 p);

/**
 * Returns a 4D vector with absolute values
 * of all components of a vector.
 */
t_vec4		vec4_abs(t_vec4 p);

/**
 * Rounds a 4D vector to the nearest integer.
 */
t_vec4i		vec4_round(t_vec4 p);

/**
 * Returns a 4D vector with the result
 * of all components of a vector through f.
 */
t_vec4		vec4_exec(double (*f)(double), t_vec4 p);

/**
 * Returns a 4D vector with the result
 * of all components of two vectors through f.
 */
t_vec4		vec4_exec2(double (*f)(double, double), t_vec4 p1, t_vec4 p2);

/**
 * Returns a 4D vector with the result
 * of all components of three vectors through f.
 */
t_vec4		vec4_exec3(double (*f)(double, double, double),
				t_vec4 p1, t_vec4 p2, t_vec4 p3);

/**
 * Returns the result all components of a vector through f.
 */
double		vec4_exec_xyzw(double (*f)(double, double, double, double),
				t_vec4 p1);

/**
 * Returns the result all components of a vector through f ((x, y), (z, w)).
 */
double		vec4_exec_xy_zw(double (*f)(double, double), t_vec4 p1);

/**
 * Returns true if all components of two 4D vectors are equal.
 */
bool		vec4_eq(t_vec4 p1, t_vec4 p2);

/**
 * Returns true if all components of a 4D vector are zero.
 */
bool		vec4_is_zero(t_vec4 p);

/**
 * Returns the length(magnitude) of a 4D vector.
 */
double		vec4_length(t_vec4 p);

/**
 * Normalizes a 4D vector.
 */
t_vec4		vec4_normalize(t_vec4 p);

/**
 * Returns the euclidean distance between two 4D vectors.
 */
double		vec4_dist(t_vec4 p1, t_vec4 p2);

/**
 * Returns the dot product of two 4D vectors.
 */
double		vec4_dot(t_vec4 p1, t_vec4 p2);
