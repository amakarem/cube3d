# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/26 17:14:32 by tkeil             #+#    #+#              #
#    Updated: 2025/03/26 17:14:32 by tkeil            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCSDIR = srcs/
OBJSDIR = objs/
GNLDIR = get_next_line/
INCLUDES = -Iheaders

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
				ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
				ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
				ft_toupper.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
				ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

GNL_SRCS = get_next_line.c

SRCS_MANDATORY_PATHS = $(addprefix $(SRCSDIR), $(SRCS))
SRCS_GNL_PATHS = $(addprefix $(GNLDIR), $(GNL_SRCS))

OBJS = $(addprefix $(OBJSDIR), $(SRCS:.c=.o))
GNL_OBJS = $(addprefix $(OBJSDIR), $(GNL_SRCS:.c=.o))

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS)
		ar -rcs $@ $^

$(OBJSDIR)%.o: $(SRCSDIR)%.c
		mkdir -p $(OBJSDIR)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSDIR)%.o: $(BONUSDIR)%.c
		mkdir -p $(OBJSDIR)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSDIR)%.o: $(GNLDIR)%.c
		mkdir -p $(OBJSDIR)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSDIR):
		mkdir -p $(OBJSDIR)

clean:
		rm -rf $(OBJSDIR)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
