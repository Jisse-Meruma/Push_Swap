### VAR #######################################################
NAME		:=	push_swap

DEBUGGING	?=

LIBS		:=	./libft/libft.a
MLX			?=	./MLX42

HEADER		:=	-I libft -I includes
HEADERS		:=	libft/libft.h 
OBJ_DIR		:=	./obj
SRC_DIR 	:=	./src

### UTILS #####################################################
CFLAGS	:=	-Wall -Wextra -Werror
RM		:=	rm -rf

SRC 	:=	main.c			\
			stack_valid.c	\
			push.c			\
			swap.c			\
			rotate.c		\
			sort.c			\
			utils.c			\
			sort_three.c

OBJ		:=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
SRC		:=	$(addprefix $(SRC_DIR)/,$(SRC))

## BON_SRC :=

## BON_OBJ :=  $(BON_SRC:_bonus.c=_bonus.o)

## Regular Colors ##############################################
Color_Off	=	"\033[0m"			# Text Reset
Black		=	"\033[0;30m"		# Black
Red			=	"\033[0;31m"		# Red
Green		=	"\033[0;32m"		# Green
Yellow		=	"\033[0;33m"		# Yellow
Blue		=	"\033[0;34m"		# Blue
Purple		=	"\033[0;35m"		# Purple
Cyan		=	"\033[0;36m"		# Cyan
White		=	"\033[0;37m"		# White

### EXEC #######################################################

ifdef DEBUG
	DEBUGGING += -fsanitize=address -g
endif

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(Yellow) Building.. 🏠$(Color_Off)
	@echo -----------------------
	@$(MAKE) -C libft
	@$(CC) $^ $(LIBS) $(DEBUGGING) -o $(NAME) 
	@echo $(Green) Complete ✅ $(Color_Off)
	@echo -----------------------

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@echo $(Purple) Compiling.. 🧱 $< $(Color_Off)
	@echo -----------------------
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@ 

$(OBJ_DIR):
	@mkdir $@

mem: $(OBJ)
	./leaks/memdetect.sh $^ $(LIBS) $(GCC_FLAGS) --args "9 3 7 0 2 90 10 11 -20 -49 -890"

clean:
	@echo $(Cyan) Sweeping.. 💥 $(Color_Off)
	@echo -----------------------
	@$(MAKE) -C libft clean
	@$(RM) $(OBJ) $(BON_OBJ)

fclean:
	@echo $(Red) Thorough sweeping.. 💥 $(Color_Off)
	@echo -----------------------
	@$(MAKE) -C libft fclean
	@$(RM) $(NAME) $(OBJ) $(BON_OBJ)

re: fclean all

.PHONY: clean all fclean re libmlx,