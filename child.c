/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:21:44 by mjales            #+#    #+#             */
/*   Updated: 2023/02/22 18:21:58 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child(char **teste, char **argv, char **envp, int pid[2])
{
	int		infile;

	close(pid[0]);
	infile = open(argv[1], O_RDONLY | O_CREAT);
	dup2(infile, 0);
	dup2(pid[1], 1);
	return (execve(teste[0], teste, envp));
}

int	process_child(char **child_arg, char **argv, char **envp, int pid[2])
{
	int	i;

	i = fork();
	if (i == -1)
		return (2);
	if (!i)
		child(child_arg, argv, envp, pid);
	else
	{
		wait(NULL);
		close(pid[1]);
	}
	return (0);
}