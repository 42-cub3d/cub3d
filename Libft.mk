.PHONY: all bonus clean fclean re

NAME := libft.a

OBJS := a.o b.o

re: fclean
	$(MAKE) all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

$(addprefix obj/,$(OBJS)): obj/%.o: %.c:
	$(CC) $(CFLAGS) -o $@ -c $< -MMD

check_all check_bonus:
	$(AR) $(ARFLAGS) $(NAME) $^

check_all: $(addprefix obj/,$(filter-out _bonus,$(OBJS)))
check_bonus: $(addprefix obj/,$(filter _bonus,$(OBJS)))

all: check_all
bonus: check_bonus
