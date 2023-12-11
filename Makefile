CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -g3

HEADERS = cub3d.h

SOURCES = main.c \
		parsing/parsing.c

SRC = srcs/
DIR = objs_deps/
INC = includes/

INCLUDES = -I/$(INCS)

SRCS = $(addprefix $(SRC), $(SOURCES))
OBJS = $(addprefix $(DIR), $(OBJ))
DEPS = $(addprefix $(DIR), $(DEP))
INCS = $(addprefix $(INC), $(HEADERS))

OBJ = $(SOURCES:.c=.o)
DEP = $(SOURCES:.c=.d)

NAME = cub3D

all : $(NAME)

$(NAME) : $(OBJS)
	@make -sC libft
	@make -sC minilibx-linux
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) ./libft/libft.a ./minilibx-linux/libmlx_Linux.a -lXext -lX11
	@echo "Compilation completed"

$(DIR)%.o : $(SRC)%.c | $(DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(DIR) :
	@echo "Start Compilation for $(NAME)"
	@echo "Wait ..."
	@mkdir -p objs_deps
	@mkdir -p objs_deps/parsing

clean :
	@echo "Deleting Objects and Dependencies"
	@make fclean -sC libft
	@make clean -sC minilibx-linux
	@rm -rf $(DIR)

fclean : clean
	@echo "Deleting the executable"
	@rm -f $(NAME)

re : fclean all

-include $(DEPS)

.PHONY : all bonus clean fclean re