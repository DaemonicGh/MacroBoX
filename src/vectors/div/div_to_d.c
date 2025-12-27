/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_to_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:03:49 by daemo             #+#    #+#             */
/*   Updated: 2025/12/23 18:28:47 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mbx.h"

t_vec2	vec2_div_to_d(t_vec2 *p, double val)
{
	p->x /= val;
	p->y /= val;
	return (*p);
}

t_vec3	vec3_div_to_d(t_vec3 *p, double val)
{
	p->x /= val;
	p->y /= val;
	p->z /= val;
	return (*p);
}
