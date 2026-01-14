/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 15:58:38 by daemo             #+#    #+#             */
/*   Updated: 2026/01/02 17:27:20 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_MATH_H
# define MBX_MATH_H

int			min(int val1, int val2);
int			max(int val1, int val2);

int			sign(int val);
int			fsign(double val);
int			fsignf(float val);
int			fsignl(long double val);

int			lerp(int start, int end, double delta);
double		flerp(double start, double end, double delta);
float		flerpf(float start, float end, double delta);
long double	flerpl(long double start, long double end, long double delta);

int			clamp(int val, int low, int high);
double		fclamp(double val, double low, double high);
float		fclampf(float val, float low, float high);
long double	fclampl(long double val, long double low, long double high);

int			loop(int val, int low, int high);
double		floop(double val, double low, double high);
float		floopf(float val, float low, float high);
long double	floopl(long double val, long double low, long double high);

int			move_towards(int val, int goal, int incr);
double		fmove_towards(double val, double goal, double incr);
float		fmove_towardsf(float val, float goal, float incr);
long double	fmove_towardsl(long double val, long double goal, long double incr);

#endif
