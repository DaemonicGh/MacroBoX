/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:59:20 by daemo             #+#    #+#             */
/*   Updated: 2025/12/23 18:28:42 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mbx.h"

t_vec2i	vec2i_add_to_i(t_vec2i *p, int val)
{
	p->x += val;
	p->y += val;
	return (*p);
}

t_vec3i	vec3i_add_to_i(t_vec3i *p, int val)
{
	p->x += val;
	p->y += val;
	p->z += val;
	return (*p);
}
