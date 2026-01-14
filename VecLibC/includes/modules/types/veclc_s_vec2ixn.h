/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_s_vec2ixn.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:36:51 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:00:29 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECLC_S_VEC2IXN_H
# define VECLC_S_VEC2IXN_H

# include "veclc_s_vec2i.h"

typedef struct s_vec2ix2
{
	t_vec2i	p1;
	t_vec2i	p2;
}	t_vec2ix2;

typedef struct s_vec2ix3
{
	t_vec2i	p1;
	t_vec2i	p2;
	t_vec2i	p3;
}	t_vec2ix3;

typedef struct s_vec2ix4
{
	t_vec2i	p1;
	t_vec2i	p2;
	t_vec2i	p3;
	t_vec2i	p4;
}	t_vec2ix4;

t_vec2ix2	vec2ix2(t_vec2i p1, t_vec2i p2);
t_vec2ix2	vec2ix2_xy(int x1, int y1, int x2, int y2);
t_vec2ix3	vec2ix3(t_vec2i p1, t_vec2i p2, t_vec2i p3);
t_vec2ix4	vec2ix4(t_vec2i p1, t_vec2i p2, t_vec2i p3, t_vec2i p4);

#endif
