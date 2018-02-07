# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncohen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 22:11:22 by ncohen            #+#    #+#              #
#    Updated: 2018/02/06 22:11:24 by ncohen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re
NAME		=	libftprintf.a
CC			=	gcc -c -Wall -Werror -Wextra
PRINTF_DIR	=	./ft_printf/
PRINTF_SRC	=	check_conv.c check_list.c ft_printf.c\
				list_fct.c red_button.c sort_str.c step_by_step.c\
				print_fct.c conv_set.c length_modif_set.c\
				space_x.c ft_itoa_base.c print_fct_chars.c\
				print_fct_wchars.c wchar_set.c

LIB_DIR		=	./libft/
LIB_NAME	=	ft_atoi.c ft_bzero.c ft_div_mod.c ft_exit.c ft_isalnum.c\
				ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
				ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c\
				ft_lstiter.c ft_lstmap.c ft_lstnew.c\
				ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c\
				ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c\
				ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c\
				ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c\
				ft_sqrt.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c\
				ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c\
				ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c\
				ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c\
				ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c\
				ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c\
				ft_strsub.c ft_strtrim.c ft_swap.c ft_tolower.c ft_toupper.c\
				ft_strupcase.c ft_strjoin_nfree.c ft_strsub_nfree.c\
				ft_strdup_nfree.c

PRINTF_NAME =	$(addprefix $(PRINTF_DIR), $(PRINTF_SRC))
LIB_OBJ		=	$(addprefix $(LIB_DIR), $(LIB_NAME:.c=.o))
PRINTF_OBJ	=	$(PRINTF_NAME:.c=.o)

OBJ			=	$(LIB_OBJ) $(PRINTF_OBJ)

all: $(NAME)

$(NAME): $(LIB_OBJ) $(PRINTF_OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\x1b[32m !>>>!COMPILATION COMPLETED!<<<!\x1b[0m"
%.o: %.c
	$(CC) $< -o $@
clean:
	@rm -f $(OBJ)
	@echo "\x1b[31m !>>>!CLEAN COMPLETED!<<<!\x1b[0m"

fclean: clean
	@rm -f $(NAME)

re : fclean all
