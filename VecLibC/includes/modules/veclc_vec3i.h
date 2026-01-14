/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_vec3i.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:56:27 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:43:08 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECLC_VEC3I_H
# define VECLC_VEC3I_H

# include <stdbool.h>

# include "types/veclc_s_vec3.h"
# include "types/veclc_s_vec3i.h"

t_vec3i		vec3i_new(int x, int y, int z);
t_vec3i		vec3i_zero(void);

t_vec3i		vec3i_add(t_vec3i p1, t_vec3i p2);
t_vec3i		vec3i_add_i(t_vec3i p, int val);
t_vec3i		vec3i_add_to(t_vec3i *p1, t_vec3i p2);
t_vec3i		vec3i_add_to_i(t_vec3i *p, int val);

t_vec3i		vec3i_sub(t_vec3i p1, t_vec3i p2);
t_vec3i		vec3i_sub_i(t_vec3i p, int val);
t_vec3i		vec3i_sub_to(t_vec3i *p1, t_vec3i p2);
t_vec3i		vec3i_sub_to_i(t_vec3i *p, int val);

t_vec3i		vec3i_mult(t_vec3i p1, t_vec3i p2);
t_vec3i		vec3i_mult_i(t_vec3i p, int val);
t_vec3i		vec3i_mult_to(t_vec3i *p1, t_vec3i p2);
t_vec3i		vec3i_mult_to_i(t_vec3i *p, int val);

t_vec3i		vec3i_div(t_vec3i p1, t_vec3i p2);
t_vec3i		vec3i_div_i(t_vec3i p, int val);
t_vec3i		vec3i_div_to(t_vec3i *p1, t_vec3i p2);
t_vec3i		vec3i_div_to_i(t_vec3i *p, int val);

t_vec3i		vec3i_neg(t_vec3i p);
t_vec3i		vec3i_square(t_vec3i p);

t_vec3i		vec3i_abs(t_vec3i p);

bool		vec3i_eq(t_vec3i p1, t_vec3i p2);
bool		vec3i_is_zero(t_vec3i p);

double		vec3i_length(t_vec3i p);
t_vec3		vec3i_normalize(t_vec3i p);
double		vec3i_dist(t_vec3i p1, t_vec3i p2);
double		vec3i_dot(t_vec3i p1, t_vec3i p2);
t_vec3i		vec3i_cross(t_vec3i p1, t_vec3i p2);

int			vec3i_print(int fd, t_vec3i p);

t_vec3		vec3i_to_vec3(t_vec3i p);

#endif
