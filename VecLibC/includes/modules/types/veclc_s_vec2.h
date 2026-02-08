/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_s_vec2.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:26:43 by rprieur           #+#    #+#             */
/*   Updated: 2026/02/08 08:49:53 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/**
 * 2D vector containing doubles.
 */
typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

/**
 * Creates a new 2D vector containing doubles.
 */
t_vec2		vec2(double x, double y);


