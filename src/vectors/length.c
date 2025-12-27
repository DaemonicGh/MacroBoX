/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:19:40 by daemo             #+#    #+#             */
/*   Updated: 2025/12/23 17:22:10 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

double	vec2_length(t_vec2 p)
{
	return (sqrt(p.x * p.x + p.y * p.y));
}

double	vec2i_length(t_vec2i p)
{
	return (sqrt(p.x * p.x + p.y * p.y));
}

double	vec3_length(t_vec3 p)
{
	return (sqrt(p.x * p.x + p.y * p.y + p.z * p.z));
}

double	vec3i_length(t_vec3i p)
{
	return (sqrt(p.x * p.x + p.y * p.y + p.z * p.z));
}
