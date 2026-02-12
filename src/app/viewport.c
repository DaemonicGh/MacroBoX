/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:56:25 by rprieur           #+#    #+#             */
/*   Updated: 2026/02/05 05:33:42 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules/veclc_vec2i.h"
#include "modules/mbx_drawing.h"
#include "modules/mbx_math.h"
#include "modules/mbx_region.h"
#include "modules/mbx_image.h"
#include "modules/mbx_window.h"
#include "modules/mbx_mlx_ext.h"

bool	mbx_resize_viewport(t_mbx *mbx, t_vec2i size)
{
	t_mbxregion	new;

	new = mbx_make_region_with_image(mbx, size);
	if (!new.canvas)
		return (false);
	mbx_destroy_region(mbx, &mbx->viewport);
	mbx->viewport = new;
	return (true);
}

/* ALT, not working
	t_mbximage			img;
	t_mbxwindow			win;
	t_mbxregion			new;

	img = mbx_make_image(mbx, size);
	if (!img.img)
		return (false);
	win = mbx_make_window_target(mbx, img);
	if (!win.win)
		return (false);
	mlx_clear_window(mbx->mlx, win.win, color(0xFFFFFF));
	mlx_set_image_region(mbx->mlx, mbx->viewport.image, 0, 0,
		mbx->viewport.size.x, mbx->viewport.size.y, mbx->viewport.canvas);
	mlx_put_transformed_image_to_window(mbx->mlx, win.win, mbx->viewport.image,
		0, 0, (float)win.size.x / mbx->viewport.size.x,
		(float)win.size.y / mbx->viewport.size.y, 0);
	new = mbx_make_region_from_image(mbx, &img);
	if (!new.canvas)
		return (false);
	//mbx_set_region_region_scaled(&new, &mbx->viewport, vec2i(0, 0),
	//	vec2i_truediv(size, mbx->viewport.size));
	mbx_destroy_region(mbx, &mbx->viewport);
	mbx_destroy_window(mbx, &win);
	mbx->viewport = new;
	return (true);
 */
bool	mbx_resize_viewport_with_content(t_mbx *mbx, t_vec2i size)
{
	t_mbxregion			new;

	new = mbx_make_region_with_image(mbx, size);
	if (!new.canvas)
		return (false);
	mbx_set_region_region_scaled(&new, &mbx->viewport, vec2i(0, 0),
		vec2i_truediv(size, mbx->viewport.size));
	mbx_destroy_region(mbx, &mbx->viewport);
	mbx->viewport = new;
	return (true);
}

void	draw_viewport(t_mbx *mbx)
{
	const int			scale = min(
			mbx->window.size.x / mbx->viewport.size.x,
			mbx->window.size.y / mbx->viewport.size.y);
	const t_vec2i		size = vec2i(mbx->viewport.size.x * scale,
			mbx->viewport.size.y * scale);

	mlx_set_image_region(mbx->mlx, mbx->viewport.image, 0, 0,
		mbx->viewport.size.x, mbx->viewport.size.y, mbx->viewport.canvas);
	mlx_put_transformed_image_to_window(mbx->mlx, mbx->window.win,
		mbx->viewport.image, (mbx->window.size.x - (size.x)) / 2,
		(mbx->window.size.y - (size.y)) / 2, scale, scale, 0);
}
