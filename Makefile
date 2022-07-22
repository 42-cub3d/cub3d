# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 16:53:06 by wchae             #+#    #+#              #
#    Updated: 2022/07/22 10:24:27 by yongmkim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME				= cub3D

INC_DIR				= include/

LIB_DIR		= 	library/
LIB_LNK		=	$(LIBFT_LNK) $(MLX_LNK)
LIB_INC		=	$(LIBFT_INC) $(MLX_INC)
HDR_INC		=	$(LIB_INC)
###	libft
LIBFT_DIR	=	$(LIB_DIR)libft/
LIBFT_INC	=	-I $(LIBFT_DIR)
LIBFT_LNK	=	-L $(LIBFT_DIR) -l ft
###	mlx
MLX_DIR 	=	$(LIB_DIR)mlx/
MLX_INC		=	-I $(MLX_DIR)
MLX_LNK		=	-L $(MLX_DIR) -l mlx -framework OpenGL -framework AppKit



SRCS_DIR 			= srcs/

OBJS_DIR 			= objs/

SRC					= main.c\
					parse_init.c\
					parse_get_texture.c\
					parse_get_color.c\
					parse_get_map.c\
					parse_get_map_error.c\
					mlx_tools.c\
					mlx_key_event.c\

OBJECT				= $(addprefix $(OBJS_DIR), $(SRC:.c=.o))


RM					= rm
RMFLAGS				= -f
CC					= cc
CFLAGS				= -Wall -Wextra -Werror

SNTZ				=	-g -fsanitize=address -fno-omit-frame-pointer
MEM					=	-g -fsanitize=memory -fsanitize-memory-track-origins \
						-fPIE -pie -fno-omit-frame-pointer





.PHONY				: all
all					: obj_dir $(NAME)

$(NAME)				: lib_make $(OBJECT)
	$(CC) $(CFLAGS) $(LIB_LNK) $(OBJECT) -o $@


.PHONY				: lib_make obj_dir
obj_dir				:
	@mkdir -p $(OBJS_DIR)

lib_make			:
	@make -C $(LIB_DIR) all

lib_clean			:
	@make -C $(LIB_DIR) clean

lib_fclean			:
	@make -C $(LIB_DIR) fclean

lib_re				:
	@make -C $(LIB_DIR) re


$(OBJS_DIR)%.o		: $(SRCS_DIR)%.c $(INC_DIR)
	$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -c $< -o $@


.PHONY				: clean lclean
clean				:
	$(RM) -rf $(OBJS_DIR)

lclean			: lib_clean

.PHONY				: fclean lfclean
fclean				: clean
	$(RM) $(RMFLAGS) $(NAME)

lfclean			: lib_fclean

.PHONY				: re lre
re					: fclean
	make all

lre					: lib_re

.PHONY				: sntz m mem
sntz		:	CFLAGS+=$(SNTZ)
sntz		:	all

m			:	mem
mem			:	CFLAGS+=$(MEM)
mem			:	all

