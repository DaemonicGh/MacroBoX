/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_vec3.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:56:19 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:43:07 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECLC_VEC3_H
# define VECLC_VEC3_H

# include <stdbool.h>

# include "types/veclc_s_vec3.h"
# include "types/veclc_s_vec3i.h"

t_vec3		vec3_new(double x, double y, double z);
t_vec3		vec3_zero(void);

t_vec3		vec3_add(t_vec3 p1, t_vec3 p2);
t_vec3		vec3_add_d(t_vec3 p, double val);
t_vec3		vec3_add_to(t_vec3 *p1, t_vec3 p2);
t_vec3		vec3_add_to_d(t_vec3 *p, double val);

t_vec3		vec3_sub(t_vec3 p1, t_vec3 p2);
t_vec3		vec3_sub_d(t_vec3 p, double val);
t_vec3		vec3_sub_to(t_vec3 *p1, t_vec3 p2);
t_vec3		vec3_sub_to_d(t_vec3 *p, double val);

t_vec3		vec3_mult(t_vec3 p1, t_vec3 p2);
t_vec3		vec3_mult_d(t_vec3 p, double val);
t_vec3		vec3_mult_to(t_vec3 *p1, t_vec3 p2);
t_vec3		vec3_mult_to_d(t_vec3 *p, double val);

t_vec3		vec3_div(t_vec3 p1, t_vec3 p2);
t_vec3		vec3_div_d(t_vec3 p, double val);
t_vec3		vec3_div_to(t_vec3 *p1, t_vec3 p2);
t_vec3		vec3_div_to_d(t_vec3 *p, double val);

t_vec3		vec3_neg(t_vec3 p);
t_vec3		vec3_square(t_vec3 p);

bool		vec3_eq(t_vec3 p1, t_vec3 p2);
bool		vec3_is_zero(t_vec3 p);

t_vec3		vec3_abs(t_vec3 p);
t_vec3i		vec3_round(t_vec3 p);

double		vec3_length(t_vec3 p);
t_vec3		vec3_normalize(t_vec3 p);
double		vec3_dist(t_vec3 p1, t_vec3 p2);
double		vec3_dot(t_vec3 p1, t_vec3 p2);
t_vec3		vec3_cross(t_vec3 p1, t_vec3 p2);

int			vec3_print(int fd, t_vec3 p, int precision);

t_vec3i		vec3_to_vec3i(t_vec3 p);

#endif
