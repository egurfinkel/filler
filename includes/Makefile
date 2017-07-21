# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egurfink <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/25 15:36:41 by egurfink          #+#    #+#              #
#    Updated: 2017/04/13 21:54:33 by egurfink         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

INCLUDES = ft_printf.h

SRCS = ft_printf.c \
	   ft_atoi.c \
	   ft_isascii.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_bzero.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_lstadd.c \
	   ft_lstdelone.c \
	   ft_lstiter.c \
	   ft_lstdel.c \
	   ft_itoa.c \
	   ft_memalloc.c \
	   ft_lstnew.c \
	   ft_lstmap.c \
	   ft_memchr.c \
	   ft_memccpy.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memdel.c \
	   ft_memmove.c \
	   ft_putchar.c \
	   ft_memset.c \
	   ft_putchar_fd.c \
	   ft_putendl_fd.c \
	   ft_putendl.c \
	   ft_putnbr.c \
	   ft_putnbr_fd.c \
	   ft_putstr.c \
	   ft_putstr_fd.c \
	   ft_strcat.c \
	   ft_strclr.c \
	   ft_strchr.c \
	   ft_strcmp.c \
	   ft_strdel.c \
	   ft_strcpy.c \
	   ft_strequ.c \
	   ft_striter.c \
	   ft_strdup.c \
	   ft_striteri.c \
	   ft_strlen.c \
	   ft_strjoin.c \
	   ft_strlcat.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strncmp.c \
	   ft_strncpy.c \
	   ft_strncat.c \
	   ft_strnequ.c \
	   ft_strnew.c \
	   ft_strrchr.c \
	   ft_strnstr.c \
	   ft_strsub.c \
	   ft_strstr.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strtrim.c \
	   ft_strsplit.c \
	   ft_itoa_base.c \
	   get_next_line.c \
	   ft_uu.c \
	   ft_xx.c \
	   if_wlpf.c \
	   ft_s.c \
	   ft_ss.c \
	   ft_oo.c \
	   ft_pp.c \
	   ft_call.c \
	   ft_cc.c \
	   ft_countnum.c \
	   ft_idd.c \
	   find_wlpf.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $< -I $(INCLUDES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all
