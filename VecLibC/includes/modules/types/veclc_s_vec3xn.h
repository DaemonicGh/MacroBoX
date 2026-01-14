/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_s_vec3xn.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:36:59 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:00:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECLC_S_VEC3XN_H
# define VECLC_S_VEC3XN_H

# include "veclc_s_vec3.h"

typedef struct s_vec3x2
{
	t_vec3	p1;
	t_vec3	p2;
}	t_vec3x2;

typedef struct s_vec3x3
{
	t_vec3	p1;
	t_vec3	p2;
	t_vec3	p3;
}	t_vec3x3;

typedef struct s_vec3x4
{
	t_vec3	p1;
	t_vec3	p2;
	t_vec3	p3;
	t_vec3	p4;
}	t_vec3x4;

t_vec3x2	vec3x2(t_vec3 p1, t_vec3 p2);
t_vec3x3	vec3x3(t_vec3 p1, t_vec3 p2, t_vec3 p3);
t_vec3x4	vec3x4(t_vec3 p1, t_vec3 p2, t_vec3 p3, t_vec3 p4);

#endif
