/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_inputs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:34:58 by rprieur           #+#    #+#             */
/*   Updated: 2026/02/08 08:54:24 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "types/mbx_s_mbx.h"

/**
 * Returns true if a key has just been pressed.
 *
 * @mbx the MacroBoX context.
 * @key the key to check.
 *
 * see MBX_KEY_*, MBX_MOUSE_* and MBX_WINDOW_* for key codes.
 */
bool	mbx_key_pressed(t_mbx *mbx, int key);

/**
 * Returns true if a key is currently held.
 *
 * @mbx the MacroBoX context.
 * @key the key to check.
 *
 * see MBX_KEY_*, MBX_MOUSE_* and MBX_WINDOW_* for key codes.
 */
bool	mbx_key_held(t_mbx *mbx, int key);

/**
 * Returns true if a key has just been released.
 *
 * @mbx the MacroBoX context.
 * @key the key to check.
 *
 * see MBX_KEY_*, MBX_MOUSE_* and MBX_WINDOW_* for key codes.
 */
bool	mbx_key_released(t_mbx *mbx, int key);

/**
 * Returns true if a key has just been pressed.
 *
 * @mbx the MacroBoX context.
 * @key the key to check.
 *
 * see MBX_KEY_*, MBX_MOUSE_* and MBX_WINDOW_* for key codes.
 */
bool	mbx_btnp(t_mbx *mbx, int key);

/**
 * Returns true if a key is currently held.
 *
 * @mbx the MacroBoX context.
 * @key the key to check.
 *
 * see MBX_KEY_*, MBX_MOUSE_* and MBX_WINDOW_* for key codes.
 */
bool	mbx_btn(t_mbx *mbx, int key);

/**
 * Returns true if a key has just been released.
 *
 * @mbx the MacroBoX context.
 * @key the key to check.
 *
 * see MBX_KEY_*, MBX_MOUSE_* and MBX_WINDOW_* for key codes.
 */
bool	mbx_btnr(t_mbx *mbx, int key);

/**
 * Forces the press of a key for one frame.
 *
 * @mbx the MacroBoX context.
 * @key the key to press.
 *
 * This function doesn't trigger the btn array.
 */
void	mbx_tap_input(t_mbx *mbx, int key);

/**
 * Forces the press of a key indefinitely.
 *
 * @mbx the MacroBoX context.
 * @key the key to press.
 *
 * Calling mbx_release_key() or releasing the physical key will stop the hold.
 */
void	mbx_press_input(t_mbx *mbx, int key);

/**
 * Forces the release of a key.
 *
 * @mbx the MacroBoX context.
 * @key the key to release.
 */
void	mbx_release_input(t_mbx *mbx, int key);

/**
 * Warps the mouse cursor to the given position.
 *
 * @mbx the MacroBoX context.
 * @x the new x position.
 * @y the new y position.
 *
 * The warp won't update cursor_delta, use
 * mbx_move_cursor if it should
 */
void	mbx_warp_cursor(t_mbx *mbx, t_vec2i pos);

/**
 * Warps the mouse cursor to the given position.
 *
 * @mbx the MacroBoX context.
 * @x the new x position.
 * @y the new y position.
 *
 * The movement will update cursor_delta, use
 * mbx_warp_cursor if it shouldn't
 */
void	mbx_move_cursor(t_mbx *mbx, t_vec2i pos);

/**
 * Updates all inputs like if a frame passed.
 *
 * @mbx the MacroBoX context.
 */
void	mbx_flush_inputs(t_mbx *mbx);
