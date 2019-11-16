##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	*.c	\

OBJ	=	libmy.a

all	:	$(OBJ)

$(OBJ)	:
	cp *.c lib/my
	gcc -c -g3 lib/my/$(SRC)
	ar rc $(OBJ) *.o

test_run	:
	gcc -c -g3 lib/my/$(SRC)
	ar rc $(OBJ) *.o
	gcc bonus/*.c *.c -L. -lmy -I include --coverage -lcriterion

clean	:
	rm -f *.o
	rm -f *.gcno
	rm -f *.gcda

fclean	: clean
	rm -f $(OBJ)
	rm -f a.out

re	: fclean all