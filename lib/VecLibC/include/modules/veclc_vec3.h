/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_vec3.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:56:19 by rprieur           #+#    #+#             */
/*   Updated: 2026/04/16 17:22:14 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdbool.h>

#include "types/veclc_s_vecn.h"

/**
 * Creates a new 3D vector containing zeros.
 */
t_vec3		vec3_zero(void);

/**
 * Creates a new 3D vector containing the given double for all components.
 */
t_vec3		vec3_d(double xyz);

/**
 * Creates a new 3D vector based on a pitch and yaw value in radians.
 * the zero angle faces towards positive x
 */
t_vec3		vec3_from_angle(t_vec2 pitch_yaw_rad);

/**
 * Adds two 3D vectors.
 */
t_vec3		vec3_add(t_vec3 p1, t_vec3 p2);

/**
 * Adds d to all components of a 3D vector.
 */
t_vec3		vec3_add_d(t_vec3 p, double d);

/**
 * Subtracts two 3D vectors.
 */
t_vec3		vec3_sub(t_vec3 p1, t_vec3 p2);

/**
 * Subtracts all components of a 3D vector by d.
 */
t_vec3		vec3_sub_d(t_vec3 p, double d);

/**
 * Subtracts d to all components of a 3D vector.
 */
t_vec3		vec3_sub_rd(double d, t_vec3 p);

/**
 * Multiplies two 3D vectors.
 */
t_vec3		vec3_mult(t_vec3 p1, t_vec3 p2);

/**
 * Multiplies all components of a 3D vector by d.
 */
t_vec3		vec3_mult_d(t_vec3 p, double d);

/**
 * Divides two 3D vectors.
 */
t_vec3		vec3_div(t_vec3 p1, t_vec3 p2);

/**
 * Divides all components of a 3D vector by d.
 */
t_vec3		vec3_div_d(t_vec3 p, double d);

/**
 * Divides d by all components of a 3D vector.
 */
t_vec3		vec3_div_rd(double d, t_vec3 p);

/**
 * Returns the remainder of the division between two 3D vectors.
 */
t_vec3		vec3_mod(t_vec3 p1, t_vec3 p2);

/**
 * Returns the remainder of the division between
 * all components of a 3D vector and d.
 */
t_vec3		vec3_mod_d(t_vec3 p, double d);

/**value
 * Returns the remainder of the division between
 * d and all components of a 3D vector.
 */
t_vec3		vec3_mod_rd(double d, t_vec3 p);

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
 * of all components of a vector.
 */
t_vec3		vec3_abs(t_vec3 p);

/**
 * Rounds a 3D vector to the nearest integer.
 */
t_vec3i		vec3_round(t_vec3 p);

/**
 * Returns a 3D vector with the result
 * of all components of a vector through f.
 */
t_vec3		vec3_exec(t_vec3 p, double (*f)(double));

/**
 * Returns a 3D vector with the result
 * of all components of two vectors through f.
 */
t_vec3		vec3_exec2(t_vec3 p1, t_vec3 p2, double (*f)(double, double));

/**
 * Returns a 3D vector with the result
 * of all components of three vectors through f.
 */
t_vec3		vec3_exec3(t_vec3 p1, t_vec3 p2, t_vec3 p3,
				double (*f)(double, double, double));

/**
 * Returns the result all components of a vector through f.
 */
double		vec3_exec_xyz(t_vec3 p1, double (*f)(double, double, double));

/**
 * Returns the result all components of a vector through f ((x, y), z).
 */
double		vec3_exec_xy_yz(t_vec3 p1, double (*f)(double, double));

/**
 * Returns true if all components of two 3D vectors are equal.
 */
bool		vec3_eq(t_vec3 p1, t_vec3 p2);

/**
 * Returns true if all components of a 3D vector are zero.
 */
bool		vec3_is_zero(t_vec3 p);

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
t_vec3i		vec3i_vd(t_vec3 p);

/**
 * Converts a 3D vector to a 2D vector containing it's x and y components.
 */
t_vec2		vec3_xy(t_vec3 p);

/**
* Converts a 3D vector to a 2D vector containing it's y and z components.
 */
t_vec2		vec3_yz(t_vec3 p);
