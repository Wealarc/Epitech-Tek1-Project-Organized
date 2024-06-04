##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c \
		src/my_putstr.c \
		src/my_getnbr.c \
		src/my_put_nbr.c \
		src/my_strdup.c \
		src/my_strlen.c \
		src/my_strcmp.c \
		src/principales_functions.c \
		src/algorithm_id.c \
		src/algorithm_name.c \
		src/algorithm_type.c \
		src/algorithm_id_reverse.c \
		src/algorithm_name_reverse.c \
		src/algorithm_type_reverse.c \
		src/my_str_isnum.c \
		src/disp_function.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS += -L. -lshell

NAME	=	organized

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
