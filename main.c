/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 10:31:47 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/14 17:09:28 by vle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <dirent.h>

int		find_options(t_ls_options *opt, char *s)
{
	if (*s == '\0') /* si l'argument est '-', ls va chercher le fichier intitulé '-'*/
		return (0);
	if (*s == '-' && *s + 1 == '\0')
		return (0);
	if (*s == '-' && *s + 1 != '\0')
		return (-1);
	while (*s != '\0')
	{
		if (*s != 'a' && *s != 'r' && *s != 'R' && *s != 'l' && *s != 't')
			return (-1);
		if (*s == 'a')
			opt->a = 1;
		if (*s == 'r')
			opt->r = 1;
		if (*s == 'R')
			opt->mr =1;
		if (*s == 'l')
			opt->l = 1;
		if (*s == 't')
			opt->t = 1;
		s++;
	}
	return (1);
}

int		find_optoffset(t_ls_options *opt, int argc, char **argv)
{
	int				i;
	int				stop_opt;
	int				opt_offset;

	i = 1;
	stop_opt = 1; /*indicateur de la fin des options (0 ou 1)*/
	opt_offset = 1; /*index des argv indiquant le début des filenames*/
	while (i < argc)
	{
		if (argv[i][0] == '-' && stop_opt == 1)
		{
			if ((stop_opt = find_options(opt, &(argv[i][1]))) == 0)
				opt_offset = i + 1;
		}
		else if (stop_opt == 1)
		{
			opt->files_nbr++; /*on a notre files_nbr complété*/
			stop_opt = 0;
			opt_offset = i;
		}
		else
			opt->files_nbr++;
		i++;
	}
	return (opt_offset);
}

void	find_filenames(t_ls_options *opt, char **argv, int opt_offset)
{
	int	i;

	i = 0;
	if (opt->files_nbr != 0)
	{
		opt->names = (char **)malloc(sizeof(char*) * (opt->files_nbr + 1));
		while (i < opt->files_nbr)
		{
			opt->names[i] = argv[opt_offset + i];
			i++;
		}
		opt->names[i] = NULL;
	}
	else
	{
		opt->names = (char **)malloc(sizeof(char*) * 2);
		opt->files_nbr = 1;
		opt->names[0] = ft_strdup(".");
		opt->names[1] = NULL;
	}
}
/*int		main(int argc, char **argv)
{
	DIR				*dirp;
	struct dirent	*dp;
	(void)argv;

	opt_offset = find_optoffset(opt, argc, argv);
	find_filenames(opt, argv, opt_offset);


	if (argc == 1)
	{
		dirp = opendir(".");
		if (!dirp)
			return (-1);
		while ((dp = readdir(dirp)))
		{
			if (dp->d_name[0] != '.')
				ft_putendl(dp->d_name);
		}
		closedir(dirp);
	}
	return (0);
}
