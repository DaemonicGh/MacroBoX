/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:35:12 by daemo             #+#    #+#             */
/*   Updated: 2026/01/19 15:14:38 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/types/mbx_s_color.h"

t_mbx_color	color(unsigned int hex)
{
	return ((t_mbx_color){.rgba = hex << 8 | 0xFF});
}

t_mbx_color	color_rgba(unsigned int hex)
{
	return ((t_mbx_color){.rgba = hex});
}

t_mbx_color	color_opaque(t_mbx_color col)
{
	return ((t_mbx_color){.rgba = col.rgba | 0xFF});
}
