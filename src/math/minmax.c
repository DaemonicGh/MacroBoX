/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daemo <daemo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:01:53 by daemo             #+#    #+#             */
/*   Updated: 2025/12/27 20:28:08 by daemo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mbx.h"

int	min(int val1, int val2)
{
	if (val1 < val2)
		return (val1);
	return (val2);
}

int	max(int val1, int val2)
{
	if (val1 > val2)
		return (val1);
	return (val2);
}
