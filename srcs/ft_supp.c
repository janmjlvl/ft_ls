/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 20:23:16 by jabadie           #+#    #+#             */
/*   Updated: 2014/11/20 20:29:04 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ptrlen(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i] != NULL)
		i++;
	return (i);
}

void	swap(char **tab, int *tmp, int i, int j)
{
	int		i_tmp;
	char	*c_tmp;

	i_tmp = tmp[i];
	c_tmp = tab[i];
	tmp[i] = tmp[j];
	tab[i] = tab[j];
	tmp[j] = i_tmp;
	tab[j] = c_tmp;
}

int	simul_log(int n)
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
