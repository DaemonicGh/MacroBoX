/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 15:58:38 by daemo             #+#    #+#             */
/*   Updated: 2026/02/08 08:54:24 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdbool.h>
#include <math.h>

#include "../lib/VecLibC/include/veclc.h"

/**
 * Returns the amount of seconds passed since the UNIX epoch.
 */
double		mbx_get_timestamp(void);

/**
 * Returns the minimum of two integers.
 */
int			min(int x, int y);

/**
 * Returns the maximum of two integers.
 */
int			max(int x, int y);

/**
 * Returns 1 if x is positive, -1 if x is negative, and 0 if x is zero.
 */
int			sign(int x);

/**
 * Returns 1 if x is positive, -1 if x is negative, and 0 if x is zero.
 */
double		fsign(double x);

/**
 * Returns true if x doesn't have a fractional part.
 */
bool		is_integer(double x);

/**
 * Returns x rounded away from 0
 */
double		trunc_up(double x);

/**
 * Returns a value between start and end based on the interpolation factor t.
 * If t is 0, returns start. If t is 1, returns end.
 * Values of t outside the range [0, 1] give undefined results.
 */
int			lerp(int start, int end, double t);

/**
 * Returns a value between start and end based on the interpolation factor t.
 * If t is 0, returns start. If t is 1, returns end.
 * Values of t outside the range [0, 1] give undefined results.
 */
double		flerp(double start, double end, double t);

/**
 * Returns the closest value to x between low and high.
 */
int			clamp(int x, int low, int high);

/**
 * Returns the closest value to x between low and high.
 */
double		fclamp(double x, double low, double high);

/**
 *	Returns x wrapped into the range
 * [low, high), wrapping around when it goes out of bounds.
 */
int			wrap(int x, int low, int high);

/**
 *	Returns x wrapped into the range
 * [low, high), wrapping around when it goes out of bounds.
 */
double		fwrap(double x, double low, double high);

/**
 * Returns x moved toward goal by at most incr, without passing beyond.
 * If incr is negative, x will be moved away from goal.
 */
int			move_towards(int x, int goal, int incr);

/**
 * Returns x moved toward goal by at most incr, without passing beyond.
 * If incr is negative, x will be moved away from goal.
 */
double		fmove_towards(double x, double goal, double incr);

/**
 * Returns the absolute difference between x and the range between low and high.
 * If x is inside the range, return 0.
 * Undefined behavior if high is inferior to low.
 */
int			dist_to_range(int x, int low, int high);

/**
 * Returns the absolute difference between x and the range between low and high.
 * If x is inside the range, return 0.
 * Undefined behavior if high is inferior to low.
 */
double		fdist_to_range(double x, double low, double high);

/**
 * Modifies x within the range [0, 1] to have a quad ease in curve
 */
double		mbx_ease_in(double x);

/**
 * Modifies x within the range [0, 1] to have a quad ease out curve
 */
double		mbx_ease_out(double x);

/**
 * Modifies x within the range [0, 1] to have a quad ease in-out curve
 */
double		mbx_ease_in_out(double x);

/**
 * Returns the sign of each component of a 2D vector.
 * (0 if component is 0)
 */
t_vec2		vec2_sign(t_vec2 p);

/**
 * Returns the sign of each component of a 2D vector.
 * (0 if component is 0)
 */
t_vec2i		vec2i_sign(t_vec2i p);

/**
 * Returns the sign of each component of a 3D vector.
 * (0 if component is 0)
 */
t_vec3		vec3_sign(t_vec3 p);

/**
 * Returns the sign of each component of a 3D vector.
 * (0 if component is 0)
 */
t_vec3i		vec3i_sign(t_vec3i p);

/**
 * Returns a 2D vector resized to have its length between low and high.
 */
t_vec2		vec2_len_clamp(t_vec2 p, double low, double high);

/**
 * Returns a 2D vector resized to have its length between low and high.
 */
t_vec2i		vec2i_len_clamp(t_vec2i p, double low, double high);

/**
 * Returns a 3D vector resized to have its length between low and high.
 */
t_vec3		vec3_len_clamp(t_vec3 p, double low, double high);

/**
 * Returns a 3D vector resized to have its length between low and high.
 */
t_vec3i		vec3i_len_clamp(t_vec3i p, double low, double high);

/**
 * Returns a 2D vector resized towards goal
 * by at most incr, without passing beyond.
 * If incr is negative, the vector will be resized away from goal.
 */
t_vec2		vec2_len_move_towards(t_vec2 p, t_vec2 goal, double incr);

/**
 * Returns a 2D vector resized towards goal
 * by at most incr, without passing beyond.
 * If incr is negative, the vector will be resized away from goal.
 */
t_vec2i		vec2i_len_move_towards(t_vec2i p, t_vec2i goal, double incr);

/**
 * Returns a 3D vector resized towards goal
 * by at most incr, without passing beyond.
 * If incr is negative, the vector will be resized away from goal.
 */
t_vec3		vec3_len_move_towards(t_vec3 p, t_vec3 goal, double incr);

/**
 * Returns a 3D vector resized towards goal
 * by at most incr, without passing beyond.
 * If incr is negative, the vector will be resized away from goal.
 */
t_vec3i		vec3i_len_move_towards(t_vec3i p, t_vec3i goal, double incr);
