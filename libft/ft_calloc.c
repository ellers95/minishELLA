/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaattol <etaattol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:56:24 by etaattol          #+#    #+#             */
/*   Updated: 2024/09/17 18:57:07 by etaattol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	bsize;

	bsize = count * size;
	if (bsize < count && bsize < size)
		return (NULL);
	p = (void *)ft_alloc(bsize);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, bsize);
	return (p);
}
