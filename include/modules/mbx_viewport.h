/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_viewport.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:46:58 by rprieur           #+#    #+#             */
/*   Updated: 2026/02/08 08:54:24 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "types/mbx_s_mbx.h"

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
