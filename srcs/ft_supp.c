/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 20:23:16 by jabadie           #+#    #+#             */
/*   Updated: 2015/02/12 15:59:50 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ptrlen(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i] != NULL)
		i++;
	return (i);
}

void	ft_intswap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_tabswap(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap(char **tab, long int *tmp, int i, int j)
{
	long int	i_tmp;
	char		*c_tmp;

	i_tmp = tmp[i];
	c_tmp = tab[i];
	tmp[i] = tmp[j];
	tab[i] = tab[j];
	tmp[j] = i_tmp;
	tab[j] = c_tmp;
}

int		simul_log(int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i * 3);
}
