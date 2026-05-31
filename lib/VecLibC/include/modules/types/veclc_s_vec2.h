/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_s_vec2.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:26:43 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 19:17:43 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/**
 * 2D vector containing doubles.
 */
typedef union u_mbx_vector2
{
	struct
	{
		double	x;
		double	y;
	};
	double	v[2];
}	t_vec2;

/**
 * 2D vector containing integers.
 */
typedef union u_mbx_vector2i
{
	struct
	{
		int		x;
		int		y;
	};
	int		v[2];
}	t_vec2i;

/**
 * Creates a new 2D vector containing doubles.
 */
t_vec2		vec2(double x, double y);

/**
 * Creates a new 2D vector containing integers.
 */
t_vec2i		vec2i(int x, int y);

/**
 * Converts a 2D integer vector to a 2D double vector.
 */
t_vec2		vec2_vi(t_vec2i p);

/**
 * Converts a 2D double vector to a 2D integer vector.
 */
t_vec2i		vec2i_vd(t_vec2 p);
