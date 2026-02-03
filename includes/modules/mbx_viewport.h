/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_viewport.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:46:58 by rprieur           #+#    #+#             */
/*   Updated: 2026/02/03 17:46:58 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_VIEWPORT_H
# define MBX_VIEWPORT_H

# include "types/mbx_s_mbx.h"

/**
 * Resizes the viewport.
 *
 * @mbx		The MacroBoX context.
 * @size	The new size of the viewport.
 *
 * This function can fail allocation, then it will return false.
 * It is recommended to call this function before any draw call
 * as the content inside the previous viewport will be discarded.
 */
bool	mbx_resize_viewport(t_mbx *mbx, t_vec2i size);

/**
 * Resizes the viewport.
 *
 * @mbx		The MacroBoX context.
 * @width	The new width of the viewport.
 * @height	The new height of the viewport.
 *
 * This function can fail allocation, then it will return false.
 * It is recommended to call this function before any draw call
 * as the content inside the previous viewport will be discarded.
 */
bool	mbx_resize_viewport_xy(t_mbx *mbx, int width, int height);

#endif
