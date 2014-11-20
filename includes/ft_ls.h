/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:50:02 by vle-guen          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

typedef	struct	s_ls_options
{
	char	**names;
	int		files_nbr;
	int		one;
	int		mc;
	int		a;
	int		ma;
	int		l;
	int		f;
	int		g;
	int		mr;
	int		ms;
	int		d;
	int		m;
	int		r;
	int		t;
	int		u;
	int		termwidth;
}				t_ls_options;

void		ft_display_tab(char *dir, char **tab, t_ls_options* opts);
char		**ft_list_dir(char *dirname);
int			ft_ptrlen(char **tab);
void		sortlg_tab(char	**tab);
int			splitnames(char **tab, char ***files, char ***dir);
void		ft_redirec(t_ls_options *opts);
char		**sorttime_tab(char *dir, char **tab);
void		revsortlg_tab(char **tab);
void		ft_ls_processargs(int argc, char **argv, t_ls_options *opts);
void		ft_bigr(t_ls_options *opts, char *dir, int i, int first);
char		**sortsize_tab(char *dir, char **tab);
char		**ft_ls_striphidden(char **tab);
char		*ft_make_path(char *dir, char *ret);
char		**sort_last_acces(char *dir, char **tab);
char		**ft_ls_stripdot(char **tab);
char		**r_sorttime_tab(char *dir, char **tab);
char		**r_sortsize_tab(char *dir, char **tab);
char		**r_sort_last_acces(char *dir, char **tab);
int			ft_optl(char *dir, char **tab, t_ls_options *opts);
int			simul_log(int n);
void		all_quick_sort(char **tab, int first, int last, int depth);
void		rev_quick_sort(char **tab, int first, int last, int depth);
void		opt_sort(t_ls_options *opts, char *path, char **tab);
void		swap(char **tab, int *tmp, int i, int j);
void		int_quick_sort(char **tab, int *tmp, int start, int end);
void		r_int_quick_sort(char **tab, int *tmp, int start, int end);
void		sortlg_after(char **tab, int *tmp);
void		r_sortlg_after(char **tab, int *tmp);

void	rev_heap_sort(char **tab, int first, int size);

#endif
