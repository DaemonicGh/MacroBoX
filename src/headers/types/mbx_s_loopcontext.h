/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbx_s_loopcontext.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:08:05 by rprieur           #+#    #+#             */
/*   Updated: 2026/01/15 00:05:26 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MBX_S_LOOPCONTEXT_H
# define MBX_S_LOOPCONTEXT_H

# include "../../../includes/modules/types/mbx_s_mbx.h"

typedef struct s__mbxloopcontext
{
	t_mbx	*mbx;
	void	(*update)(t_mbx *mbx, void *args);
	void	*args;
}	t__mbxloopcontext;

#endif
