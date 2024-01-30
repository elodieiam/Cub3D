CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -g3

HEADERS = cub3d.h

SOURCES = main.c \
		parsing/parsing.c \
		parsing/set_null.c \
		parsing/rgb.c \
		parsing/take_texture.c \
		parsing/fill_texture.c \
		parsing/take_map.c \
		parsing/check_map.c \
		parsing/fill_map.c \
		parsing/search_player.c \
		parsing/check_border.c \
		parsing/set_textures.c \
		parsing/clear.c \
		game/game.c \
		game/background.c \
		player/hook.c \
		player/move_player.c \
		utils/put_pixel.c \
		utils/put_line.c \
		utils/trigonometry.c

HEADERS_BONUS = cub3d_bonus.h

SOURCES_BONUS = main_bonus.c \
		parsing_bonus/parsing_bonus.c \
		parsing_bonus/set_null_bonus.c \
		parsing_bonus/rgb_bonus.c \
		parsing_bonus/take_texture_bonus.c \
		parsing_bonus/fill_texture_bonus.c \
		parsing_bonus/take_map_bonus.c \
		parsing_bonus/check_map_bonus.c \
		parsing_bonus/fill_map_bonus.c \
		parsing_bonus/search_player_bonus.c \
		parsing_bonus/check_border_bonus.c \
		parsing_bonus/set_textures_bonus.c \
		parsing_bonus/clear_bonus.c \
		game_bonus/game_bonus.c \
		game_bonus/background_bonus.c \
		game_bonus/map_buffer_bonus.c \
		game_bonus/minimap_bonus.c \
		player_bonus/hook_bonus.c \
		player_bonus/move_player_bonus.c \
		player_bonus/collision_bonus.c \
		player_bonus/dir_collision_bonus.c \
		player_bonus/move_cam_bonus.c \
		utils_bonus/put_pixel_bonus.c \
		utils_bonus/put_line_bonus.c \
		utils_bonus/trigonometry_bonus.c

SRC = srcs/
DIR = objs_deps/
INC = includes/

SRC_BONUS = srcs_bonus/
DIR_BONUS = objs_deps_bonus/
INC_BONUS = includes_bonus/

INCLUDES = -I/$(INCS)

SRCS = $(addprefix $(SRC), $(SOURCES))
OBJS = $(addprefix $(DIR), $(OBJ))
DEPS = $(addprefix $(DIR), $(DEP))
INCS = $(addprefix $(INC), $(HEADERS))

INCLUDES_BONUS = -I/$(INCS_BONUS)

SRCS_BONUS = $(addprefix $(SRC_BONUS), $(SOURCES_BONUS))
OBJS_BONUS = $(addprefix $(DIR_BONUS), $(OBJ_BONUS))
DEPS_BONUS = $(addprefix $(DIR_BONUS), $(DEP_BONUS))
INCS_BONUS = $(addprefix $(INC_BONUS), $(HEADERS_BONUS))

OBJ = $(SOURCES:.c=.o)
DEP = $(SOURCES:.c=.d)

OBJ_BONUS = $(SOURCES_BONUS:.c=.o)
DEP_BONUS = $(SOURCES_BONUS:.c=.d)

NAME = cub3D

NAME_BONUS = cub3D_bonus

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJS)
	@make -sC libft
	@make -sC minilibx-linux
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) ./libft/libft.a ./minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm
	@echo "Compilation completed"

$(NAME_BONUS) : $(OBJS_BONUS)
	@make -sC libft
	@make -sC minilibx-linux
	@$(CC) $(CFLAGS) $(INCLUDES_BONUS) -o $(NAME_BONUS) $(OBJS_BONUS) ./libft/libft.a ./minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm
	@echo "Compilation completed"

$(DIR)%.o : $(SRC)%.c | $(DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(DIR_BONUS)%.o : $(SRC_BONUS)%.c | $(DIR_BONUS)
	@$(CC) $(CFLAGS) $(INCLUDES_BONUS) -o $@ -c $<

$(DIR) :
	@echo "Start Compilation for $(NAME)"
	@echo "Wait ..."
	@mkdir -p objs_deps
	@mkdir -p objs_deps/parsing
	@mkdir -p objs_deps/utils
	@mkdir -p objs_deps/game
	@mkdir -p objs_deps/player

$(DIR_BONUS) :
	@echo "Start Compilation for $(NAME_BONUS)"
	@echo "Wait ..."
	@mkdir -p objs_deps_bonus
	@mkdir -p objs_deps_bonus/parsing_bonus
	@mkdir -p objs_deps_bonus/utils_bonus
	@mkdir -p objs_deps_bonus/game_bonus
	@mkdir -p objs_deps_bonus/player_bonus

clean :
	@echo "Deleting Objects and Dependencies"
	@make fclean -sC libft
	@make clean -sC minilibx-linux
	@rm -rf $(DIR)
	@rm -rf $(DIR_BONUS)

fclean : clean
	@echo "Deleting the executable"
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)

re : fclean all

-include $(DEPS)
-include $(DEPS_BONUS)

.PHONY : all bonus clean fclean re