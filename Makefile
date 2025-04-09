# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/26 16:25:26 by tkeil             #+#    #+#              #
#    Updated: 2025/04/09 14:55:31 by tkeil            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = cub3D
BONUS_NAME = cub3D_bonus

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
    LIBS = -L/usr/local/lib/ -framework OpenGL -framework AppKit -L$(LIBFTDIR) -lft -L$(MINILIBXDIR) -lmlx -lz
	MINILIBX = $(MINILIBXDIR)/libmlx.a
endif

CLEARING = cleaners.c
INITIALIZATION = heap_allocations.c init_player.c
KEYBOARD = controllers.c
MESSAGING = errors.c
PARSING = parser.c get_textures.c get_colors.c
RAYCASTING = raycast.c draw_slices.c draw_utils.c buffer.c move_player.c
UTILS = utils_staff.c
VALIDATION = validations.c check_textures.c check_colors.c check_map.c utils0.c utils1.c utils2.c utils3.c utils4.c utils5.c utils6.c
MINIMAP = minimap.c

SHARED_DIR = shared/
SHARED_SRCS = $(addprefix parsing/, $(PARSING)) $(addprefix utils/, $(UTILS)) $(addprefix clearing/, $(CLEARING)) \
				$(addprefix messaging/, $(MESSAGING)) $(addprefix keyboard/, $(KEYBOARD)) $(addprefix initialization/, $(INITIALIZATION)) \
				$(addprefix validation/, $(VALIDATION)) $(addprefix raycasting/, $(RAYCASTING))

MANDATORY_DIR = mandatory/
MANDATORY_SRCS = main.c

BONUS_DIR = bonus/
BONUS_SRCS = main.c $(addprefix minimap/, $(MINIMAP))

SRCS_MANDATORY = $(addprefix $(SRCSDIR)$(MANDATORY_DIR), $(MANDATORY_SRCS)) \
					$(addprefix $(SRCSDIR)$(SHARED_DIR), $(SHARED_SRCS)) \

SRCS_BONUS = $(addprefix $(SRCSDIR)$(BONUS_DIR), $(BONUS_SRCS)) \
				$(addprefix $(SRCSDIR)$(SHARED_DIR), $(SHARED_SRCS))

OBJS_MANDATORY = $(SRCS_MANDATORY:$(SRCSDIR)%.c=$(OBJSDIR)%.o)
OBJS_BONUS = $(SRCS_BONUS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)

all: test  $(NAME)
	echo "all wird ausgefuehrt"

test:
	echo $(OBJS_MANDATORY)
	
$(NAME): $(OBJS_MANDATORY) $(MINILIBX) $(LIBFT)
	echo $(SRCS_MANDATORY)
	$(CC) $(CFLAGS) $(OBJS_MANDATORY) $(INCLUDES) $(LIBS) -o $(NAME)

bonus: $(OBJS_BONUS) $(MINILIBX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(INCLUDES) $(LIBS) -o $(BONUS_NAME)

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
	rm -rf $(NAME) $(BONUS_NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
