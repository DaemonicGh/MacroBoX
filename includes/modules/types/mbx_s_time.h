/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_time.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:05:45 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/19 13:13:35 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_S_TIME_H
# define MBX_S_TIME_H

/**
 * Struct containing MacroBox application's time related data.
 *
 * @delta			time in seconds spent in the last frame.
 * @frame_start		timestamp at the beginning of the last frame.
 * @app_start		time at the start of the application.
 * @sec_per_frame	time spent processing the last frame.
 * @frames_elapsed	number of frames elapsed since the start of the application.
 */
typedef struct s_mbxtime
{
	double			delta;
	double			frame_start;
	double			app_start;
	double			sec_per_frame;
	unsigned long	frames_elapsed;
}	t_mbxtime;

#endif
