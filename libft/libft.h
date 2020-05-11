/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anprenat <anprenat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 18:59:28 by anprenat          #+#    #+#             */
/*   Updated: 2020/05/10 18:59:30 by anprenat         ###   ########.fr       */
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
