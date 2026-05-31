/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_s_vec2xn.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:36:51 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 17:16:19 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "veclc_s_vec2.h"

/**
 * Group of two 2D vectors containing doubles.
 */
typedef union u_mbx_vector2x2
{
	struct
	{
		t_vec2	p1;
		t_vec2	p2;
	};
	t_vec2	v[2];
}	t_vec2x2;

/**
 * Group of three 2D vectors containing doubles.
 */
typedef union u_mbx_vector2x3
{
	struct
	{
		t_vec2	p1;
		t_vec2	p2;
		t_vec2	p3;
	};
	t_vec2	v[3];
}	t_vec2x3;

/**
 * Group of four 2D vectors containing doubles.
 */
typedef union u_mbx_vector2x4
{
	struct
	{
		t_vec2	p1;
		t_vec2	p2;
		t_vec2	p3;
		t_vec2	p4;
	};
	t_vec2	v[4];
}	t_vec2x4;

/**
 * Group of two 2D vectors containing integers.
 */
typedef union u_mbx_vector2ix2
{
	struct
	{
		t_vec2i	p1;
		t_vec2i	p2;
	};
	t_vec2i	v[2];
}	t_vec2ix2;

/**
 * Group of three 2D vectors containing integers.
 */
typedef union u_mbx_vector2ix3
{
	struct
	{
		t_vec2i	p1;
		t_vec2i	p2;
		t_vec2i	p3;
	};
	t_vec2i	v[3];
}	t_vec2ix3;

/**
 * Group of four 2D vectors containing integers.
 */
typedef union u_mbx_vector2ix4
{
	struct
	{
		t_vec2i	p1;
		t_vec2i	p2;
		t_vec2i	p3;
		t_vec2i	p4;
	};
	t_vec2i	v[4];
}	t_vec2ix4;

/**
 * Creates a group of two 2D vectors containing doubles.
 */
t_vec2x2	vec2x2(t_vec2 p1, t_vec2 p2);

/**
 * Creates a group of two 2D vectors containing doubles.
 */
t_vec2x2	vec2x2_xy(double x1, double y1, double x2, double y2);

/**
 * Creates a group of three 2D vectors containing doubles.
 */
t_vec2x3	vec2x3(t_vec2 p1, t_vec2 p2, t_vec2 p3);

/**
 * Creates a group of four 2D vectors containing doubles.
 */
t_vec2x4	vec2x4(t_vec2 p1, t_vec2 p2, t_vec2 p3, t_vec2 p4);

/**
 * Creates a group of two 2D vectors containing integers.
 */
t_vec2ix2	vec2ix2(t_vec2i p1, t_vec2i p2);

/**
 * Creates a group of two 2D vectors containing integers.
 */
t_vec2ix2	vec2ix2_xy(int x1, int y1, int x2, int y2);

/**
 * Creates a group of three 2D vectors containing integers.
 */
t_vec2ix3	vec2ix3(t_vec2i p1, t_vec2i p2, t_vec2i p3);

/**
 * Creates a group of four 2D vectors containing integers.
 */
t_vec2ix4	vec2ix4(t_vec2i p1, t_vec2i p2, t_vec2i p3, t_vec2i p4);
