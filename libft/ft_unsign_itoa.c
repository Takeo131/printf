/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsign_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Takeo <Takeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 22:07:34 by anprenat          #+#    #+#             */
/*   Updated: 2020/05/08 16:40:45 by Takeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_chiffre(long	int n)
{
	int a;

	a = 1;
	while (n >= 10)
	{
		n = (n / 10);
		a++;
	}
	return (a);
}

static void	convert(char *str, int b, long int c)
{
	if (c >= 10)
	{
		convert(str, (b - 1), (c / 10));
	}
	str[b] = ((c % 10) + 48);
	b++;
	str[b] = '\0';
}

char		*ft_unsign_itoa(unsigned int n)
{
	char		*res;
	int			a;
	int			b;
	long int	c;

	a = 0;
	c = n;
	b = nb_chiffre(c);
	if (n < 0)
	{
		c = (c * -1);
		b = nb_chiffre(c);
		b++;
	}
	if (!(res = malloc(sizeof(char) * b + 1)))
		return (0);
	if (n < 0)
		res[a++] = '-';
	convert(res, (b - 1), c);
	return (res);
}
