/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_vec3i.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:56:27 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 14:27:23 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECLC_VEC3I_H
# define VECLC_VEC3I_H

# include <stdbool.h>

# include "types/veclc_s_vec3.h"
# include "types/veclc_s_vec3i.h"

/**
 * Creates a new 3D vector containing integers.
 */
t_vec3i		vec3i_new(int x, int y, int z);

/**
 * Creates a new 3D vector containing zeros.
 */
t_vec3i		vec3i_zero(void);

/**
 * Adds two 3D vectors.
 */
t_vec3i		vec3i_add(t_vec3i p1, t_vec3i p2);

/**
 * Adds i to both components of a 3D vector.
 */
t_vec3i		vec3i_add_i(t_vec3i p, int i);

/**
 * Adds two 3D vectors and stores the result in the first vector.
 */
t_vec3i		vec3i_add_to(t_vec3i *p1, t_vec3i p2);

/**
 * Adds i to both components of a 3D vector and stores the result in the vector.
 */
t_vec3i		vec3i_add_to_i(t_vec3i *p, int i);

/**
 * Subtracts two 3D vectors.
 */
t_vec3i		vec3i_sub(t_vec3i p1, t_vec3i p2);

/**
 * Subtracts i from both components of a 3D vector.
 */
t_vec3i		vec3i_sub_i(t_vec3i p, int i);

/**
 * Subtracts two 3D vectors and stores the result in the first vector.
 */
t_vec3i		vec3i_sub_to(t_vec3i *p1, t_vec3i p2);

/**
 * Subtracts i from both components of a 3D vector
 * and stores the result in the vector.
 */
t_vec3i		vec3i_sub_to_i(t_vec3i *p, int i);

/**
 * Multiplies two 3D vectors.
 */
t_vec3i		vec3i_mult(t_vec3i p1, t_vec3i p2);

/**
 * Multiplies both components of a 3D vector by i.
 */
t_vec3i		vec3i_mult_i(t_vec3i p, int i);

/**
 * Multiplies two 3D vectors and stores the result in the first vector.
 */
t_vec3i		vec3i_mult_to(t_vec3i *p1, t_vec3i p2);

/**
 * Multiplies both components of a 3D vector by i
 * and stores the result in the vector.
 */
t_vec3i		vec3i_mult_to_i(t_vec3i *p, int i);

/**
 * Divides two 3D vectors.
 */
t_vec3i		vec3i_div(t_vec3i p1, t_vec3i p2);

/**
 * Divides both components of a 3D vector by i.
 */
t_vec3i		vec3i_div_i(t_vec3i p, int i);

/**
 * Divides two 3D vectors and stores the result in the first vector.
 */
t_vec3i		vec3i_div_to(t_vec3i *p1, t_vec3i p2);

/**
 * Divides both components of a 3D vector by i
 * and stores the result in the vector.
 */
t_vec3i		vec3i_div_to_i(t_vec3i *p, int i);

/**
 * Negates a 3D vector.
 */
t_vec3i		vec3i_neg(t_vec3i p);

/**
 * Squares a 3D vector.
 */
t_vec3i		vec3i_square(t_vec3i p);

/**
 * Returns a 3D vector with absolute values
 * of both components of a vector.
 */
t_vec3i		vec3i_abs(t_vec3i p);

/**
 *  Returns true if both components of two 3D vectors are equal.
 */
bool		vec3i_eq(t_vec3i p1, t_vec3i p2);

/**
 * Returns true if both components of a 3D vector are zero.
 */
bool		vec3i_is_zero(t_vec3i p);

/**
 * Returns the length(magnitude) of a 3D vector.
 */
double		vec3i_length(t_vec3i p);

/**
 * Normalizes a 3D vector.
 */
t_vec3		vec3i_normalize(t_vec3i p);

/**
 * Returns the euclidean distance between two 3D vectors.
 */
double		vec3i_dist(t_vec3i p1, t_vec3i p2);

/**
 * Returns the dot product of two 3D vectors.
 */
double		vec3i_dot(t_vec3i p1, t_vec3i p2);

/**
 * Returns the cross product of two 3D vectors.
 */
t_vec3i		vec3i_cross(t_vec3i p1, t_vec3i p2);

/**
 * Prints a 3D vector to a file descriptor.
 */
int			vec3i_print(int fd, t_vec3i p);

/**
 * Converts a 3D integer vector to a 3D double vector.
 */
t_vec3		vec3i_to_vec3(t_vec3i p);

#endif
