/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:35:04 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/08 13:59:18 by vle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\r' || c == '\v' || c == '\f' || c == '\n')
		return (1);
	else if (c == ' ')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		nbr;
	int		neg;

	i = 0;
	nbr = 0;
	neg = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		nbr = 0;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	nbr = nbr * neg;
	return (nbr);
}
