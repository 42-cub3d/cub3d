# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 17:15:09 by yongmkim          #+#    #+#              #
#    Updated: 2022/07/19 20:22:04 by yongmkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR 	=	./libft/
MLX_DIR		=	./mlx/

#	Make  ======================================================================

all			:
		@make -C $(LIBFT_DIR)
		@make -C $(MLX_DIR)


clean		:
		@make -C $(LIBFT_DIR) clean
		@make -C $(MLX_DIR) clean

fclean		:
		@make -C $(LIBFT_DIR) fclean
		@make -C $(MLX_DIR) fclean

re			:
		@make lfclean
		@make all

clear		:	clean

fclear		:	fclean

.PHONY		:	all clean fclean re clear fclear \
