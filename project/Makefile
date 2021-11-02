NAME		= fdf
NAME_BONUS	=
CC			= clang
FLAGS		= -O3 -Wall -Wextra -Werror -D BUFFER_SIZE=1
RM			= rm -rf
AR			= ar rc
INC			= -I ./inc
LIBFT		= libft/libft.a

SRCS_PATH	= ./src/
OBJS_PATH	= ./objs/

SRCS_NAME	=	main.c read_map.c error.c get_next_line.c get_next_line_utils.c
SRCS		= $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS		= $(addprefix $(OBJS_PATH), $(SRCS_NAME:.c=.o))

B_SRCS_NAME	=
BONUS_SRCS	= $(addprefix $(SRCS_PATH), $(B_SRCS_NAME))
BONUS_OBJS	= $(addprefix $(OBJS_PATH), $(B_SRCS_NAME:.c=.o))

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	$(CC) -c $(FLAGS) $(INC) $< -o $@

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

$(LIBFT):
	@make -C ./libft

clean: clean_libft
	$(RM) $(OBJS_PATH)

clean_libft:
	@make clean -C ./libft

fclean:		clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	$(RM) $(LIBFT)

re:			fclean all

# bonus:	$(LIBFT) $(NAME) $(NAME_BONUS)

# $(NAME_BONUS): $(OBJS_PATH) $(BONUS_OBJS)
# 	$(CC) $(FLAGS) $(BONUS_OBJS) $(LIBFT) -o $(NAME_BONUS)

.PHONY: all clean fclean re #bonus
