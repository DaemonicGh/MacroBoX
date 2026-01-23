/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_inputs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:02:12 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/24 00:08:49 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_S_INPUTS_H
# define MBX_S_INPUTS_H

# include "../../../VecLibC/includes/modules/types/veclc_s_vec2i.h"
# include "../consts/mbx_c_input_arrays.h"

/**
 * Struct holding all input data.
 *
 * @btn array containing the active state of each button.
 * @btnp array containing the state of each button just pressed.
 * @btnr array containing the state of each button just released.
 * @last_key the last key pressed.
 * @mouse the current mouse position.
 * @mouse_delta the change in mouse position since the last frame.
 * @mouse_wheel the current mouse wheel state
 * (negative if scrolling down, positive if scrolling up).
 * @should_exit whether the application has been requested to exit.
 */
typedef struct s_mbxinputs
{
	bool		btn[MBX_INPUT_ARRAY_LENGTH];
	bool		btnp[MBX_INPUT_ARRAY_LENGTH];
	bool		btnr[MBX_INPUT_ARRAY_LENGTH];
	int			last_key;
	t_vec2i		mouse;
	t_vec2i		mouse_delta;
	int			mouse_wheel;
	bool		should_exit;
}	t_mbxinputs;

#endif
