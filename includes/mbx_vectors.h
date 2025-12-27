/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_vectors.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:29:49 by daemo             #+#    #+#             */
/*   Updated: 2025/12/27 15:21:25 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_VECTORS_H
# define MBX_VECTORS_H

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_vec2i
{
	int	x;
	int	y;
}	t_vec2i;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_vec3i
{
	int	x;
	int	y;
	int	z;
}	t_vec3i;

// Vec2

t_vec2	vec2_new(double x, double y);
t_vec2	vec2_zero(void);

t_vec2	vec2_add(t_vec2 p1, t_vec2 p2);
t_vec2	vec2_add_d(t_vec2 p, double val);
t_vec2	vec2_add_to(t_vec2 *p1, t_vec2 p2);
t_vec2	vec2_add_to_d(t_vec2 *p, double val);

t_vec2	vec2_sub(t_vec2 p1, t_vec2 p2);
t_vec2	vec2_sub_d(t_vec2 p, double val);
t_vec2	vec2_sub_to(t_vec2 *p1, t_vec2 p2);
t_vec2	vec2_sub_to_d(t_vec2 *p, double val);

t_vec2	vec2_mult(t_vec2 p1, t_vec2 p2);
t_vec2	vec2_mult_d(t_vec2 p, double val);
t_vec2	vec2_mult_to(t_vec2 *p1, t_vec2 p2);
t_vec2	vec2_mult_to_d(t_vec2 *p, double val);

t_vec2	vec2_div(t_vec2 p1, t_vec2 p2);
t_vec2	vec2_div_d(t_vec2 p, double val);
t_vec2	vec2_div_to(t_vec2 *p1, t_vec2 p2);
t_vec2	vec2_div_to_d(t_vec2 *p, double val);

t_vec2	vec2_neg(t_vec2 p);
t_vec2	vec2_square(t_vec2 p);

bool	vec2_eq(t_vec2 p1, t_vec2 p2);
bool	vec2_is_zero(t_vec2 p);

t_vec2	vec2_abs(t_vec2 p);
t_vec2i	vec2_round(t_vec2 p);

double	vec2_length(t_vec2 p);
t_vec2	vec2_normalize(t_vec2 p);
double	vec2_dist(t_vec2 p1, t_vec2 p2);
t_vec2	vec2_rotate(t_vec2 p, double radians);
double	vec2_dot(t_vec2 p1, t_vec2 p2);

int		vec2_print(int fd, t_vec2 p, int precision);

t_vec2i	vec2_to_vec2i(t_vec2 p);

// Vec2i

t_vec2i	vec2i_new(int x, int y);
t_vec2i	vec2i_zero(void);

t_vec2i	vec2i_add(t_vec2i p1, t_vec2i p2);
t_vec2i	vec2i_add_i(t_vec2i p, int val);
t_vec2i	vec2i_add_to(t_vec2i *p1, t_vec2i p2);
t_vec2i	vec2i_add_to_i(t_vec2i *p, int val);

t_vec2i	vec2i_sub(t_vec2i p1, t_vec2i p2);
t_vec2i	vec2i_sub_i(t_vec2i p, int val);
t_vec2i	vec2i_sub_to(t_vec2i *p1, t_vec2i p2);
t_vec2i	vec2i_sub_to_i(t_vec2i *p, int val);

t_vec2i	vec2i_mult(t_vec2i p1, t_vec2i p2);
t_vec2i	vec2i_mult_i(t_vec2i p, int val);
t_vec2i	vec2i_mult_to(t_vec2i *p1, t_vec2i p2);
t_vec2i	vec2i_mult_to_i(t_vec2i *p, int val);

t_vec2i	vec2i_div(t_vec2i p1, t_vec2i p2);
t_vec2i	vec2i_div_i(t_vec2i p, int val);
t_vec2i	vec2i_div_to(t_vec2i *p1, t_vec2i p2);
t_vec2i	vec2i_div_to_i(t_vec2i *p, int val);

t_vec2i	vec2i_neg(t_vec2i p);
t_vec2i	vec2i_square(t_vec2i p);

bool	vec2i_eq(t_vec2i p1, t_vec2i p2);
bool	vec2i_is_zero(t_vec2i p);

t_vec2i	vec2i_abs(t_vec2i p);

double	vec2i_length(t_vec2i p);
t_vec2	vec2i_normalize(t_vec2i p);
double	vec2i_dist(t_vec2i p1, t_vec2i p2);
t_vec2i	vec2i_rotate(t_vec2i p, double radians);
double	vec2i_dot(t_vec2i p1, t_vec2i p2);

int		vec2i_print(int fd, t_vec2i p);

t_vec2	vec2i_to_vec2(t_vec2i p);

// Vec3

t_vec3	vec3_new(double x, double y, double z);
t_vec3	vec3_zero(void);

t_vec3	vec3_add(t_vec3 p1, t_vec3 p2);
t_vec3	vec3_add_d(t_vec3 p, double val);
t_vec3	vec3_add_to(t_vec3 *p1, t_vec3 p2);
t_vec3	vec3_add_to_d(t_vec3 *p, double val);

t_vec3	vec3_sub(t_vec3 p1, t_vec3 p2);
t_vec3	vec3_sub_d(t_vec3 p, double val);
t_vec3	vec3_sub_to(t_vec3 *p1, t_vec3 p2);
t_vec3	vec3_sub_to_d(t_vec3 *p, double val);

t_vec3	vec3_mult(t_vec3 p1, t_vec3 p2);
t_vec3	vec3_mult_d(t_vec3 p, double val);
t_vec3	vec3_mult_to(t_vec3 *p1, t_vec3 p2);
t_vec3	vec3_mult_to_d(t_vec3 *p, double val);

t_vec3	vec3_div(t_vec3 p1, t_vec3 p2);
t_vec3	vec3_div_d(t_vec3 p, double val);
t_vec3	vec3_div_to(t_vec3 *p1, t_vec3 p2);
t_vec3	vec3_div_to_d(t_vec3 *p, double val);

t_vec3	vec3_neg(t_vec3 p);
t_vec3	vec3_square(t_vec3 p);

bool	vec3_eq(t_vec3 p1, t_vec3 p2);
bool	vec3_is_zero(t_vec3 p);

t_vec3	vec3_abs(t_vec3 p);
t_vec3i	vec3_round(t_vec3 p);

double	vec3_length(t_vec3 p);
t_vec3	vec3_normalize(t_vec3 p);
double	vec3_dist(t_vec3 p1, t_vec3 p2);
double	vec3_dot(t_vec3 p1, t_vec3 p2);
t_vec3	vec3_cross(t_vec3 p1, t_vec3 p2);

int		vec3_print(int fd, t_vec3 p, int precision);

t_vec3i	vec3_to_vec3i(t_vec3 p);

// Vec3i

t_vec3i	vec3i_new(int x, int y, int z);
t_vec3i	vec3i_zero(void);

t_vec3i	vec3i_add(t_vec3i p1, t_vec3i p2);
t_vec3i	vec3i_add_i(t_vec3i p, int val);
t_vec3i	vec3i_add_to(t_vec3i *p1, t_vec3i p2);
t_vec3i	vec3i_add_to_i(t_vec3i *p, int val);

t_vec3i	vec3i_sub(t_vec3i p1, t_vec3i p2);
t_vec3i	vec3i_sub_i(t_vec3i p, int val);
t_vec3i	vec3i_sub_to(t_vec3i *p1, t_vec3i p2);
t_vec3i	vec3i_sub_to_i(t_vec3i *p, int val);

t_vec3i	vec3i_mult(t_vec3i p1, t_vec3i p2);
t_vec3i	vec3i_mult_i(t_vec3i p, int val);
t_vec3i	vec3i_mult_to(t_vec3i *p1, t_vec3i p2);
t_vec3i	vec3i_mult_to_i(t_vec3i *p, int val);

t_vec3i	vec3i_div(t_vec3i p1, t_vec3i p2);
t_vec3i	vec3i_div_i(t_vec3i p, int val);
t_vec3i	vec3i_div_to(t_vec3i *p1, t_vec3i p2);
t_vec3i	vec3i_div_to_i(t_vec3i *p, int val);

t_vec3i	vec3i_neg(t_vec3i p);
t_vec3i	vec3i_square(t_vec3i p);

t_vec3i	vec3i_abs(t_vec3i p);

bool	vec3i_eq(t_vec3i p1, t_vec3i p2);
bool	vec3i_is_zero(t_vec3i p);

double	vec3i_length(t_vec3i p);
t_vec3	vec3i_normalize(t_vec3i p);
double	vec3i_dist(t_vec3i p1, t_vec3i p2);
double	vec3i_dot(t_vec3i p1, t_vec3i p2);
t_vec3i	vec3i_cross(t_vec3i p1, t_vec3i p2);

int		vec3i_print(int fd, t_vec3i p);

t_vec3	vec3i_to_vec3(t_vec3i p);

#endif