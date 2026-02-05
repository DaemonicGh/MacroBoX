/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_viewport.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:46:58 by rprieur           #+#    #+#             */
/*   Updated: 2026/02/05 04:14:00 by rprieur          ###   ########.fr       */
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
 */
bool	mbx_resize_viewport(t_mbx *mbx, t_vec2i size);

/**
 * Resizes the viewport and its content.
 *
 * @mbx		The MacroBoX context.
 * @size	The new size of the viewport.
 *
 * This function can fail allocation, then it will return false.
 * The content of the viewport will stretch to fit the new size.
 */
bool	mbx_resize_viewport_with_content(t_mbx *mbx, t_vec2i size);

#endif
