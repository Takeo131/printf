/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Takeo <Takeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 04:44:00 by nel-alla          #+#    #+#             */
/*   Updated: 2020/05/08 17:25:46 by Takeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_input(char *str, int num, t_flags flags)
{
	int count;

	count = 0;
	if (flags.dot >= 0 && num < 0 && num != -2147483648)
		ft_putchar('-');
	if (flags.dot >= 0)
		count += ft_handle_width(flags.dot - 1, ft_strlen(str) - 1, 1);
	count += ft_putp(str, ft_strlen(str));
	return (count);
}

static int	ft_put_int(char *str, int num, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_input(str, num, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_handle_width(flags.width, 0, 0);
	}
	else
		count += ft_handle_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		count += ft_input(str, num, flags);
	return (count);
}

int			ft_handle_int(int i, t_flags flags)
{
	int		count;
	int		num;
	char	*str;

	count = 0;
	num = i;
	if (flags.dot == 0 && i == 0)
	{
		count += ft_handle_width(flags.width, 0, 0);
		return (count);
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1) && num != -2147483648)
	{
		if (flags.dot <= -1 && flags.zero == 1)
			ft_putp("-", 1);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		count++;
	}
	str = ft_itoa(i);
	count += ft_put_int(str, num, flags);
	free(str);
	return (count);
}
