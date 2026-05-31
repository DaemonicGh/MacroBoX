/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 19:38:22 by rprieur           #+#    #+#             */
/*   Updated: 2026/05/31 19:38:22 by rprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "modules/mbx_core.h"

void	write_u32(int fd, uint32_t nbr)
{
	char		nbr_repr[10];
	uint32_t	nbr2;
	int			end;
	int			i;

	nbr2 = nbr;
	i = (nbr == 0);
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	end = i;
	while (i--)
	{
		nbr_repr[i] = nbr2 % 10 + '0';
		nbr2 /= 10;
	}
	write(fd, nbr_repr, end);
}

static void	report_prefix(t_mbx *mbx)
{
	if (mbx->frames_elapsed)
	{
		write(STDOUT_FILENO, "\e[0;1;34m[MacroBoX\e[2m@", 23);
		write_u32(STDOUT_FILENO, mbx->frames_elapsed);
		write(STDOUT_FILENO, "\e[0;1;34m]\e[22m ", 16);
	}
	else
		write(STDOUT_FILENO, "\e[0;1;34m[MacroBoX]\e[22m ", 25);
}

void	mbx_report(t_mbx *mbx, const char *str)
{
	size_t	len;

	if (!MBX_DEBUG)
		return ;
	len = 0;
	while (str[len])
		len++;
	report_prefix(mbx);
	write(STDOUT_FILENO, str, len);
	write(STDOUT_FILENO, ".\e[0m\n", 6);
}

void	mbx_report_nbr(t_mbx *mbx,
	const char *pref, uint32_t nbr, const char *suf)
{
	size_t	len;

	if (!MBX_DEBUG)
		return ;
	len = 0;
	while (pref[len])
		len++;
	report_prefix(mbx);
	write(STDOUT_FILENO, pref, len);
	write_u32(STDOUT_FILENO, nbr);
	len = 0;
	while (suf[len])
		len++;
	write(STDOUT_FILENO, suf, len);
	write(STDOUT_FILENO, ".\e[0m\n", 6);
}

void	mbx_report_mem(t_mbx *mbx, const char *pref, uint32_t nbr)
{
	size_t	len;

	if (!MBX_DEBUG)
		return ;
	len = 0;
	while (pref[len])
		len++;
	report_prefix(mbx);
	write(STDOUT_FILENO, "\e[2;30m", 8);
	write(STDOUT_FILENO, pref, len);
	write(STDOUT_FILENO, "\e[22m", 5);
	write_u32(STDOUT_FILENO, nbr);
	write(STDOUT_FILENO, "\e[2m. (", 7);
	write_u32(STDOUT_FILENO, mbx->allocator.alloc_count);
	write(STDOUT_FILENO, " total)\e[0m\n", 12);
}
