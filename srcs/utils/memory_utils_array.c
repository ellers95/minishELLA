/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaattol <etaattol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:23:04 by etaattol          #+#    #+#             */
/*   Updated: 2024/09/17 19:08:10 by etaattol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Frees a 2D array of strings and sets the pointer to NULL.
 * If arc is -1, frees all elements until a NULL pointer is encountered.
 * If arc is >= 0, frees the specified number of elements.
*/
void	free_array(char ***paths, int arc)
{
	int	i;

	if (paths == NULL)
		return ;
	i = 0;
	if (arc == -1)
	{
		while ((*paths)[i] != NULL)
		{
			ft_free((*paths)[i]);
			i++;
		}
	}
	else
	{
		while (i < arc)
		{
			if ((*paths)[i] != NULL)
				ft_free((*paths)[i]);
			i++;
		}
	}
	ft_free(*paths);
	*paths = NULL;
}

/*
 * Frees a dynamically allocated array of strings.
 * Frees each string in the array and then the array itself.
*/
char	*free_char_array(char **array)
{
	size_t	i;

	if (array == NULL)
		return (NULL);
	i = 0;
	while ((array)[i] != NULL)
	{
		ft_free((array)[i]);
		(array)[i] = NULL;
		i++;
	}
	ft_free(array);
	return (NULL);
}

/*
 * Frees an array of argument strings and a path string.
 * Typically used for cleaning up after command execution.
*/
void	free_stuff(char **args, char *path)
{
	int	i;

	i = 0;
	while (args[i])
	{
		ft_free(args[i]);
		i++;
	}
	ft_free(args);
	if (path)
		ft_free(path);
}

/*
 * Frees an array of path strings.
 * If arc is -1, frees all elements until a NULL pointer is encountered.
 * If arc is >= 0, frees the specified number of elements.
*/
void	free_line(char **paths, int arc)
{
	int	i;

	if (paths == NULL)
		return ;
	i = 0;
	if (arc == -1)
	{
		while (paths[i] != NULL)
		{
			ft_free(paths[i]);
			i++;
		}
	}
	else
	{
		while (i < arc)
		{
			if (paths[i] != NULL)
				ft_free(paths[i]);
			i++;
		}
	}
	ft_free(paths);
	paths = NULL;
}
