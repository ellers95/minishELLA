/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaattol <etaattol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:05:06 by etaattol          #+#    #+#             */
/*   Updated: 2024/09/17 18:58:06 by etaattol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Initializes the environment variable linked list from the provided envp array.
 * Iterates through the envp array, adding each environment variable to the list.
*/
void	load_list(t_data *data, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (add_end(&data->env, envp[i]))
		{
			free_env(&data->env);
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return ;
}

/*
* Finds and returns the last node in the linked list.
*/
t_node	*find_last(t_node	*stack)
{
	t_node	*temp;

	if (!stack)
		return (NULL);
	temp = stack;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

/*
 * Parses a string into key and value components for an environment variable.
 * Splits the string at the '=' character, if present.
*/
t_node	*parse_str(t_node *node, char *env_str)
{
	char	*split;
	int		i;

	i = 0;
	split = ft_strchr(env_str, '=');
	if (!split)
	{
		node->value = NULL;
		node->key = ft_strdup(env_str);
	}
	else
	{
		i = split - env_str;
		split++;
		node->value = ft_strdup(split);
		env_str[i] = '\0';
		node->key = ft_strdup(env_str);
	}
	return (node);
}

/*
 * Counts the number of nodes in the linked list.
*/
int	stack_len(t_node *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

/*
 * Removes a specified node from the linked list and frees its memory.
 * Adjusts the links of surrounding nodes to maintain list integrity.
*/
void	remove_node(t_node *node)
{
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	ft_free(node->key);
	ft_free(node->value);
	ft_free(node);
}
