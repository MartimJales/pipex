/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:16:52 by jales             #+#    #+#             */
/*   Updated: 2023/02/22 18:25:56 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**check_path(char *argv, char **path_arg)
{
	char	**teste;
	char	*buffer;
	int		i;

	teste = ft_split(argv, ' ');
	i = 0;
	while (path_arg[i])
	{
		buffer = malloc(ft_strlen(path_arg[i]) + 1);
		ft_strlcpy(buffer, path_arg[i], ft_strlen(path_arg[i]) + 1);
		buffer = junta_strings(buffer, teste[0]);
		if (access(buffer, F_OK) == 0)
		{
			free(teste[0]);
			teste[0] = malloc(ft_strlen(buffer) + 1);
			ft_strlcpy(teste[0], buffer, ft_strlen(buffer) + 1);
			free(buffer);
			return (teste);
		}
		free(buffer);
		i++;
	}
	return (NULL);
}

char	**create_path(char *envp[])
{
	char	*path;
	char	**path_arg;
	int		i;

	i = 0;
	while (envp[i])
	{
		path = ft_strnstr(envp[i], "PATH=", 5);
		if (path)
			break ;
		i++;
	}
	path_arg = ft_split(path + 5, ':');
	i = -1;
	while (path_arg[++i])
		path_arg[i] = junta_strings(path_arg[i], "/");
	return (path_arg);
}