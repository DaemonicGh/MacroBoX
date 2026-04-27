/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_s_vec3i.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:26:58 by rprieur           #+#    #+#             */
/*   Updated: 2026/04/24 16:11:15 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
	int		comp[3];
}	t_vec3i;

/**
 * Creates a new 3D vector containing integers.
 */
t_vec3i		vec3i(int x, int y, int z);
