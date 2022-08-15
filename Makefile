# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 16:53:06 by wchae             #+#    #+#              #
#    Updated: 2022/08/15 16:06:37 by yongmkim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME				:=	cub3D

INC_DIR				=	include/

LIB_DIR				= 	library/
LIB_LNK				=	$(LIBFT_LNK) $(MLX_LNK)
LIB_INC				=	$(LIBFT_INC) $(MLX_INC) -I $(INC_DIR)
HDR_INC				=	$(LIB_INC)
###	libft
LIBFT_DIR			=	$(LIB_DIR)libft/
LIBFT_INC			=	-I $(LIBFT_DIR)
LIBFT_LNK			=	-L $(LIBFT_DIR) -l ft
###	mlx
MLX_DIR 			=	$(LIB_DIR)mlx/
MLX_INC				=	-I $(MLX_DIR)
MLX_LNK				=	-L $(MLX_DIR) -l mlx -framework OpenGL -framework AppKit



SRCS_DIR 			=	srcs/

OBJS_DIR 			=	objs/

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
						mlx_mouse_event.c\
						minimap_init.c\
						ray_dda.c\
						ray_work.c\
						ray_init.c\

SRC_B				:=

OBJ					=	$(addprefix $(OBJS_DIR), $(SRC:.c=.o))

OBJ_B				=	$(addprefix $(OBJS_DIR), $(SRC_B:.c=.o))


ifdef _BONUS
	SRC_DIR			=	./source_bonus/
	INC_DIR			=	./include_bonus/
	OBJECT			:=	$(OBJ_B)
else
	SRC_DIR			=	./source/
	INC_DIR			=	./include/
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
	@mkdir -p $(OBJS_DIR)

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


$(OBJS_DIR)%.o		: $(SRCS_DIR)%.c $(INC_DIR)
	$(CC) $(CFLAGS) $(LIB_INC) -c $< -o $@


.PHONY				: clean lclean fclean lfclean re lre bonus
clean				:
	$(RM) $(RMFLAGS)r $(OBJS_DIR)

lclean			: lib_clean

fclean				: clean
	$(RM) $(RMFLAGS) $(NAME)

lfclean			: lib_fclean

re					: fclean
	make all

lre					: lib_re

bonus				: all

.PHONY				: sntz m mem
sntz		:	CFLAGS+=$(SNTZ)
sntz		:	all

m			:	mem
mem			:	CFLAGS+=$(MEM)
mem			:	all

