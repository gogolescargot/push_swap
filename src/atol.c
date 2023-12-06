/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:24:29 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 01:24:29 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	atol(const char *nptr)
{
	size_t	i;
	size_t	r;
	int		m;

	i = 0;
	r = 0;
	m = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == 45)
	{
		m = -1;
		i++;
	}
	else if (nptr[i] == 43)
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
		r = nptr[i++] - 48 + (r * 10);
	return (r * m);
}
