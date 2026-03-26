/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:09:31 by rprieur           #+#    #+#             */
/*   Updated: 2026/03/25 15:09:31 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/mbx_s_mbx.h"

t_mbx_color	mbx_color_setter_ignore(void *data, t_mbx_color col)
{
	(void)data;
	return (col);
}

t_mbx_color	mbx_color_getter_ignore(
	void *data, t_mbx_region *region, int index)
{
	(void)data;
	return (region->canvas[index]);
}
