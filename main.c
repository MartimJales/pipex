/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:41:40 by mjales            #+#    #+#             */
/*   Updated: 2023/02/22 18:23:51 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clean_all(char **path_arg, char **child_arg, char **parent_arg)
{
	int	i;

	i = 0;
	while (path_arg[i])
	{
		free(path_arg[i]);
		i++;
	}
	free(path_arg);
	i = 0;
	while (child_arg[i])
	{
		free(child_arg[i]);
		i++;
	}
	free(child_arg);
	i = 0;
	while (parent_arg[i])
	{
		free(parent_arg[i]);
		i++;
	}
	free(parent_arg);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		pid[2];
	char	**path_arg;
	char	**child_arg;
	char	**parent_arg;

	(void)argc;
	if (pipe(pid) == -1)
		return (1);
	path_arg = create_path(envp);
	child_arg = check_path(argv[2], path_arg);
	parent_arg = check_path(argv[3], path_arg);
	process_child(child_arg, argv, envp, pid);
	process_parent(parent_arg, argv, envp, pid);
	clean_all(path_arg, child_arg, parent_arg);
	return (0);
}
