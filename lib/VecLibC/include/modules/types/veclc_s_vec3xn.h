/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_s_vec3xn.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:37:04 by rprieur           #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "veclc_s_vec3.h"

/**
 * Group of two 3D vectors containing doubles.
 */
typedef union u_mbx_vector3x2
{
	struct
	{
		t_vec3	p1;
		t_vec3	p2;
	};
	t_vec3	v[2];
}	t_vec3x2;

/**
 * Group of three 3D vectors containing doubles.
 */
typedef union u_mbx_vector3x3
{
	struct
	{
		t_vec3	p1;
		t_vec3	p2;
		t_vec3	p3;
	};
	t_vec3	v[3];
}	t_vec3x3;

/**
 * Group of four 3D vectors containing doubles.
 */
typedef union u_mbx_vector3x4
{
	struct
	{
		t_vec3	p1;
		t_vec3	p2;
		t_vec3	p3;
		t_vec3	p4;
	};
	t_vec3	v[4];
}	t_vec3x4;

/**
 * Group of two 3D vectors containing integers.
 */
typedef union u_mbx_vector3ix2
{
	struct
	{
		t_vec3i	p1;
		t_vec3i	p2;
	};
	t_vec3i	v[2];
}	t_vec3ix2;

/**
 * Group of three 3D vectors containing integers.
 */
typedef union u_mbx_vector3ix3
{
	struct
	{
		t_vec3i	p1;
		t_vec3i	p2;
		t_vec3i	p3;
	};
	t_vec3i	v[3];
}	t_vec3ix3;

/**
 * Group of four 3D vectors containing integers.
 */
typedef union u_mbx_vector3ix4
{
	struct
	{
		t_vec3i	p1;
		t_vec3i	p2;
		t_vec3i	p3;
		t_vec3i	p4;
	};
	t_vec3i	v[4];
}	t_vec3ix4;

/**
 * Creates a group of two 3D vectors containing integers.
 */
t_vec3ix2	vec3ix2(t_vec3i p1, t_vec3i p2);

/**
 * Creates a group of three 3D vectors containing integers.
 */
t_vec3ix3	vec3ix3(t_vec3i p1, t_vec3i p2, t_vec3i p3);

/**
 * Creates a group of four 3D vectors containing integers.
 */
t_vec3ix4	vec3ix4(t_vec3i p1, t_vec3i p2, t_vec3i p3, t_vec3i p4);

/**
 * Creates a group of two 3D vectors containing doubles.
 */
t_vec3x2	vec3x2(t_vec3 p1, t_vec3 p2);

/**
 * Creates a group of three 3D vectors containing doubles.
 */
t_vec3x3	vec3x3(t_vec3 p1, t_vec3 p2, t_vec3 p3);

/**
 * Creates a group of four 3D vectors containing doubles.
 */
t_vec3x4	vec3x4(t_vec3 p1, t_vec3 p2, t_vec3 p3, t_vec3 p4);
