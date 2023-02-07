/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:41:40 by mjales            #+#    #+#             */
/*   Updated: 2023/02/07 00:49:13 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		i;
	char	**teste;
	// char	*path;
	int		infile;
	int		outfile;
	int		pid[2];

	(void)argc;
	(void)envp;
	(void)argv;
	if (pipe(pid) == -1)
	{
		printf("Error no pipe\n");
		return (1);
	}
	// for(int i = 0; envp[i]; i++)
	// {
	// 	path = ft_strnstr(envp[i], "PATH=/", ft_strlen(envp[i]));
	// 	if (path)
	// 		break ;
	// }
	// path = path +5;
	i = fork();
	if (i == -1)
	{
		printf("Erro no fork\n");
		return (2);
	}
	if (!i)
	{
		close(pid[0]);
		infile = open(argv[1], O_RDONLY);
		dup2(infile, 0);
		dup2(pid[1], 1);
		argv[2] = ft_strjoin("/bin/", argv[2]);
		teste = ft_split(argv[2], ' ');
		execve(teste[0], teste, NULL);
	}
	else
	{
		wait(NULL);
		close(pid[1]);
		outfile = open(argv[4], O_WRONLY);
		dup2(pid[0], 0);
		dup2(outfile, 1);
		argv[3] = ft_strjoin("/bin/", argv[3]);
		teste = ft_split(argv[3], ' ');
		execve(teste[0], teste, NULL);
	}
	printf("hellof from dad\n");

}
