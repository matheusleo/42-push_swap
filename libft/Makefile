# Mandatory part
NAME		:=	libft.a
INCLUDES	:=	libft.h
SOURCE		:=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
				ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
				ft_strlcat.c ft_strlcpy.c  ft_strlen.c  ft_strncmp.c  ft_strnstr.c \
				ft_strrchr.c ft_tolower.c  ft_toupper.c  ft_putchar_fd.c  ft_putstr_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_striteri.c ft_strjoin.c \
				ft_strmapi.c ft_strtrim.c ft_substr.c ft_itoa.c \
				get_next_line.c get_next_line_2.c get_next_line_utils.c \
				ft_printf.c ft_print_char.c ft_print_hex.c ft_print_int.c \
				ft_print_ptr.c ft_print_str.c ft_print_uint.c ft_flag_parser.c utils.c \
				ft_ternary.c ft_replace.c
OBJS		:=	$(SOURCE:.c=.o)

# Bonus part
BONUSSOURCE	:=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
BONUSOBJS	:= $(BONUSSOURCE:.c=.o)

# General purpose
CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror
AR			:=	ar
ARFLAGS		:=	-rcs
RM			:=	rm -rf

# Colors
OFF			:= \033[0m
RED			:= \033[0;31m
GREEN		:= \033[0;32m

$(NAME):	$(OBJS)
			@echo "$(GREEN)All object files were created!$(OFF)"
			@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
			@echo "$(GREEN)$(NAME) files were sucessfully linked!$(OFF)"

%.o:	%.c $(INCLUDES)
		@$(CC) -c $(CFLAGS) -o $@ $<

all:	$(NAME)

bonus:	$(BONUSOBJS)
		@$(AR) $(ARFLAGS) $(NAME) $(BONUSOBJS)
		@echo "$(GREEN)All bonus functions were added to the $(NAME)!$(OFF)"

clean:
		@$(RM) $(OBJS) $(BONUSOBJS)
		@echo "$(RED)The object files were sucessfully removed!$(OFF)"

fclean:	clean
		@$(RM) $(NAME)
		@echo "$(RED)The $(NAME) was removed!$(OFF)"

re:		fclean all

.PHONY:	all clean fclean re
