/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_s_vec3i.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:26:58 by rprieur           #+#    #+#             */
/*   Updated: 2026/02/08 08:50:11 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/**
 * 3D vector containing integers.
 */
typedef struct
{
	int	x;
	int	y;
	int	z;
}	t_vec3i;

/**
 * Creates a new 3D vector containing integers.
 */
t_vec3i		vec3i(int x, int y, int z);


