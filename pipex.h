/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:42:09 by mjales            #+#    #+#             */
/*   Updated: 2023/02/22 18:24:29 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/wait.h>
# include <fcntl.h>

int		child(char **teste, char **argv, char **envp, int pid[2]);
int		process_child(char **child_arg, char **argv, char **envp, int pid[2]);
int		parent(char **teste, char **argv, char **envp, int pid[2]);
int		process_parent(char **child_arg, char **argv, char **envp, int pid[2]);
char	**check_path(char *argv, char **path_arg);
char	**create_path(char *envp[]);
char	*junta_strings(char *s1, char *s2);

#endif
