/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:41:40 by mjales            #+#    #+#             */
/*   Updated: 2023/02/06 17:38:07 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**teste;

	i = 0;
	while (i++ < argc - 1)
	{
		printf("%s\n", argv[i]);
	}
	printf("hello world\n");
	i = fork();
	if (!i)
	{
		printf("===hello from child===\n");
		argv[2] = ft_strjoin("/bin/", argv[2]);
		printf("%s\n", argv[2]);
		teste = ft_split(argv[2], ' ');
		i = -1;
		while(teste[++i])
			printf("teste[%d] = %s\n", i, teste[i]);
		execve(teste[0], teste, NULL);
		argv[3] = ft_strjoin("/bin/", argv[3]);
		printf("%s\n", argv[3]);
		teste = ft_split(argv[3], ' ');
		execve(argv[3], teste, NULL);
		return (0);
	}
	else
	{
		wait(NULL);
	}

	printf("hellof from dad\n");

}
