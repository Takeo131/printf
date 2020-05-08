/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Takeo <Takeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:55:30 by anprenat          #+#    #+#             */
/*   Updated: 2020/05/08 17:22:47 by Takeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

int		ft_isdigit(int c);
char	*ft_itoa(int n);
int		ft_putchar(char c);
int		ft_putp(char *str, int precision);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strlower(char *str);
int		ft_tolower(int c);
char	*ft_unsign_itoa(unsigned int n);
char	*ft_utl_base(unsigned long long number, int base);

#endif
