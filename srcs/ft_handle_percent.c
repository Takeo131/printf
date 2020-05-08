/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Takeo <Takeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 22:43:01 by nel-alla          #+#    #+#             */
/*   Updated: 2020/05/08 17:26:04 by Takeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_handle_percent(t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_putp("%", 1);
	count += ft_handle_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		count += ft_putp("%", 1);
	return (count);
}
