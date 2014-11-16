/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 10:31:47 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/16 10:52:53 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	t_ls_options opts;

	ft_ls_processargs(argc, argv, &opts);
	ft_redirec(&opts);
	return (0);
}

/*int		main(int argc, char **argv)
{
	t_ls_options opts;
	(void)argc;
	ft_bzero(&opts, sizeof(t_ls_options));
	ft_display_tab(ft_list_dir(argv[1]), &opts);
	return (0);
}*/
