/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anprenat <anprenat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:26:48 by anprenat          #+#    #+#             */
/*   Updated: 2019/12/20 21:31:30 by anprenat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*res;
	int		a;
	int		size;

	a = 0;
	size = ft_strlen(s1);
	if (!(res = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (s1[a])
	{
		res[a] = s1[a];
		a++;
	}
	res[a] = '\0';
	return (res);
}
