/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 15:58:38 by daemo             #+#    #+#             */
/*   Updated: 2026/01/19 16:44:24 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_MATH_H
# define MBX_MATH_H

# include <stdbool.h>

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
int			fsign(double x);

/**
 * Returns 1 if x is positive, -1 if x is negative, and 0 if x is zero.
 */
int			fsignf(float x);

/**
 * Returns 1 if x is positive, -1 if x is negative, and 0 if x is zero.
 */
int			fsignl(long double x);

/**
 * Returns true if x doesn't have a fractional part.
 */
bool		is_integer(double x);

/**
 * Returns true if x doesn't have a fractional part.
 */
bool		is_integerf(float x);

/**
 * Returns true if x doesn't have a fractional part.
 */
bool		is_integerl(long double x);

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
 * Returns a value between start and end based on the interpolation factor t.
 * If t is 0, returns start. If t is 1, returns end.
 * Values of t outside the range [0, 1] give undefined results.
 */
float		flerpf(float start, float end, double t);

/**
 * Returns a value between start and end based on the interpolation factor t.
 * If t is 0, returns start. If t is 1, returns end.
 * Values of t outside the range [0, 1] give undefined results.
 */
long double	flerpl(long double start, long double end, long double t);

/**
 * Returns the closest value to x between low and high.
 */
int			clamp(int x, int low, int high);

/**
 * Returns the closest value to x between low and high.
 */
double		fclamp(double x, double low, double high);

/**
 * Returns the closest value to x between low and high.
 */
float		fclampf(float x, float low, float high);

/**
 * Returns the closest value to x between low and high.
 */
long double	fclampl(long double x, long double low, long double high);

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
 *	Returns x wrapped into the range
 * [low, high), wrapping around when it goes out of bounds.
 */
float		fwrapf(float x, float low, float high);

/**
 *	Returns x wrapped into the range
 * [low, high), wrapping around when it goes out of bounds.
 */
long double	fwrapl(long double x, long double low, long double high);

/**
 * Returns x moved toward goal by at most incr, without passing beyond the goal.
 * If incr is negative, x will be moved away from goal.
 */
int			move_towards(int x, int goal, int incr);

/**
 * Returns x moved toward goal by at most incr, without passing beyond the goal.
 * If incr is negative, x will be moved away from goal.
 */
double		fmove_towards(double x, double goal, double incr);

/**
 * Returns x moved toward goal by at most incr, without passing beyond the goal.
 * If incr is negative, x will be moved away from goal.
 */
float		fmove_towardsf(float x, float goal, float incr);

/**
 * Returns x moved toward goal by at most incr, without passing beyond the goal.
 * If incr is negative, x will be moved away from goal.
 */
long double	fmove_towardsl(long double x, long double goal, long double incr);

#endif
