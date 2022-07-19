# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchae <wchae@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 16:53:06 by wchae             #+#    #+#              #
#    Updated: 2022/07/19 18:52:22 by yongmkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= cub3D

INCLUDE				= .
INCLUDE_FILES		= cub3d.h

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



SRCS_DIR 			= srcs
SRC					= main.c


SRCS				= $(addprefix $(SRCS_DIR)/, $(SRC))
OBJS				= $(SRCS:.c=.o)

RM					= rm -f
CC					= cc
CFLAGS				= -Wall -Wextra -Werror

.PHONY				: all
all					: $(NAME)

$(NAME)				: lib_make $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_LNK) -o $@

.PHONY				: lib_make
lib_make			:
	@make -C $(LIB_DIR) all
					
%.o					: %.c $(INCLUDE)
	$(CC) $(CFLAGS) $(LIB_INC) -I $(INCLUDE) -c $< -o $@

.PHONY				: clean lclean
clean				:
	$(RM) $(OBJS)

lclean			:
	@make -C $(LIB_DIR) lclean

.PHONY				: fclean lfclean
fclean				: clean
	$(RM) $(NAME)

lfclean			:
	@make -C $(LIB_DIR) lfclean

.PHONY				: re lre
re					: fclean
						make all

lre					:
	@make -C $(LIB_DIR) lre

