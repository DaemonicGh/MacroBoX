/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_s_all.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:27:05 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 17:30:14 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "veclc_s_vec2xn.h"
#include "veclc_s_vec3xn.h"
#include "veclc_s_vec4xn.h"

/**
 * Converts a 3D vector to a 2D vector containing it's x and y components.
 */
t_vec2		vec3_xy(t_vec3 p);

/**
 * Converts a 3D vector to a 2D vector containing it's x and y components.
 */
t_vec2i		vec3i_xy(t_vec3i p);

/**
 * Converts a 4D vector to a 2D vector containing it's x and y components.
 */
t_vec2		vec4_xy(t_vec4 p);

/**
* Converts a 4D vector to a 3D vector containing it's x, y and z components.
 */
t_vec3		vec4_xyz(t_vec4 p);

/**
 * Converts a 4D vector to a 2D vector containing it's x and y components.
 */
t_vec2i		vec4i_xy(t_vec4i p);

/**
* Converts a 4D vector to a 3D vector containing it's x, y and z components.
 */
t_vec3i		vec4i_xyz(t_vec4i p);
