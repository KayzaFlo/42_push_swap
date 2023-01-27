# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 15:53:36 by fgeslin           #+#    #+#              #
#    Updated: 2023/01/27 13:18:30 by fgeslin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#####	CONFIG		############################################################
NAME		:= push_swap
LIBFT		:= libft/libft.a
CC			:= gcc
AR			:= ar -rcs
RM			:= rm -f
CFLAGS		= -Wall -Wextra -Werror

#####	SOURCES		############################################################
SRC			=	src/push_swap.c \
				src/push_swap_utils.c \
				src/simple_sort.c \
				src/complexe_sort.c \
				src/sorting_utils.c
SRC_BONUS	=	
OBJ			= $(SRC:.c=.o)
OBJ_BONUS	= $(SRC_BONUS:.c=.o)

#####	Makefile  objs		###################################################
WHITE		:= \033[0m
RED			:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
PINK		:= \033[1;35m
CYAN 		:= \033[1;36m

.c.o:
	@ echo "$(YELLOW)Compiling: $(WHITE)$<"
	@ ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@ echo "$(GREEN)Compilation ${WHITE}of ${CYAN}$(NAME) ${WHITE}..."
	@ $(CC) -o $(NAME) $(OBJ) $(LIBFT) -lmlx -framework OpenGL -framework AppKit
	@ echo "$(CYAN)$(NAME) $(GREEN)created$(WHITE) ✔️"

bonus: $(LIBFT) $(OBJ_BONUS)
	@ echo "$(GREEN)Compilation ${WHITE}of ${CYAN}$(NAME) ${WHITE}..."
	@ $(CC) -o $(NAME) $(OBJ_BONUS) $(LIBFT) -lmlx -framework OpenGL -framework AppKit
	@ echo "$(CYAN)$(NAME) $(GREEN)created$(WHITE) ✔️"

$(LIBFT):
	@ echo "$(GREEN)Compilation ${WHITE}of ${CYAN}${LIBFT} ${WHITE}..."
	@ $(MAKE) -C libft/
	@ echo "$(CYAN)$(LIBFT) $(GREEN)created$(WHITE) ✔️"

clean:
	@ ${RM} $(OBJ) $(OBJ_BONUS)
	@ $(MAKE) clean -C libft/
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(WHITE)and $(CYAN)$(LIBFT) $(WHITE)objs ✔️"

fclean: clean
	@ ${RM} $(NAME)
	@ $(MAKE) fclean -C libft/
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(WHITE)and $(CYAN)$(LIBFT) $(WHITE)binary ✔️"

re: fclean all

rebonus: fclean bonus

.PHONY:		all clean fclean re
