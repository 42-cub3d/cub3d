# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 16:53:06 by wchae             #+#    #+#              #
#    Updated: 2022/08/16 13:11:54 by yongmkim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME				:=	cub3D

VPATH				:=	$(shell ls -R)

LIB_DIR				= 	library/
LIB_LNK				=	$(LIBFT_LNK) $(MLX_LNK)
LIB_INC				=	$(LIBFT_INC) $(MLX_INC)
###	libft
LIBFT_DIR			=	$(LIB_DIR)libft/
LIBFT_INC			=	-I $(LIBFT_DIR)
LIBFT_LNK			=	-L $(LIBFT_DIR) -l ft
###	mlx
MLX_DIR 			=	$(LIB_DIR)mlx/
MLX_INC				=	-I $(MLX_DIR)
MLX_LNK				=	-L $(MLX_DIR) -l mlx -framework OpenGL -framework AppKit

SRC					:=	main.c\
						parse_init.c\
						parse_get_texture.c\
						parse_get_map.c\
						parse_get_map_error.c\
						parse_get_texture_img.c\
						mlx_tools.c\
						mlx_key_event.c\
						mlx_key_move.c\
						mlx_key_rotate_view.c\
						ray_dda.c\
						ray_work.c\
						ray_init.c\

SRC_B				:=	main_bonus.c\
						parse_init_bonus.c\
						parse_get_texture_bonus.c\
						parse_get_map_bonus.c\
						parse_get_map_error_bonus.c\
						parse_get_texture_img_bonus.c\
						mlx_tools_bonus.c\
						mlx_key_event_bonus.c\
						mlx_key_move_bonus.c\
						mlx_key_rotate_view_bonus.c\
						mlx_mouse_event_bonus.c\
						minimap_init_bonus.c\
						ray_dda_bonus.c\
						ray_work_bonus.c\
						ray_init_bonus.c\
						sprite_init_bonus.c\
						sprite_work_bonus.c\

OBJ_DIR 			=	obj/

OBJ_B				:=	$(addprefix $(OBJ_DIR), $(SRC_B:.c=.o))

OBJ					:=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

ifdef WITH_BONUS
	SRC_DIR			:=	src_bonus/
	INC_DIR			:=	include_bonus/
	OBJECT			:=	$(OBJ_B)
else
	SRC_DIR			:=	src/
	INC_DIR			:=	include/
	OBJECT			:=	$(OBJ)
endif

RM					=	rm
RMFLAGS				=	-f
CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror

SNTZ				=	-g -fsanitize=address -fno-omit-frame-pointer
MEM					=	-g -fsanitize=memory -fsanitize-memory-track-origins \
						-fPIE -pie -fno-omit-frame-pointer





.PHONY				: all lib_make make_dir lib_clean lib_fclean lib_re
all					: make_dir lib_make $(NAME)

make_dir			:
	@mkdir -p $(OBJ_DIR)

$(NAME)				: $(OBJECT)
	$(CC) $(CFLAGS) $(LIB_LNK) $(OBJECT) -o $@

lib_make			:
	@make -C $(LIB_DIR) all

lib_clean			:
	@make -C $(LIB_DIR) clean

lib_fclean			:
	@make -C $(LIB_DIR) fclean

lib_re				:
	@make -C $(LIB_DIR) re

$(OBJ_DIR)%.o		: %.c $(INC_DIR)
	$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -c $< -o $@

.PHONY				: clean lclean fclean lfclean re lre bonus b
clean				:
	$(RM) -rf $(OBJ_DIR)

lclean			: lib_clean

fclean				: clean
	$(RM) $(RMFLAGS) $(NAME)

lfclean			: lib_fclean

re					: fclean
	@make all

lre					: lib_re

b					: bonus
bonus				:
	@make WITH_BONUS=1 all

.PHONY				: sntz m mem norm normr
sntz		:	CFLAGS+=$(SNTZ)
sntz		:
	@make lfclean fclean bonus

m			:	mem
mem			:	CFLAGS+=$(MEM)
mem			:
	@make lfclean fclean bonus

norm		:
	norminette include_bonus include src src_bonus library/libft

normr		:
	norminette -R CheckForbiddenSourceHeader include_bonus include src src_bonus library/libft

