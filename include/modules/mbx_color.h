/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_color.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:13:57 by rprieur           #+#    #+#             */
/*   Updated: 2026/02/08 08:54:24 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "types/mbx_s_color.h"

/**
 * Creates and returns an opaque version of the given color.
 */
t_mbxcolor		color_opaque(t_mbxcolor col);

/**
 * Blends two color together, respecting transparency.
 *
 * @bg the background color.
 * @fg the foreground color.
 */
t_mbxcolor		color_blend(t_mbxcolor bg, t_mbxcolor fg);

/**
 * Blends two color together, respecting transparency.
 *
 * @bg the background color.
 * @fg the foreground color.
 *
 * this version does not optimize if fg is fully opaque or transparent,
 * use it when you know that fg isn't either.
 */
t_mbxcolor		color_blend_quick(t_mbxcolor bg, t_mbxcolor fg);
