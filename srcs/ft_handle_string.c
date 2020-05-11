/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anprenat <anprenat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 16:14:19 by anprenat          #+#    #+#             */
/*   Updated: 2020/05/11 16:14:21 by anprenat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_input(char *str, t_flags flags)
{
	int count;

	count = 0;
	if (flags.dot >= 0)
	{
		count += ft_handle_width(flags.dot, ft_strlen(str), 0);
		count += ft_putp(str, flags.dot);
	}
	else
		count += ft_putp(str, ft_strlen(str));
	return (count);
}

int			ft_handle_string(char *str, t_flags flags)
{
	int count;

	count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		count += ft_input(str, flags);
	if (flags.dot >= 0)
		count += ft_handle_width(flags.width, flags.dot, 0);
	else
		count += ft_handle_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		count += ft_input(str, flags);
	return (count);
}
