/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 03:51:01 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/18 22:40:33 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/veclc_s_vec2.h"

t_vec2	vec2_exec(double (*f) (double), t_vec2 p)
{
	return ((t_vec2){
		.x = f(p.x),
		.y = f(p.y),
	});
}

t_vec2i	vec2i_exec(int (*f)(int), t_vec2i p)
{
	return ((t_vec2i){
		.x = f(p.x),
		.y = f(p.y),
	});
}
