/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 14:31:38 by jabadie           #+#    #+#             */
/*   Updated: 2014/11/20 19:10:22 by jabadie          ###   ########.fr       */
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

	i_tmp = tmp[j];
	c_tmp = tab[j];
	tmp[j] = tmp[i];
	tab[j] = tab[i];
	tmp[i] = i_tmp;
	tab[i] = c_tmp;
}
