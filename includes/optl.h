/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:51:55 by nmeier            #+#    #+#             */
/*   Updated: 2015/02/17 13:08:57 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTL_H
# define OPTL_H

int		display_name(char *dir, char *files);
int		display_acl(char *dir, char *files);
int		display_exattributes(char *dir, char *files);
int		display_type(char *path);
int		displayrights(char *pathtmp, char *dir, char *file);

int		display_chmod1(char *path);
int		display_chmod2(char *path);
int		display_chmod3(char *path);

int		find_intlength(int n);
int		find_maxlength(char *dir, char **path, int flag);
int		find_maxcharlength(char *dir, char **path, int flag);

int		display_spacingint(int n, int k);
int		display_spaceuid(char *name, int k);
char	*display_modiftime(char *s, int flag);
int		display_total(char *dir, char **files);
void	displaynames(struct stat buf, int *tab, t_ls_options *opts);

#endif
