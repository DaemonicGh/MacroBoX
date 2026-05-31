/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_s_vec4xn.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:37:04 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/19 00:40:57 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "veclc_s_vec4.h"

/**
 * Group of two 3D vectors containing doubles.
 */
typedef union u_mbx_vector4x2
{
	struct
	{
		t_vec4	p1;
		t_vec4	p2;
	};
	t_vec4	v[2];
}	t_vec4x2;

/**
 * Group of three 3D vectors containing doubles.
 */
typedef union u_mbx_vector4x3
{
	struct
	{
		t_vec4	p1;
		t_vec4	p2;
		t_vec4	p3;
	};
	t_vec4	v[3];
}	t_vec4x3;

/**
 * Group of four 3D vectors containing doubles.
 */
typedef union u_mbx_vector4x4
{
	struct
	{
		t_vec4	p1;
		t_vec4	p2;
		t_vec4	p3;
		t_vec4	p4;
	};
	t_vec4	v[4];
}	t_vec4x4;

/**
 * Group of two 3D vectors containing integers.
 */
typedef union u_mbx_vector4ix2
{
	struct
	{
		t_vec4i	p1;
		t_vec4i	p2;
	};
	t_vec4i	v[2];
}	t_vec4ix2;

/**
 * Group of three 3D vectors containing integers.
 */
typedef union u_mbx_vector4ix3
{
	struct
	{
		t_vec4i	p1;
		t_vec4i	p2;
		t_vec4i	p3;
	};
	t_vec4i	v[3];
}	t_vec4ix3;

/**
 * Group of four 3D vectors containing integers.
 */
typedef union u_mbx_vector4ix4
{
	struct
	{
		t_vec4i	p1;
		t_vec4i	p2;
		t_vec4i	p3;
		t_vec4i	p4;
	};
	t_vec4i	v[4];
}	t_vec4ix4;

/**
 * Creates a group of two 3D vectors containing integers.
 */
t_vec4ix2	vec4ix2(t_vec4i p1, t_vec4i p2);

/**
 * Creates a group of three 3D vectors containing integers.
 */
t_vec4ix3	vec4ix3(t_vec4i p1, t_vec4i p2, t_vec4i p3);

/**
 * Creates a group of four 3D vectors containing integers.
 */
t_vec4ix4	vec4ix4(t_vec4i p1, t_vec4i p2, t_vec4i p3, t_vec4i p4);

/**
 * Creates a group of two 3D vectors containing doubles.
 */
t_vec4x2	vec4x2(t_vec4 p1, t_vec4 p2);

/**
 * Creates a group of three 3D vectors containing doubles.
 */
t_vec4x3	vec4x3(t_vec4 p1, t_vec4 p2, t_vec4 p3);

/**
 * Creates a group of four 3D vectors containing doubles.
 */
t_vec4x4	vec4x4(t_vec4 p1, t_vec4 p2, t_vec4 p3, t_vec4 p4);
