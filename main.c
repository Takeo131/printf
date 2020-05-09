/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Takeo <Takeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:35:39 by Takeo             #+#    #+#             */
/*   Updated: 2020/05/09 17:12:37 by Takeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "include/ft_printf.h"

int		part1(int c)
{
	printf("\n	Part I\n\n");
	printf("   printf c = %c\n", 'c');
	ft_printf("ft_printf c = %c\n\n", 'c');
	printf("   printf s = %s\n", "lol");
	ft_printf("ft_printf s = %s\n\n", "lol");
	printf("   printf p = %p\n", "c");
	ft_printf("ft_printf p = %p\n\n", "c");
	printf("   printf d = %d\n", 1);
	ft_printf("ft_printf d = %d\n\n", 1);
	printf("   printf i = %i\n", 2);
	ft_printf("ft_printf i = %i\n\n", 2);
	printf("   printf u = %u\n", 5);
	ft_printf("ft_printf u = %u\n\n", 5);
	printf("   printf x = %x\n", 42);
	ft_printf("ft_printf x = %x\n\n", 42);
	printf("   printf X = %X\n", 42);
	ft_printf("ft_printf X = %X\n\n", 42);
	c = 0;
	return (c);
}

int		part2(int c)
{
	printf("\n	Part II \n\n");
	ft_printf("\n");
	printf("%d\n", printf("   printf |%-8.6d|%-8.6d|\n", 1025, -1025));
	printf("%d\n", ft_printf("ft_printf |%-8.6d|%-8.6d|\n", 1025, -1025));
	ft_printf("\n");
	printf("%d\n", printf("   printf |%-15.8d|\n", 15));
	printf("%d\n", ft_printf("ft_printf |%-15.8d|\n", 15));
	ft_printf("\n");
	printf("%d\n", printf("|%-20.8d|\n", 15));
	printf("%d\n", ft_printf("|%-20.8d|\n", 15));
	ft_printf("\n");
	printf("%d\n", printf("   printf |%0*d|%0*d|\n", -3, 10012, -3, -10012));
	printf("%d\n", ft_printf("ft_printf |%0*d|%0*d|\n", -3, 10012, -3, -10012));
	ft_printf("\n");
	printf("%d\n", printf("   printf |%-*d|%-*d|\n", 5, 10012, 5, -10012));
	printf("%d\n", ft_printf("ft_printf |%-*d|%-*d|\n", 5, 10012, 5, -10012));
	c = 0;
	return (c);
}

int		main(void)
{
	int c;

	c = 1;
	part1(c);
	part2(c);
	return (c);
}
