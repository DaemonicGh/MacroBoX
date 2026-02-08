/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_settings.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:38:32 by rprieur           #+#    #+#             */
/*   Updated: 2026/02/08 08:54:24 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "types/mbx_s_mbx.h"

/**
 * Resets the settings to their default values.
 *
 * @mbx the MacroBox context.
 */
void			mbx_reset_settings(t_mbx *mbx);

/**
 * Updates the elements affected by settings.
 *
 * @mbx the MacroBox context.
 */
void			mbx_refresh_settings(t_mbx *mbx);
