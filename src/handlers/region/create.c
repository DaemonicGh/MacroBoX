/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:02:39 by daemo             #+#    #+#             */
/*   Updated: 2026/05/29 03:22:54 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/mbx_handlers.h"

t_mbx_region	*mbx_create_region(t_mbx *mbx, t_vec2i size)
{
	return (mbx_create_region_ext(
			mbx, size, sizeof(t_mbx_region))
	);
}

t_mbx_region	*mbx_create_region_with_image(t_mbx *mbx, t_vec2i size)
{
	return (mbx_create_region_ext_with_image(
			mbx, size, sizeof(t_mbx_region))
	);
}

t_mbx_region	*mbx_create_region_from_image(t_mbx *mbx, t_mbx_image *image)
{
	return (mbx_create_region_ext_from_image(
			mbx, image, sizeof(t_mbx_region))
	);
}

t_mbx_region	*mbx_create_region_from_file(t_mbx *mbx, char *filename)
{
	return (mbx_create_region_ext_from_file(
			mbx, filename, sizeof(t_mbx_region))
	);
}

t_mbx_region	*mbx_create_region_from_file_with_image(
	t_mbx *mbx, char *filename)
{
	return (mbx_create_region_ext_from_file_with_image(
			mbx, filename, sizeof(t_mbx_region))
	);
}
