/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_s_vec3xn.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:36:59 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 13:49:11 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECLC_S_VEC3XN_H
# define VECLC_S_VEC3XN_H

# include "veclc_s_vec3.h"

/**
 * Group of two 3D vectors containing doubles.
 */
typedef struct s_vec3x2
{
	t_vec3	p1;
	t_vec3	p2;
}	t_vec3x2;

/**
 * Group of three 3D vectors containing doubles.
 */
typedef struct s_vec3x3
{
	t_vec3	p1;
	t_vec3	p2;
	t_vec3	p3;
}	t_vec3x3;

/**
 * Group of four 3D vectors containing doubles.
 */
typedef struct s_vec3x4
{
	t_vec3	p1;
	t_vec3	p2;
	t_vec3	p3;
	t_vec3	p4;
}	t_vec3x4;

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

#endif
