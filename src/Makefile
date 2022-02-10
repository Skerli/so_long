NAME	= so_long.out
ODIR	= ./bin
SDIR	= ./src
SRCS	= main.c #$(shell find $(SDIR) -name '*.c')
OBJS	= $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))
DEPS	= $(addsuffix .d, $(basename $(OBJS)))
CFLAGS	= -g $(AFL)
CC	= gcc
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
