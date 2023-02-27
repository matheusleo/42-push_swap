# Mandatory part
NAME			:= push_swap
INCLUDES		:= -I includes
SOURCE			:= ./source/main.c ./source/push.c ./source/swap.c \
				./source/rotate.c ./source/reverse_rotate.c ./source/error.c \
				./source/parser.c ./source/validator.c ./source/utils.c \
				./source/utils_stack.c ./source/utils_stack_2.c \
				./source/index.c ./source/sort.c ./source/sort_short.c \
				./source/sort_long.c ./source/costs.c ./source/move.c
OBJS_PATH		:= objects
OBJS			:= $(SOURCE:./source/%.c=./$(OBJS_PATH)/%.o)
HEADERS			:= ./includes/push_swap.h ./includes/libft.h

# Bonus part
NAME_BONUS		:= checker
INCLUDES_BONUS	:= -I includes
SOURCE_BONUS	:= ./source_checker/main.c
OBJS_BONUS_PATH	:= objects_bonus
OBJS_BONUS		:= $(SOURCE_BONUS:./checker/%.c=./$(OBJS_BONUS_PATH)/%.o)
HEADERS			:= ./includes/checker.h ./includes/push_swap.h ./includes/libft.h

# General purpose
LIBFT			:= libft.a
CC				:= cc
# C_FLAGS			:= -Wall -Werror -Wextra
RM				:= rm -rf

# Colors
OFF				:= \033[0m
RED				:= \033[0;31m
GREEN			:= \033[0;32m
BLUE			:= \033[0;34m

# Mandatory Rules
all:			$(NAME)

$(NAME):		./libft/$(LIBFT) $(OBJS) $(HEADERS)
				@echo "$(GREEN)All object files from $(NAME) were created!$(OFF)"
				@cp ./libft/$(LIBFT) .
				@$(CC) $(C_FLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT)
				@echo "$(GREEN)$(NAME) files were sucessfully linked!$(OFF)"

./libft/$(LIBFT):
				make -C libft/
				make -C libft/ bonus

./$(OBJS_PATH)/%.o:	./source/%.c
				@mkdir -p $(OBJS_PATH)
				@$(CC) $(C_FLAGS) -c $(INCLUDES) -o $@ $<

clean:
				@$(RM) $(OBJS)
				@$(RM) $(OBJS_PATH)
				@make -C libft/ clean
				@echo "$(RED)The object files from $(NAME) were sucessfully removed!$(OFF)"

fclean:			clean
				@$(RM) $(NAME) $(LIBFT)
				@echo "$(RED)The $(NAME) was removed!$(OFF)"
				@make -C libft/ fclean

re:				fclean all

# Bonus rules
bonus:			$(NAME_BONUS)

$(NAME_BONUS):	./libft/$(LIBFT) $(OBJS_BONUS) $(HEADERS_BONUS)
				cp ./libft/$(LIBFT) .
				$(CC) $(C_FLAGS) $(INCLUDES) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT)

./$(OBJS_BONUS_PATH)/%.o:	./checker/%.c
				@mkdir -p $(OBJS_BONUS_PATH)
				@$(CC) $(C_FLAGS) -c $(INCLUDES) -o $@ $<

# Extra rules
test_1:			$(NAME)
				@cp $(NAME) ./testers/push_swap_tester/

norm:
				@norminette ./source ./includes

.PHONY:			all clean fclean re
