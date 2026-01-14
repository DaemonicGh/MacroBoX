/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_vec2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:56:08 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:43:01 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECLC_VEC2_H
# define VECLC_VEC2_H

# include <stdbool.h>

# include "types/veclc_s_vec2.h"
# include "types/veclc_s_vec2i.h"

t_vec2		vec2_new(double x, double y);
t_vec2		vec2_zero(void);

t_vec2		vec2_add(t_vec2 p1, t_vec2 p2);
t_vec2		vec2_add_d(t_vec2 p, double val);
t_vec2		vec2_add_to(t_vec2 *p1, t_vec2 p2);
t_vec2		vec2_add_to_d(t_vec2 *p, double val);

t_vec2		vec2_sub(t_vec2 p1, t_vec2 p2);
t_vec2		vec2_sub_d(t_vec2 p, double val);
t_vec2		vec2_sub_to(t_vec2 *p1, t_vec2 p2);
t_vec2		vec2_sub_to_d(t_vec2 *p, double val);

t_vec2		vec2_mult(t_vec2 p1, t_vec2 p2);
t_vec2		vec2_mult_d(t_vec2 p, double val);
t_vec2		vec2_mult_to(t_vec2 *p1, t_vec2 p2);
t_vec2		vec2_mult_to_d(t_vec2 *p, double val);

t_vec2		vec2_div(t_vec2 p1, t_vec2 p2);
t_vec2		vec2_div_d(t_vec2 p, double val);
t_vec2		vec2_div_to(t_vec2 *p1, t_vec2 p2);
t_vec2		vec2_div_to_d(t_vec2 *p, double val);

t_vec2		vec2_neg(t_vec2 p);
t_vec2		vec2_square(t_vec2 p);

bool		vec2_eq(t_vec2 p1, t_vec2 p2);
bool		vec2_is_zero(t_vec2 p);

t_vec2		vec2_abs(t_vec2 p);
t_vec2i		vec2_round(t_vec2 p);

double		vec2_length(t_vec2 p);
t_vec2		vec2_normalize(t_vec2 p);
double		vec2_dist(t_vec2 p1, t_vec2 p2);
t_vec2		vec2_rotate(t_vec2 p, double radians);
double		vec2_dot(t_vec2 p1, t_vec2 p2);

int			vec2_print(int fd, t_vec2 p, int precision);

t_vec2i		vec2_to_vec2i(t_vec2 p);

#endif
