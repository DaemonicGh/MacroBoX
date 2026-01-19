/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_vec2i.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:56:23 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 14:25:44 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECLC_VEC2I_H
# define VECLC_VEC2I_H

# include <stdbool.h>

# include "types/veclc_s_vec2i.h"
# include "types/veclc_s_vec2.h"

/**
 * Creates a new 2D vector containing integers.
 */
t_vec2i		vec2i_new(int x, int y);

/**
 * Creates a new 2D vector containing zeros.
 */
t_vec2i		vec2i_zero(void);

/**
 * Adds two 2D vectors.
 */
t_vec2i		vec2i_add(t_vec2i p1, t_vec2i p2);

/**
 * Adds i to both components of a 2D vector.
 */
t_vec2i		vec2i_add_i(t_vec2i p, int i);

/**
 * Adds two 2D vectors and stores the result in the first vector.
 */
t_vec2i		vec2i_add_to(t_vec2i *p1, t_vec2i p2);

/**
 * Adds i to both components of a 2D vector and stores the result in the vector.
 */
t_vec2i		vec2i_add_to_i(t_vec2i *p, int i);

/**
 * Subtracts two 2D vectors.
 */
t_vec2i		vec2i_sub(t_vec2i p1, t_vec2i p2);

/**
 * Subtracts i from both components of a 2D vector.
 */
t_vec2i		vec2i_sub_i(t_vec2i p, int i);

/**
 * Subtracts two 2D vectors and stores the result in the first vector.
 */
t_vec2i		vec2i_sub_to(t_vec2i *p1, t_vec2i p2);

/**
 * Subtracts i from both components of a 2D vector
 * and stores the result in the vector.
 */
t_vec2i		vec2i_sub_to_i(t_vec2i *p, int i);

/**
 * Multiplies two 2D vectors.
 */
t_vec2i		vec2i_mult(t_vec2i p1, t_vec2i p2);

/**
 * Multiplies both components of a 2D vector by i.
 */
t_vec2i		vec2i_mult_i(t_vec2i p, int i);

/**
 * Multiplies two 2D vectors and stores the result in the first vector.
 */
t_vec2i		vec2i_mult_to(t_vec2i *p1, t_vec2i p2);

/**
 * Multiplies both components of a 2D vector by i
 * and stores the result in the vector.
 */
t_vec2i		vec2i_mult_to_i(t_vec2i *p, int i);

/**
 * Divides two 2D vectors.
 */
t_vec2i		vec2i_div(t_vec2i p1, t_vec2i p2);

/**
 * Divides both components of a 2D vector by i.
 */
t_vec2i		vec2i_div_i(t_vec2i p, int i);

/**
 * Divides two 2D vectors and stores the result in the first vector.
 */
t_vec2i		vec2i_div_to(t_vec2i *p1, t_vec2i p2);

/**
 * Divides both components of a 2D vector by i
 * and stores the result in the vector.
 */
t_vec2i		vec2i_div_to_i(t_vec2i *p, int i);

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
 * Rotates a 2D vector by a given angle in radians.
 */
t_vec2i		vec2i_rotate(t_vec2i p, double radians);

/**
 * Returns the dot product of two 2D vectors.
 */
double		vec2i_dot(t_vec2i p1, t_vec2i p2);

/**
 * Prints a 2D vector to a file descriptor.
 */
int			vec2i_print(int fd, t_vec2i p);

/**
 * Converts a 2D integer vector to a 2D double vector.
 */
t_vec2		vec2i_to_vec2(t_vec2i p);

#endif
