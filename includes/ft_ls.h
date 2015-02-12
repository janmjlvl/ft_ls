/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 13:48:31 by nmeier            #+#    #+#             */
/*   Updated: 2015/02/12 16:00:20 by nmeier           ###   ########.fr       */
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

typedef struct	s_colparms
{
	int tablen;
	int colnbr;
	int linenbr;
	int maxlen;
}				t_colparms;

void			ft_display_tab(char *d, char **t, t_ls_options *o, int isdir);
void			ft_intswap(int *a, int *b);
void			ft_tabswap(char **a, char **b);
char			**ft_list_dir(char *dirname);
int				ft_ptrlen(char **tab);
void			sortlg_tab(char	**tab);
int				splitnames(char **t, char ***f, char ***d, t_ls_options *opts);
void			ft_redirec(t_ls_options *opts);
char			**sorttime_tab(char *dir, char **tab);
void			revsortlg_tab(char **tab);
void			ft_ls_processargs(int argc, char **argv, t_ls_options *opts);
void			ft_bigr(t_ls_options *opts, char *dir, int i, int *first);
char			**sortsize_tab(char *dir, char **tab);
char			**ft_ls_striphidden(char **tab);
char			*ft_make_path(char *dir, char *ret);
char			**sort_last_acces(char *dir, char **tab);
char			**ft_ls_stripdot(char **tab);
char			**r_sorttime_tab(char *dir, char **tab);
char			**r_sortsize_tab(char *dir, char **tab);
char			**r_sort_last_acces(char *dir, char **tab);
int				ft_optl(char *dir, char **tab, t_ls_options *opts, int isdir);
int				simul_log(int n);
void			all_quick_sort(char **tab, int first, int last, int depth);
void			rev_quick_sort(char **tab, int first, int last, int depth);
void			opt_sort(t_ls_options *opts, char *path, char **tab);
void			swap(char **tab, long int *tmp, int i, int j);
void			int_quick_sort(char **tab, long int *tmp, int start, int end);
void			r_int_quick_sort(char **tab, long int *tmp, int start, int end);
void			sortlg_after(char **tab, long int *tmp);
void			r_sortlg_after(char **tab, long int *tmp);
void			rev_insertion_sort(char **tab, int first, int last);
char			*ft_chooseprint(char *file, t_ls_options *opts);
void			rev_heap_sort(char **tab, int first, int size);
void			heap_sort(char **tab, int first, int size);
void			insertion_sort(char **tab, int first, int last);
void			display_columns(char **tab, int termwidth);
int				find_options(t_ls_options *opt, char *s);

#endif
