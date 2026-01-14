/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_s_vec2xn.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:36:46 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:00:36 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECLC_S_VEC2XN_H
# define VECLC_S_VEC2XN_H

# include "veclc_s_vec2.h"

typedef struct s_vec2x2
{
	t_vec2	p1;
	t_vec2	p2;
}	t_vec2x2;

typedef struct s_vec2x3
{
	t_vec2	p1;
	t_vec2	p2;
	t_vec2	p3;
}	t_vec2x3;

typedef struct s_vec2x4
{
	t_vec2	p1;
	t_vec2	p2;
	t_vec2	p3;
	t_vec2	p4;
}	t_vec2x4;

t_vec2x2	vec2x2(t_vec2 p1, t_vec2 p2);
t_vec2x2	vec2x2_xy(int x1, int y1, int x2, int y2);
t_vec2x3	vec2x3(t_vec2 p1, t_vec2 p2, t_vec2 p3);
t_vec2x4	vec2x4(t_vec2 p1, t_vec2 p2, t_vec2 p3, t_vec2 p4);

#endif
