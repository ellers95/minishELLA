/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaattol <etaattol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:47:28 by etaattol          #+#    #+#             */
/*   Updated: 2023/11/20 12:18:06 by etaattol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int i)
{
	return (i >= 0 && i <= 127);
}
