# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 16:47:46 by cskipjac          #+#    #+#              #
#    Updated: 2022/02/15 19:03:35 by cskipjac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long.out
ODIR	= ./bin
SDIR	= ./src
SRCS	= main.c #$(shell find $(SDIR) -name '*.c')
OBJS	= $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))
DEPS	= $(addsuffix .d, $(basename $(OBJS)))
CFLAGS	= -g $(AFL)
CC	= cc
RM	= rm -rf

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ -lmlx -framework OpenGL -framework AppKit $^
	./$@

$(ODIR)/%.o: $(SDIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $< -MMD

-include $(DEPS)
.PHONY: clean
clean:
	$(RM) $(NAME)

.PHONY: fclean
fclean: clean
	$(RM) $(ODIR)

.PHONY: re
re: fclean all
