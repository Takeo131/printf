/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Takeo <Takeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:47:08 by Takeo             #+#    #+#             */
/*   Updated: 2020/05/08 17:20:04 by Takeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static t_flags		ft_flags(void)
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

static int			ft_parse(const char *str, int i,
t_flags *flags, va_list args)
{
	while (str[i])
	{
		if (!ft_isconversion(str[i]) && !ft_isflag(str[i])
		&& !ft_isdigit(str[i]))
			break ;
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '*')
			*flags = ft_width_flag(args, *flags);
		if (str[i] == '.')
			i = ft_dot_flag(str, i, flags, args);
		if (str[i] == '-')
			*flags = ft_minus_flag(*flags);
		if (ft_isdigit(str[i]))
			*flags = ft_digit_flag(str[i], *flags);
		if (ft_isconversion(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

static int			ft_input(const char *str, va_list args)
{
	int		i;
	int		c;
	t_flags flags;

	i = 0;
	c = 0;
	while (!0)
	{
		flags = ft_flags();
		if (!str[i])
			break ;
		else if (str[i] != '%')
			c += ft_putchar(str[i]);
		else if (str[i] == '%' && str[i + 1])
		{
			i = ft_parse(str, ++i, &flags, args);
			if (ft_isconversion(str[i]))
				c += ft_handle((char)flags.type, flags, args);
			else if (str[i])
				c += ft_putchar(str[i]);
		}
		i++;
	}
	return (c);
}

int					ft_printf(const char *type, ...)
{
	va_list		args;
	const char	*str;
	int			c;

	c = 0;
	if (!(str = ft_strdup(type)))
		return (0);
	va_start(args, type);
	c += ft_input(str, args);
	va_end(args);
	free((char*)str);
	return (c);
}
