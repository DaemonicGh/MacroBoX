/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_inputs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:02:12 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:04:02 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_S_INPUTS_H
# define MBX_S_INPUTS_H

# include "../../../VecLibC/includes/modules/types/veclc_s_vec2i.h"
# include "../consts/mbx_c_input_arrays.h"

typedef struct s_mbxinputs
{
	bool		btn[MBX_INPUT_ARRAY_LENGTH];
	bool		btnp[MBX_INPUT_ARRAY_LENGTH];
	bool		btnr[MBX_INPUT_ARRAY_LENGTH];
	int			last_key;
	t_vec2i		mouse;
	t_vec2i		prev_mouse;
	int			mouse_wheel;
	bool		should_exit;
}	t_mbxinputs;

#endif
