# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lelajour <lelajour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/10 20:37:24 by lelajour          #+#    #+#              #
#    Updated: 2019/09/16 21:18:49 by lelajour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

CFLAGS = -Werror -Wextra -Wall -g

NAME = libftprintf.a

D_SRC =

D_LIBFT =

SRC1 =    modulo_conv.c c_conv.c di_conv.c di_malloc.c ft_check_arg.c ft_error.c \
					ft_newf.c ft_parsing.c ft_work.c s_conv.c xxo_malloc.c xxo_conv.c\
					ft_fill_struct.c u_conv.c u_malloc.c len_return_scotch.c f_conv.c\

SRC2=			ft_strdup.c ft_strndup.c ft_strcpy.c ft_strncpy.c ft_memset.c \
					ft_itoa_base.c ft_strcmp.c ft_strnew.c ft_strlen.c ft_strchr.c\
					ft_memcpy.c ft_putstr.c ft_strcat.c ft_itoa.c ft_isdigit.c \
					ft_putchar.c ft_strnequ.c ft_strnstr.c ft_strrev.c ft_strrsub.c \
					ft_bzero.c ft_strncmp.c ft_strjoin.c ft_atoi.c itoa_basic.c\
					ft_strequ.c f_toa.c ft_strcdup.c\

SRC_FILL = $(addprefix $(D_SRC), $(SRC1))

SRC_LIB = $(addprefix $(D_LIBFT), $(SRC2))

OBJ = $(SRC_FILL:.c=.o) $(SRC_LIB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "\033[0;32m✅️    $(NAME) executable created."

./%.o: ./%.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "\033[0;32m✅️    $@ created."

clean:
	@rm -f $(OBJ)
	@echo "\033[0;31m🗑️    Deleting object files."

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31m🗑️    Deleting $(NAME) executable."

re: fclean all
