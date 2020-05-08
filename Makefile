# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Takeo <Takeo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/08 16:57:38 by Takeo             #+#    #+#              #
#    Updated: 2020/05/08 17:29:57 by Takeo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	ft_printf.c \
		srcs/ft_handle_char.c \
		srcs/ft_handle_flags.c \
		srcs/ft_handle_hex.c \
		srcs/ft_handle_int.c \
		srcs/ft_handle_percent.c \
		srcs/ft_handle_pointer.c \
		srcs/ft_handle_string.c \
		srcs/ft_handle_uint.c \
		srcs/ft_handle_width.c \
		srcs/ft_handle.c \
		libft/ft_isdigit.c \
		libft/ft_itoa.c \
		libft/ft_putchar.c \
		libft/ft_putp.c \
		libft/ft_strdup.c \
		libft/ft_strlen.c \
		libft/ft_strlower.c \
		libft/ft_tolower.c \
		libft/ft_unsign_itoa.c \
		libft/ft_utl_base.c 

OBJECTS = ft_printf.o \
		ft_handle_char.o \
		ft_handle_flags.o \
		ft_handle_hex.o \
		ft_handle_int.o \
		ft_handle_percent.o \
		ft_handle_pointer.o \
		ft_handle_string.o \
		ft_handle_uint.o \
		ft_handle_width.o \
		ft_handle.o \
		ft_isdigit.o \
		ft_itoa.o \
		ft_putchar.o \
		ft_putp.o \
		ft_strdup.o \
		ft_strlen.o \
		ft_strlower.o \
		ft_tolower.o \
		ft_unsign_itoa.o \
		ft_utl_base.o

INCLUDES = include/ft_printf.h


all: $(NAME)

$(NAME): $(OBJECTS)

$(OBJECTS): $(SRCS) $(INCLUDES)
	@gcc -Wextra -Werror -Wall -c $(SRCS)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all
bonus: