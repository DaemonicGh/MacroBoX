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

t_mbxcolor	color(unsigned int hex)
{
	return ((t_mbxcolor){.rgba = hex << 8 | 0xFF});
}

t_mbxcolor	color_rgba(unsigned int hex)
{
	return ((t_mbxcolor){.rgba = hex});
}

t_mbxcolor	color_opaque(t_mbxcolor col)
{
	return ((t_mbxcolor){.rgba = col.rgba | 0xFF});
}
