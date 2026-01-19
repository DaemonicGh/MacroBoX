/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_vec3.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:56:19 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 14:25:30 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECLC_VEC3_H
# define VECLC_VEC3_H

# include <stdbool.h>

# include "types/veclc_s_vec3.h"
# include "types/veclc_s_vec3i.h"

/**
 * Creates a new 3D vector containing doubles.
 */
t_vec3		vec3_new(double x, double y, double z);

/**
 * Creates a new 3D vector containing zeros.
 */
t_vec3		vec3_zero(void);

/**
 * Adds two 3D vectors.
 */
t_vec3		vec3_add(t_vec3 p1, t_vec3 p2);

/**
 * Adds d to both components of a 3D vector.
 */
t_vec3		vec3_add_d(t_vec3 p, double d);

/**
 * Adds two 3D vectors and stores the result in the first vector.
 */
t_vec3		vec3_add_to(t_vec3 *p1, t_vec3 p2);

/**
 * Adds d to both components of a 3D vector and stores the result in the vector.
 */
t_vec3		vec3_add_to_d(t_vec3 *p, double d);

/**
 * Subtracts two 3D vectors.
 */
t_vec3		vec3_sub(t_vec3 p1, t_vec3 p2);

/**
 * Subtracts d from both components of a 3D vector.
 */
t_vec3		vec3_sub_d(t_vec3 p, double d);

/**
 * Subtracts two 3D vectors and stores the result in the first vector.
 */
t_vec3		vec3_sub_to(t_vec3 *p1, t_vec3 p2);

/**
 * Subtracts d from both components of a 3D vector
 * and stores the result in the vector.
 */
t_vec3		vec3_sub_to_d(t_vec3 *p, double d);

/**
 * Multiplies two 3D vectors.
 */
t_vec3		vec3_mult(t_vec3 p1, t_vec3 p2);

/**
 * Multiplies both components of a 3D vector by d.
 */
t_vec3		vec3_mult_d(t_vec3 p, double d);

/**
 * Multiplies two 3D vectors and stores the result in the first vector.
 */
t_vec3		vec3_mult_to(t_vec3 *p1, t_vec3 p2);

/**
 * Multiplies both components of a 3D vector by d
 * and stores the result in the vector.
 */
t_vec3		vec3_mult_to_d(t_vec3 *p, double d);

/**
 * Divides two 3D vectors.
 */
t_vec3		vec3_div(t_vec3 p1, t_vec3 p2);

/**
 * Divides both components of a 3D vector by d.
 */
t_vec3		vec3_div_d(t_vec3 p, double d);

/**
 * Divides two 3D vectors and stores the result in the first vector.
 */
t_vec3		vec3_div_to(t_vec3 *p1, t_vec3 p2);

/**
 * Divides both components of a 3D vector by d
 * and stores the result in the vector.
 */
t_vec3		vec3_div_to_d(t_vec3 *p, double d);

/**
 * Negates a 3D vector.
 */
t_vec3		vec3_neg(t_vec3 p);

/**
 * Squares a 3D vector.
 */
t_vec3		vec3_square(t_vec3 p);

/**
 * Returns a 3D vector with absolute values
 * of both components of a vector.
 */
t_vec3		vec3_abs(t_vec3 p);

/**
 * Returns true if both components of two 3D vectors are equal.
 */
bool		vec3_eq(t_vec3 p1, t_vec3 p2);

/**
 * Returns true if both components of a 3D vector are zero.
 */
bool		vec3_is_zero(t_vec3 p);

/**
 * Rounds a 3D vector to the nearest integer.
 */
t_vec3i		vec3_round(t_vec3 p);

/**
 * Returns the length(magnitude) of a 3D vector.
 */
double		vec3_length(t_vec3 p);

/**
 * Normalizes a 3D vector.
 */
t_vec3		vec3_normalize(t_vec3 p);

/**
 * Returns the euclidean distance between two 3D vectors.
 */
double		vec3_dist(t_vec3 p1, t_vec3 p2);

/**
 * Returns the dot product of two 3D vectors.
 */
double		vec3_dot(t_vec3 p1, t_vec3 p2);

/**
 * Returns the cross product of two 3D vectors.
 */
t_vec3		vec3_cross(t_vec3 p1, t_vec3 p2);

/**
 * Prints a 3D vector to a file descriptor.
 */
int			vec3_print(int fd, t_vec3 p, int precision);

/**
 * Converts a 3D double vector to a 3D integer vector.
 */
t_vec3i		vec3_to_vec3i(t_vec3 p);

#endif
