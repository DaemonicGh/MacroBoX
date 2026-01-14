/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_vec2i.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:56:23 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:43:05 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECLC_VEC2I_H
# define VECLC_VEC2I_H

# include <stdbool.h>

# include "types/veclc_s_vec2i.h"
# include "types/veclc_s_vec2.h"

t_vec2i		vec2i_new(int x, int y);
t_vec2i		vec2i_zero(void);

t_vec2i		vec2i_add(t_vec2i p1, t_vec2i p2);
t_vec2i		vec2i_add_i(t_vec2i p, int val);
t_vec2i		vec2i_add_to(t_vec2i *p1, t_vec2i p2);
t_vec2i		vec2i_add_to_i(t_vec2i *p, int val);

t_vec2i		vec2i_sub(t_vec2i p1, t_vec2i p2);
t_vec2i		vec2i_sub_i(t_vec2i p, int val);
t_vec2i		vec2i_sub_to(t_vec2i *p1, t_vec2i p2);
t_vec2i		vec2i_sub_to_i(t_vec2i *p, int val);

t_vec2i		vec2i_mult(t_vec2i p1, t_vec2i p2);
t_vec2i		vec2i_mult_i(t_vec2i p, int val);
t_vec2i		vec2i_mult_to(t_vec2i *p1, t_vec2i p2);
t_vec2i		vec2i_mult_to_i(t_vec2i *p, int val);

t_vec2i		vec2i_div(t_vec2i p1, t_vec2i p2);
t_vec2i		vec2i_div_i(t_vec2i p, int val);
t_vec2i		vec2i_div_to(t_vec2i *p1, t_vec2i p2);
t_vec2i		vec2i_div_to_i(t_vec2i *p, int val);

t_vec2i		vec2i_neg(t_vec2i p);
t_vec2i		vec2i_square(t_vec2i p);

bool		vec2i_eq(t_vec2i p1, t_vec2i p2);
bool		vec2i_is_zero(t_vec2i p);

t_vec2i		vec2i_abs(t_vec2i p);

double		vec2i_length(t_vec2i p);
t_vec2		vec2i_normalize(t_vec2i p);
double		vec2i_dist(t_vec2i p1, t_vec2i p2);
t_vec2i		vec2i_rotate(t_vec2i p, double radians);
double		vec2i_dot(t_vec2i p1, t_vec2i p2);

int			vec2i_print(int fd, t_vec2i p);

t_vec2		vec2i_to_vec2(t_vec2i p);

#endif
