# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchae <wchae@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 16:53:06 by wchae             #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2022/07/20 23:39:14 by wchae            ###   ########.fr        #
=======
#    Updated: 2022/07/20 21:21:53 by yongmkim         ###   ########.fr        #
>>>>>>> bc7b30ae707a3ccd612b88ed11125cf226030601
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

<<<<<<< HEAD
SRC					= main.c parse_map.c get_texture.c get_color.c\
=======
SRC					= get_map.c \
					  check_map_error.c \

>>>>>>> bc7b30ae707a3ccd612b88ed11125cf226030601


OBJECT				= $(addprefix $(OBJS_DIR), $(SRC:.c=.o))


RM					= rm
RMFLAGS				= -f
CC					= cc
CFLAGS				= -Wall -Wextra -Werror -g -fsanitize=address

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

