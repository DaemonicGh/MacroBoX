/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_s_vec3.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:26:53 by rprieur           #+#    #+#             */
/*   Updated: 2026/02/08 08:50:06 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/**
 * 3D vector containing doubles.
 */
typedef struct
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

/**
 * Creates a new 3D vector containing doubles.
 */
t_vec3		vec3(double x, double y, double z);


