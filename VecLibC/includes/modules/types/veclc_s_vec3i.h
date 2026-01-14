/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclc_s_vec3i.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:26:58 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:00:44 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECLC_S_VEC3I_H
# define VECLC_S_VEC3I_H

typedef struct s_vec3i
{
	int	x;
	int	y;
	int	z;
}	t_vec3i;

t_vec3i		vec3i(int x, int y, int z);

#endif
