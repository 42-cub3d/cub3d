# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 17:38:27 by yongmkim          #+#    #+#              #
#    Updated: 2022/07/19 17:50:07 by yongmkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#	Color  =====================================================================
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
ORANGE		=	\e[38;5;214m
BLUE_PURPLE	=	\e[38;5;057m
PURPLE		=	\e[38;5;165m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(ORANGE)INFO$(RESET)]
_NAME		=	[$(GREEN)$(NAME)$(RESET)]
_CLEAN		=	[$(BLUE_PURPLE)$(NAME)$(RESET)]
_NAME_B		=	[$(GREEN)$(NAME_B)$(RESET)]
_PROG		=	$(_INFO) [$(ORANGE)$(NAME)$(RESET)] - Compile $(YELLOW)
_DONE		=	$(GREEN)✓$(RESET)

#	Loading bar
SHELL		=	/bin/bash
sp			=	/-\|/
idx			=	0
#	Make  ======================================================================

NAME		=	libmlx.dylib

MODULE_SRC	=	mlx_image.swift \
				mlx_window.swift\
				mlx_init.swift

SRC			=	interface.swift $(MODULE_SRC)

C_SRC		=	mlx_xpm.c \
				mlx_png.c \
				mlx_string_put.c

OBJ_DIR		=	

MODULE_OBJ	=	$(MODULE_SRC:.swift=.swiftmodule)
OBJ			=	$(SRC:.swift=.o)
C_OBJ		=	$(C_SRC:.c=.o)

CFLAGS		=	-O3

INC			=	-I.
HDR			=	mlx.h
#OPTI=-Ounchecked







#	Make  ======================================================================
all			:	$(NAME)

$(NAME)		:	$(MODULE_OBJ) $(OBJ) $(C_OBJ)
	@printf "\b$(_DONE)\n"
	@swiftc $(OPTI) $(INC) -o $(NAME) -emit-library $(OBJ) $(C_OBJ) -lz
	@cp libmlx.dylib ../../
	@printf "$(_SUCCESS) $(_NAME) - all $(_DONE)\n"

$(OBJ_DIR)%.o:	%.c	$(HDR)
	$(eval idx = $(shell expr $(idx) + 1))
	$(eval t_idx = $(shell expr $(idx) % 4 + 1))
	$(eval chr = $(shell echo $(sp) | cut -c $(t_idx)))
	@if [ $(idx) = 1 ]; then\
		printf "   $(_PROG) ";\
	fi
	@printf "\b$(chr)"
	@gcc $(CFLAGS) -o $@ -c $<

$(OBJ_DIR)%.o:	%.swift
	$(eval idx = $(shell expr $(idx) + 1))
	$(eval t_idx = $(shell expr $(idx) % 4 + 1))
	$(eval chr = $(shell echo $(sp) | cut -c $(t_idx)))
	@if [ $(idx) = 1 ]; then\
		printf "   $(_PROG) ";\
	fi
	@printf "\b$(chr)"
	@swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@

$(OBJ_DIR)%.swiftmodule:	%.swift
	$(eval idx = $(shell expr $(idx) + 1))
	$(eval t_idx = $(shell expr $(idx) % 4 + 1))
	$(eval chr = $(shell echo $(sp) | cut -c $(t_idx)))
	@if [ $(idx) = 1 ]; then\
		printf "   $(_PROG) ";\
	fi
	@printf "\b$(chr)"
	@swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@ -emit-module -module-name $(patsubst %.swift,%,$<) -module-link-name $(patsubst %.swift,%,$<)

clean		:
	@rm -f $(OBJ) $(MODULE_OBJ) $(C_OBJ) *.swiftdoc *.swiftsourceinfo *~
	@printf "   $(_INFO) $(_CLEAN) - clean $(_DONE)\n"

fclean		:
	@rm -f $(NAME) $(OBJ) $(MODULE_OBJ) $(C_OBJ) *.swiftdoc *.swiftsourceinfo *~
	@rm -f ../../$(NAME)
	@printf "   $(_INFO) $(_CLEAN) - fclean $(_DONE)\n"

re			:
	@make fclean
	@make all

clear		:	clean

fclear		:	fclean

.PHONY		:	all clean fclean re clear fclear
