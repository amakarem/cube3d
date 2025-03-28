# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/26 16:25:26 by tkeil             #+#    #+#              #
#    Updated: 2025/03/28 20:15:21 by tkeil            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = cub3D

SRCSDIR = srcs/
OBJSDIR = objs/
HEADERSDIR = headers
HEADERS_LIBFTDIR = libft/headers/
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
MINILIBXDIR = mlx
MINILIBXLINUXDIR = linux

UNAME = $(shell uname)
# MACOS or Linux
ifeq ($(UNAME), Linux)
	INCLUDES = -I/usr/include -I$(MINILIBXLINUXDIR) -I$(HEADERSDIR) -I$(HEADERS_LIBFTDIR)
	LIBS = -L/usr/lib -L/usr/lib/x86_64-linux-gnu -L$(LIBFTDIR) -lft -L$(MINILIBXLINUXDIR) -lmlx_Linux -L/usr/lib/x86_64-linux-gnu -lXext -lX11 -lm -lbsd
	MINILIBX = $(MINILIBXLINUXDIR)/libmlx_Linux.a
else
    INCLUDES = -I/usr/local/include -I$(MINILIBXDIR) -I$(HEADERSDIR) -I$(HEADERS_LIBFTDIR)
    LIBS = -L/usr/local/lib/ -framework OpenGL -framework AppKit -L$(LIBFTDIR) -lft -L$(MINILIBXDIR) -lmlx
	MINILIBX = $(MINILIBXDIR)/libmlx.a
endif

# ADD here folder names with (PARSING, CLEARING, UTILS, ...), that hold appropriate files for a clean project structure
VALIDATION =  validations.c checkers.c checkers2.c
CLEARING = cleaners.c
UTILS = utils_validating.c utils_staff.c numbers.c
MESSAGING = err_message.c
KEYBOARD = actions.c controllers.c wnd_resize.c
INITIALIZATION = heap_allocations.c
PARSING = parser.c


# ADD the Files to SRCS and add a prefix for a clean structure
SRCS = main.c $(addprefix parsing/, $(PARSING)) $(addprefix utils/, $(UTILS)) $(addprefix clearing/, $(CLEARING)) \
				$(addprefix messaging/, $(MESSAGING)) $(addprefix keyboard/, $(KEYBOARD)) $(addprefix initialization/, $(INITIALIZATION)) \
				$(addprefix validation/, $(VALIDATION))

BONUS_SRCS = main.c $(addprefix parsing/, $(PARSING)) $(addprefix utils/, $(UTILS)) $(addprefix clearing/, $(CLEARING)) \
						$(addprefix messaging/, $(MESSAGING)) $(addprefix keyboard/, $(KEYBOARD)) $(addprefix initialization/, $(INITIALIZATION)) \
						$(addprefix validation/, $(VALIDATION))

SRCS_PATHS = $(addprefix $(SRCSDIR), $(SRCS))
BONUS_PATHS = $(addprefix $(SRCSDIR), $(BONUS_SRCS))

OBJS = $(SRCS_PATHS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)
OBJS_BONUS = $(BONUS_PATHS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)

all: $(NAME)

$(NAME): $(OBJS) $(MINILIBX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)

bonus: $(OBJS_BONUS) $(MINILIBX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(INCLUDES) $(LIBS) -o $(NAME)

# compilation of libmlx.a inside mlx directory
ifeq ($(UNAME), Linux)
    $(MINILIBX):
	$(MAKE) -C $(MINILIBXLINUXDIR)
else
    $(MINILIBX):
	$(MAKE) -C $(MINILIBXDIR)
endif

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFTDIR)

clean:
	rm -rf $(OBJSDIR)
	make -C $(LIBFTDIR) clean
	make -C $(MINILIBXDIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
