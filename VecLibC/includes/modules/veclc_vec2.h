/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_vec2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:56:08 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 14:25:50 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECLC_VEC2_H
# define VECLC_VEC2_H

# include <stdbool.h>

# include "types/veclc_s_vec2.h"
# include "types/veclc_s_vec2i.h"

/**
 * Creates a new 2D vector containing doubles.
 */
t_vec2		vec2_new(double x, double y);

/**
 * Creates a new 2D vector containing zeros.
 */
t_vec2		vec2_zero(void);

/**
 * Adds two 2D vectors.
 */
t_vec2		vec2_add(t_vec2 p1, t_vec2 p2);

/**
 * Adds d to both components of a 2D vector.
 */
t_vec2		vec2_add_d(t_vec2 p, double d);

/**
 * Adds two 2D vectors and stores the result in the first vector.
 */
t_vec2		vec2_add_to(t_vec2 *p1, t_vec2 p2);

/**
 * Adds d to both components of a 2D vector and stores the result in the vector.
 */
t_vec2		vec2_add_to_d(t_vec2 *p, double d);

/**
 * Subtracts two 2D vectors.
 */
t_vec2		vec2_sub(t_vec2 p1, t_vec2 p2);

/**
 * Subtracts d from both components of a 2D vector.
 */
t_vec2		vec2_sub_d(t_vec2 p, double d);

/**
 * Subtracts two 2D vectors and stores the result in the first vector.
 */
t_vec2		vec2_sub_to(t_vec2 *p1, t_vec2 p2);

/**
 * Subtracts d from both components of a 2D vector
 * and stores the result in the vector.
 */
t_vec2		vec2_sub_to_d(t_vec2 *p, double d);

/**
 * Multiplies two 2D vectors.
 */
t_vec2		vec2_mult(t_vec2 p1, t_vec2 p2);

/**
 * Multiplies both components of a 2D vector by d.
 */
t_vec2		vec2_mult_d(t_vec2 p, double d);

/**
 * Multiplies two 2D vectors and stores the result in the first vector.
 */
t_vec2		vec2_mult_to(t_vec2 *p1, t_vec2 p2);

/**
 * Multiplies both components of a 2D vector by d
 * and stores the result in the vector.
 */
t_vec2		vec2_mult_to_d(t_vec2 *p, double d);

/**
 * Divides two 2D vectors.
 */
t_vec2		vec2_div(t_vec2 p1, t_vec2 p2);

/**
 * Divides both components of a 2D vector by d.
 */
t_vec2		vec2_div_d(t_vec2 p, double d);

/**
 * Divides two 2D vectors and stores the result in the first vector.
 */
t_vec2		vec2_div_to(t_vec2 *p1, t_vec2 p2);

/**
 * Divides both components of a 2D vector by d
 * and stores the result in the vector.
 */
t_vec2		vec2_div_to_d(t_vec2 *p, double d);

/**
 * Negates a 2D vector.
 */
t_vec2		vec2_neg(t_vec2 p);

/**
 * Squares a 2D vector.
 */
t_vec2		vec2_square(t_vec2 p);

/**
 * Returns a 2D vector with absolute values
 * of both components of a vector.
 */
t_vec2		vec2_abs(t_vec2 p);

/**
 * Returns true if both components of two 2D vectors are equal.
 */
bool		vec2_eq(t_vec2 p1, t_vec2 p2);

/**
 * Returns true if both components of a 2D vector are zero.
 */
bool		vec2_is_zero(t_vec2 p);

/**
 * Rounds the components of a 2D vector to the nearest integer.
 */
t_vec2i		vec2_round(t_vec2 p);

/**
 * Returns the length(magnitude) of a 2D vector.
 */
double		vec2_length(t_vec2 p);

/**
 * Normalizes a 2D vector.
 */
t_vec2		vec2_normalize(t_vec2 p);

/**
 * Returns the euclidean distance between two 2D vectors.
 */
double		vec2_dist(t_vec2 p1, t_vec2 p2);

/**
 * Rotates a 2D vector by a given angle in radians.
 */
t_vec2		vec2_rotate(t_vec2 p, double radians);

/**
 * Returns the dot product of two 2D vectors.
 */
double		vec2_dot(t_vec2 p1, t_vec2 p2);

/**
 * Prints a 2D vector to a file descriptor.
 */
int			vec2_print(int fd, t_vec2 p, int precision);

/**
 * Converts a 2D double vector to a 2D integer vector.
 */
t_vec2i		vec2_to_vec2i(t_vec2 p);

#endif
