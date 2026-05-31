/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_s_vec3.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:26:53 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 17:33:04 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/**
 * 3D vector containing doubles.
 */
typedef union u_mbx_vector3
{
	struct
	{
		double	x;
		double	y;
		double	z;
	};
	struct
	{
		double	r;
		double	g;
		double	b;
	};
	double	v[3];
}	t_vec3;

/**
 * 3D vector containing integers.
 */
typedef union u_mbx_vector3i
{
	struct
	{
		int		x;
		int		y;
		int		z;
	};
	struct
	{
		int		r;
		int		g;
		int		b;
	};
	int		v[3];
}	t_vec3i;

/**
 * Creates a new 3D vector containing doubles.
 */
t_vec3		vec3(double x, double y, double z);

/**
 * Creates a new 3D vector containing integers.
 */
t_vec3i		vec3i(int x, int y, int z);

/**
 * Converts a 3D integer vector to a 3D double vector.
 */
t_vec3		vec3_vi(t_vec3i p);

/**
 * Converts a 3D double vector to a 3D integer vector.
 */
t_vec3i		vec3i_vd(t_vec3 p);
