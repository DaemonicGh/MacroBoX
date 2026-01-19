/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_s_vec3ixn.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:37:04 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 13:48:21 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECLC_S_VEC3IXN_H
# define VECLC_S_VEC3IXN_H

# include "veclc_s_vec3i.h"

/**
 * Group of two 3D vectors containing integers.
 */
typedef struct s_vec3ix2
{
	t_vec3i	p1;
	t_vec3i	p2;
}	t_vec3ix2;

/**
 * Group of three 3D vectors containing integers.
 */
typedef struct s_vec3ix3
{
	t_vec3i	p1;
	t_vec3i	p2;
	t_vec3i	p3;
}	t_vec3ix3;

/**
 * Group of four 3D vectors containing integers.
 */
typedef struct s_vec3ix4
{
	t_vec3i	p1;
	t_vec3i	p2;
	t_vec3i	p3;
	t_vec3i	p4;
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

#endif
