/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libf4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:35:09 by aarchtou          #+#    #+#             */
/*   Updated: 2023/04/08 18:35:10 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		l;
	char	*ptr;

	i = 0;
	l = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (free(s1), NULL);
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i])
		ptr[l++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[l++] = s2[i++];
	ptr[l] = '\0';
	free(s1);
	return (ptr);
}

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}
