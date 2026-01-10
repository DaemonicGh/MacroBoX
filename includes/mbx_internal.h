/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:50:15 by daemo             #+#    #+#             */
/*   Updated: 2026/01/09 01:55:01 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_INTERNAL_H
# define MBX_INTERNAL_H

# include <stddef.h>
# include "mbx_structs.h"

// Utils

int		bsign(bool positive);
void	*palloc(size_t size, int value);
double	get_sec_since_epoch(void);

void	mbx_start_frame(t_mbx *mbx);
void	mbx_end_frame(t_mbx *mbx);

#endif
