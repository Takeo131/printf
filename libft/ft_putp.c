/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Takeo <Takeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:19:43 by Takeo             #+#    #+#             */
/*   Updated: 2020/05/08 17:12:35 by Takeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putp(char *str, int precision)
{
	int i;

	i = 0;
	while (str[i] && i < precision)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}