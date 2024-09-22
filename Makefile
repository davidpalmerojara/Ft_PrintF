# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapalmer <dapalmer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/23 18:17:10 by dapalmer          #+#    #+#              #
#    Updated: 2019/12/19 17:47:45 by dapalmer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		libftprintf.a

HEADERS		=		ft_libft.h

SRCS 		=		ft_printf.c				\
					ft_printf_flags.c 		\
					ft_printf_types.c 		\
					ft_printf_char.c 		\
					ft_printf_string.c 		\
					ft_printf_utils.c		\
					ft_printf_number.c		\
					ft_printf_ptr.c			\
					ft_ulltoa.c

FLAGS 		= 		-Wall -Wextra -Werror -g

OBJ			= 		$(SRCS:.c=.o)

LIB 		= 		libft/libft.a

all			: 		$(NAME)

$(LIB)		:
		@make -C libft

$(NAME): $(LIB) $(OBJ)
		@cp libft/libft.a $(NAME)
		@ar rcs $(NAME) $(OBJ) $(LIB)
		@echo "\033[90m[\033[32mft_printf\033[90m]\033[32m Successfully compiled ft_printf.\033[0m"

%.o: %.c
		@$(CC) -I $(HEADERS) -o $@ -c $< $(FLAGS)

clean		:
		@/bin/rm -f $(OBJ)
		@make clean -C libft
		@echo "\033[90m[\033[91mft_printf\033[90m]\033[31m Deleted *.o\033[0m"

fclean		:		clean
		@/bin/rm -f $(NAME)
		@make fclean -C libft
		@echo "\033[90m[\033[91mft_printf\033[90m]\033[31m Deleted $(NAME)\033[0m"

re			:		fclean all

run			:		all
		@gcc -Wall -Werror -Wextra -g libftprintf.a main.c -o printf
		@clear
		@./printf

norme		:
		@echo "\033[91m"
		@norminette srcs/*.c | grep -v "C++ comment"
		@echo "\033[0m"