/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:22:25 by mjales            #+#    #+#             */
/*   Updated: 2023/02/22 18:22:39 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parent(char **teste, char **argv, char **envp, int pid[2])
{
	int		outfile;

	close(pid[1]);
	outfile = open(argv[4], O_WRONLY | O_CREAT);
	dup2(pid[0], 0);
	dup2(outfile, 1);
	return (execve(teste[0], teste, envp));
}



int	process_parent(char **parent_arg, char **argv, char **envp, int pid[2])
{
	int	i;

	i = fork();
	if (i == -1)
		return (2);
	if (!i)
		parent(parent_arg, argv, envp, pid);
	else
	{
		wait(NULL);
	}
	return (0);
}