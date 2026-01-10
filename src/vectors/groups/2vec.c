/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2vec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 22:53:39 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/10 00:09:21 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mbx.h"

t_2vec2	t2vec2(t_vec2 p1, t_vec2 p2)
{
	return ((t_2vec2){.p1 = p1, .p2 = p2});
}

t_2vec2i	t2vec2i(t_vec2i p1, t_vec2i p2)
{
	return ((t_2vec2i){.p1 = p1, .p2 = p2});
}

t_2vec3	t2vec3(t_vec3 p1, t_vec3 p2)
{
	return ((t_2vec3){.p1 = p1, .p2 = p2});
}

t_2vec3i	t2vec3i(t_vec3i p1, t_vec3i p2)
{
	return ((t_2vec3i){.p1 = p1, .p2 = p2});
}
