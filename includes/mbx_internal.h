/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:50:15 by daemo             #+#    #+#             */
/*   Updated: 2025/12/27 21:05:13 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_INTERNAL_H
# define MBX_INTERNAL_H

# include "mbx_structs.h"

void	mbx_start_frame(t_mbxcontext *mbx);
void	mbx_end_frame(t_mbxcontext *mbx);

#endif