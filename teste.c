/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:35:30 by mjales            #+#    #+#             */
/*   Updated: 2023/02/14 19:37:27 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "pipex.h"

char	*junta_strings(char *s1, char *s2)
{
	char	*buffer;

	buffer = malloc(ft_strlen(s1) + 1);
	ft_strlcpy(buffer, s1, ft_strlen(s1) + 1);
	free(s1);
	s1 = ft_strjoin(buffer, s2);
	free(buffer);
	return (s1);
}
