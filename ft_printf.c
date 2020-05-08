/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Takeo <Takeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:47:08 by Takeo             #+#    #+#             */
/*   Updated: 2020/05/08 13:40:13 by Takeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char				check_type(char *type)
{
	int		a;
	char	c;

	a = 0;
	while (type[a] != '%')
		a++;
	c = type[a + 1];
	return (c);
}

void				ft_putstr(char *s)
{
	int a;

	a = 0;
	if (s != NULL)
	{
		while (s[a])
		{
			ft_putchar(s[a]);
			a++;
		}
	}
}

char				build_tab(char **tab, char *str)
{
	int		a;
	int		b;
	int		c;
	char	d;

	a = 0;
	b = 0;
	while (str[a])
	{
		c = 0;
		if (str[a++] == '%')
		{
			d = str[a];
			tab[b++][c] = str[a++];
		}
		while (str[a] && str[a] != '%')
			tab[b][c++] = str[a++];
		b++;
	}
	return (d);
}

int					ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

char				*ft_strdup(const char *s1)
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

static t_flags		ft_flag(void)
{
	t_flags	flags;

	flags.width = 0;
	flags.star = 0;
	flags.type = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	return (flags);
}

static int			ft_input(const char *str, va_list args)
{
	int		i;
	int		count;
	t_flags	flags;

	i = 0;
	count = 0;
	while (!0)
	{
		flags = ft_flag();
		if (!str[i])
			break ;
		else if (str[i] != '%')
			count += ft_putchar(str[i]);
		else if (str[i] == '%' && str[i + 1])
		{
			i = ft_parse(str, ++i, &flags, args);
			if (ft_isconversion(str[i]))
				count += ft_handle((char)flags.type, flags, args);
			else if (str[i])
				count += ft_putchar(str[i]);
		}
		i++;
	}
	return (count);
}

int					ft_printf(const char *type, ...)
{
	va_list		args;
	const char	*str;
	int			count;

	count = 0;
	if (!(str = ft_strdup(type)))
		return (0);
	va_start(args, type);
	count += ft_input(str, args);
	va_end(args);
	free((char*)str);
	return (count);
}
