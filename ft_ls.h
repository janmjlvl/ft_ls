/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:50:02 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/15 13:58:03 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

typedef	struct	s_ls_options
{
	char	**names;
	int		files_nbr;
	int		a;
	int		l;
	int		mr;
	int		r;
	int		t;
}				t_ls_options;

void		ft_display_tab(char **tab, t_ls_options* opts);
char		**ft_list_dir(char *dirname);
int			ft_ptrlen(char **tab);

#endif
