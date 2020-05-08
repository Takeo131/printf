/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Takeo <Takeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:35:39 by Takeo             #+#    #+#             */
/*   Updated: 2020/05/08 17:31:08 by Takeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		ft_printf(const char *type, ...);

int		main(void)
{
	printf("   printf c = %c\n", 'c');
	ft_printf("ft_printf c = %c\n", 'c');
	printf("   printf s = %s\n", "lol");
	ft_printf("ft_printf s = %s\n", "lol");
	printf("   printf p = %p\n", "c");
	ft_printf("ft_printf p = %p\n", "c");
	printf("   printf d = %d\n", 1);
	ft_printf("ft_printf d = %d\n", 1);
	printf("   printf i = %i\n", 2);
	ft_printf("ft_printf i = %i\n", 2);
	printf("   printf u = %u\n", 5);
	ft_printf("ft_printf u = %u\n", 5);
	printf("   printf x = %x\n", 42);
	ft_printf("ft_printf x = %x\n", 42);
	printf("   printf X = %X\n", 42);
	ft_printf("ft_printf X = %X\n", 42);
	ft_printf("26----------------------\n");
	printf("%d\n", printf("   printf |%-8.6d|%-8.6d|\n", 1025, -1025));
	printf("%d\n", ft_printf("ft_printf |%-8.6d|%-8.6d|\n", 1025, -1025));
	ft_printf("26----------------------\n");
	printf("%d\n", printf("   printf |%-15.8d|\n", 15));
	printf("%d\n", ft_printf("ft_printf |%-15.8d|\n", 15));
	ft_printf("26----------------------\n");
	printf("%d\n", printf("|%-20.8d|\n", 15));
	printf("%d\n", ft_printf("|%-20.8d|\n", 15));
	ft_printf("111-----------------------------------\n");
	printf("%d\n", printf("   printf |%0*d|%0*d|\n", -3, 10012, -3, -10012));
	printf("%d\n", ft_printf("ft_printf |%0*d|%0*d|\n", -3, 10012, -3, -10012));
	ft_printf("119-----------------------------------\n");
	printf("%d\n", printf("   printf |%-*d|%-*d|\n", 5, 10012, 5, -10012));
	printf("%d\n", ft_printf("ft_printf |%-*d|%-*d|\n", 5, 10012, 5, -10012));
	return (0);
}
