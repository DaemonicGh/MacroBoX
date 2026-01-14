/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_time.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:05:45 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/14 23:23:32 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_S_TIME_H
# define MBX_S_TIME_H

typedef struct s_mbxtime
{
	double			delta;
	double			frame_start;
	double			app_start;
	double			sec_per_frame;
	unsigned long	frames_elapsed;
}	t_mbxtime;

#endif
