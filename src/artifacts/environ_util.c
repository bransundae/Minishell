/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 14:06:09 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/12 14:31:41 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

int				environ_search(char **env, char *pair, int split)
{
	size_t		counter;

	counter = -1;
	while (++counter < ft_sstrlen(env))
	{
		if (ft_strncmp(env[counter], pair, split) == 0)
			return (counter);
	}
	return (-1);
}

char			*environ_get_value(char **env, int pos)
{
	size_t		counter;

	counter = -1;
	while (++counter < ft_strlen(env[pos]))
	{
		if (env[pos][counter] == '=')
			return (env[pos] + counter + 1);
	}
	return (NULL);
}

char			*environ_pair_clone(char *original)
{
	size_t		len;
	size_t		counter;
	char		*clone;

	len = ft_strlen(original);
	counter = -1;
	clone = (char *)malloc(sizeof(char) * (ft_strlen(original) + 1));
	while (++counter < len)
	{
		clone[counter] = original[counter];
	}
	clone[len] = '\0';
	return (clone);
}