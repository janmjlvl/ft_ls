/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_processargs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 10:35:02 by nmeier            #+#    #+#             */
/*   Updated: 2015/02/12 15:07:45 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>

int			getcolwidth(void)
{
	char			*str;
	struct winsize	window;

	if ((str = getenv("COLUMNS")) != NULL)
		return (ft_atoi(str));
	else if (ioctl(1, TIOCGWINSZ, &window) == 0 && window.ws_col > 0)
		return (window.ws_col);
	return (80);
}

static int	checkarg(char **argv, int *stop_opt, t_ls_options *opt, int i)
{
	int opt_offset;

	if (argv[i][0] == '-' && *stop_opt == 1)
	{
		if ((*stop_opt = find_options(opt, &(argv[i][1]))) != 1)
		{
			if (*stop_opt == -1)
			{
				opt_offset = i;
				opt->files_nbr++;
			}
			else
				opt_offset = i + 1;
		}
	}
	else if (*stop_opt == 1)
	{
		opt->files_nbr++;
		*stop_opt = 0;
		opt_offset = i;
	}
	else
		opt->files_nbr++;
	return (opt_offset);
}

int			find_optoffset(t_ls_options *opt, int argc, char **argv)
{
	int				i;
	int				stop_opt;
	int				opt_offset;

	i = 1;
	stop_opt = 1;
	opt_offset = 1;
	while (i < argc)
	{
		opt_offset = checkarg(argv, &stop_opt, opt, i);
		i++;
	}
	return (opt_offset);
}

void		find_filenames(t_ls_options *opt, char **argv, int opt_offset)
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

void		ft_ls_processargs(int argc, char **argv, t_ls_options *opts)
{
	int opt_offset;

	ft_bzero(opts, sizeof(t_ls_options));
	opts->termwidth = getcolwidth();
	opt_offset = find_optoffset(opts, argc, argv);
	if (!isatty(fileno(stdout)) && opts->l == 0)
		opts->one = 1;
	find_filenames(opts, argv, opt_offset);
}
