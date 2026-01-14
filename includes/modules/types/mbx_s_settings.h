/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_settings.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:41:05 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/14 23:23:25 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_S_SETTINGS_H
# define MBX_S_SETTINGS_H

# include "mbx_s_color.h"

typedef struct s_mbxsettings
{
	t_mbxcolor	background_color;
	int			fps_cap;
}	t_mbxsettings;

#endif
