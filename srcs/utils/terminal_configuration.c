/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_configuration.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaattol <etaattol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:06:03 by etaattol          #+#    #+#             */
/*   Updated: 2024/09/17 19:14:36 by etaattol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Sets up the terminal for custom input handling.
 * Disables the echoing of control characters (like ^C) to the terminal.
 * Saves the original terminal settings and applies modified settings.
*/
void	setup_terminal(struct termios *original_termios)
{
	struct termios	new_termios;

	if (!isatty(STDIN_FILENO))
		return ;
	tcgetattr(STDIN_FILENO, original_termios);
	new_termios = *original_termios;
	new_termios.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}

/*
 * Restores the terminal to its original settings.
*/
void	restore_terminal(const struct termios *original_termios)
{
	if (isatty(STDIN_FILENO))
		tcsetattr(STDIN_FILENO, TCSANOW, original_termios);
}
