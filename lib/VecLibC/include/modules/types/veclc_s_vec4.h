/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_s_vec4.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:26:53 by rprieur           #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/**
 * 3D vector containing doubles.
 */
typedef union u_mbx_vector4
{
	struct
	{
		double	x;
		double	y;
		double	z;
		double	w;
	};
	struct
	{
		double	r;
		double	g;
		double	b;
		double	a;
	};
	double	v[4];
}	t_vec4;

typedef t_vec4	t_quat;

/**
 * 3D vector containing integers.
 */
typedef union u_mbx_vector4i
{
	struct
	{
		int		x;
		int		y;
		int		z;
		int		w;
	};
	struct
	{
		int		r;
		int		g;
		int		b;
		int		a;
	};
	int		v[4];
}	t_vec4i;

/**
 * Creates a new 3D vector containing doubles.
 */
t_vec4		vec4(double x, double y, double z, double w);

/**
 * Creates a new 3D vector containing integers.
 */
t_vec4i		vec4i(int x, int y, int z, int w);

/**
 * Converts a 4D integer vector to a 4D double vector.
 */
t_vec4		vec4_vi(t_vec4i p);

/**
 * Converts a 4D double vector to a 4D integer vector.
 */
t_vec4i		vec4i_vd(t_vec4 p);
