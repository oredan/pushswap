# **************************************************************************** #
#                                                                              #
#        ::::::    ::::::   :::  ::::::::  ::::::::   :::  ::::::    :::::::   #
#      :+:   :+: :+:   :+: :+: :+:   :+:  :+:    :+: :+: :+:   :+: :+:    :+:  #
#     +:+       +:+       +:+ +:+   +:+  +:+    +:+     +:+       +:+    +:+   #
#    +#+       +:+       +#+ +:+   +#+  +:+    +#+ +:+ +#+       +#+:+:+#+:    #
#   +#+       +#+       +#+   +#+#+#+# #+#+#+#+   +#+ +#+       +#+            #
#  #+#   #+# #+#   #+# #+#            #+#    #+# #+# #+#   #+# #+#    #+#      #
#   ######    ######  ############## ###    ### ###   ######    #######        #
#                                                                              #
# **************************************************************************** #
#                                                                              #
#    Makefile                                 cclarice@student.21-school.ru    #
#                                                                              #
#    Created/Updated: 2021/05/28 18:51:33  /  2021/05/28 18:52:17 @cclarice    #
#                                                                              #
# **************************************************************************** #

# HEAD & NAME
NAME = push_swap
HEAD = src/pushswap.h

# TEST
TEST = test_xtox.c
TSTN = test_xtox

# SRCS
SRCF = src
SRC  = main.c ft_strlen.c ft_atoi.c ft_putint.c game_rules.c visual.c p2b_sort.c
#SRC  = main.c ft_strlen.c ft_atoi.c ft_putint.c game_rules.c visual.c 2sw_sort.c
#SRC  = main.c ft_strlen.c ft_atoi.c ft_putint.c game_rules.c visual.c 1sw_sort.c
SRCS = $(addprefix $(SRCF)/, $(SRC))

# OBJS
OBJF = obj
OBJS = $(patsubst src/%.c, obj/%.o, $(SRCS))

# COMPILE
FLAG = -Wall -Wextra -Werror -O3
MKDR = mkdir -p
SAY  = echo -e
RM   = rm -rf
CC   = clang

# Compile Rule
all: $(OBJF) $(NAME)

$(OBJF):
	@$(MKDR) $(OBJF)

obj/%.o: src/%.c $(HEAD)
	@$(CC) $(FLAG) -c $< -o $@
	@$(SAY) "Compilng \033[33m$< \033[0mto \033[36m$@\033[0m"

$(NAME): $(OBJS)
	@$(CC) $(FLAG) $(OBJS) -o $(NAME)
	@$(SAY) "Compilng \033[35m$(NAME)\033[0m"
	@$(SAY) "Makefile \033[32mDone!\033[0m"

# Clean and recompile rules
clean:
	@$(RM) $(OBJF)
	@$(SAY) "Removing \033[31m$(OBJF)\033[0m"

fclean: clean
	@if [ -a "${NAME}" ]; then $(RM) $(NAME); \
	$(SAY) "Removing \033[31m$(NAME)\033[0m"; fi
	@if [ -a "${NVIS}" ]; then $(RM) $(NVIS); \
	$(SAY) "Removing \033[31m$(NVIS)\033[0m"; fi

re: fclean all
