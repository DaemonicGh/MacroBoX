/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_vec3i.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:56:27 by rprieur           #+#    #+#             */
/*   Updated: 2026/02/08 08:54:24 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdbool.h>

#include "types/veclc_s_vec3.h"
#include "types/veclc_s_vec3i.h"
#include "types/veclc_s_vec2i.h"

/**
 * Creates a new 3D vector containing zeros.
 */
t_vec3i		vec3i_zero(void);

/**
 * Creates a new 3D vector containing the given integer for all components.
 */
t_vec3i		vec3i_d(int xyz);

/**
 * Adds two 3D vectors.
 */
t_vec3i		vec3i_add(t_vec3i p1, t_vec3i p2);

/**
 * Adds d to all components of a 3D vector.
 */
t_vec3i		vec3i_add_d(t_vec3i p, double d);

/**
 * Subtracts two 3D vectors.
 */
t_vec3i		vec3i_sub(t_vec3i p1, t_vec3i p2);

/**
 * Subtracts all components of a 3D vector by d.
 */
t_vec3i		vec3i_sub_d(t_vec3i p, double d);

/**
 * Subtracts d to all components of a 3D vector.
 */
t_vec3i		vec3i_sub_rd(double d, t_vec3i p);

/**
 * Multiplies two 3D vectors.
 */
t_vec3i		vec3i_mult(t_vec3i p1, t_vec3i p2);

/**
 * Multiplies all components of a 3D vector by d.
 */
t_vec3i		vec3i_mult_d(t_vec3i p, double d);

/**
 * Multiplies two 3D vectors, one having float precision.
 */
t_vec3i		vec3i_mult_vd(t_vec3i p1, t_vec3 p2);

/**
 * Divides two 3D vectors.
 */
t_vec3i		vec3i_div(t_vec3i p1, t_vec3i p2);

/**
 * Divides all components of a 3D vector by d.
 */
t_vec3i		vec3i_div_d(t_vec3i p, double d);

/**
 * Divides d by all components of a 3D vector.
 */
t_vec3i		vec3i_div_rd(double value, t_vec3i p);

/**
 * Divides two 3D vectors, one having float precision.
 */
t_vec3i		vec3i_div_vd(t_vec3i p1, t_vec3 p2);

/**
 * Divides two 3D vectors, one having float precision.
 */
t_vec3i		vec3i_div_rvd(t_vec3 p1, t_vec3i p2);

/**
 * Divides two 3D vectors and keeps the result's float precision.
 */
t_vec3		vec3i_truediv(t_vec3i p1, t_vec3i p2);

/**
 * Divides all components of a 3D vector by d
 * and keeps the result's float precision.
 */
t_vec3		vec3i_truediv_d(t_vec3i p, double d);

/**
 * Divides d by all components of a 3D vector
 * and keeps the result's float precision.
 */
t_vec3		vec3i_truediv_rd(double d, t_vec3i p);

/**
 * Returns the remainder of the division between two 3D vectors.
 */
t_vec2i		vec2i_mod(t_vec2i p1, t_vec2i p2);

/**
 * Returns the remainder of the division between
 * all components of a 3D vector and i.
 */
t_vec3i		vec3i_mod_i(t_vec3i p, int i);

/**
 * Returns the remainder of the division between
 * i and all components of a 3D vector.
 */
t_vec3i		vec3i_mod_ri(int i, t_vec3i p);

/**
 * Returns the remainder of the division between
 * all components of a 3D vector and d.
 */
t_vec3i		vec3i_mod_d(t_vec3i p, double d);

/**
 * Returns the remainder of the division between
 * d and all components of a 3D vector.
 */
t_vec3i		vec3i_mod_rd(double d, t_vec3i p);

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
 * of all components of a vector.
 */
t_vec3i		vec3i_abs(t_vec3i p);

/**
 *  Returns true if all components of two 3D vectors are equal.
 */
bool		vec3i_eq(t_vec3i p1, t_vec3i p2);

/**
 * Returns true if all components of a 3D vector are zero.
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

/**
 * Converts a 3D vector to a 2D vector containing it's x and y components.
 */
t_vec2i		vec3i_xy(t_vec3i p);

/**
* Converts a 3D vector to a 2D vector containing it's y and z components.
 */
t_vec2i		vec3i_yz(t_vec3i p);
