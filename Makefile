# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchae <wchae@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 16:53:06 by wchae             #+#    #+#              #
#    Updated: 2022/07/19 17:52:21 by wchae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= cub3D

INCLUDE				= .
INCLUDE_FILES		= cub3d.h

LIBMLX_DIR			= minilibx_mms_20200219
LIBMLX_INCLUDE		= $(LIBMLX_DIR)
LIBMLX				= libmlx.dylib

SRCS_DIR 			= srcs
SRC					= main.c
SRCS				= $(addprefix $(SRCS_DIR)/, $(SRC))
OBJS				= $(SRCS:.c=.o)

RM					= rm -f
CC					= cc
CFLAGS				= -Wall -Wextra -Werror

.PHONY				: all
all					: $(NAME)

$(NAME)				: $(OBJS) $(LIBMLX) $(INCLUDE_FILES)
	$(CC) $(CFLAGS) $(OBJS) $(LIBMLX) -o $@
					
%.o					: %.c
	$(CC) $(CFLAGS) -I$(LIBMLX_INCLUDE) -I$(INCLUDE) -c $< -o $@

$(LIBMLX)			:
	make -C $(LIBMLX_DIR) all
	cp $(LIBMLX_DIR)/$(LIBMLX) ./

.PHONY				: clean
clean				:
	$(RM) $(OBJS)

.PHONY				: fclean
fclean				: clean
	$(RM) $(NAME) $(LIBMLX)
	# make -C $(LIBMLX_DIR) clean

.PHONY				: re
re					: fclean
						make all