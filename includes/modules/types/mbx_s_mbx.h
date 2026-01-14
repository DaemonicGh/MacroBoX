/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_mbx.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:35:40 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:23:58 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_S_MBX_H
# define MBX_S_MBX_H

# include "mbx_s_settings.h"
# include "mbx_s_window.h"
# include "mbx_s_region.h"
# include "mbx_s_font.h"
# include "mbx_s_inputs.h"
# include "mbx_s_time.h"
# include "mbx_s_image.h"

typedef struct s_mbxcontext
{
	mlx_context		mlx;
	t_mbxsettings	settings;
	t_mbxwindow		window;
	t_mbxregion		viewport;
	t_mbxfont		font;
	t_mbxinputs		inputs;
	t_mbxtime		time;
}	t_mbx;

#endif
