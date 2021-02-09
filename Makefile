##
## EPITECH PROJECT, 2020
## Workshop_LL
## File description:
## Makefile
##

SRC_DIR_PATH		=	./src/

COVERAGE_DIR_PATH	=	./coverage/

SRC_MAIN			=	$(addprefix $(SRC_DIR_PATH), main.c)		\

SRC					=	$(addprefix $(SRC_DIR_PATH), dispme.c)	\

OBJ					=	$(SRC_MAIN:.c=.o) $(SRC:.c=.o)

CFLAGS				=	-W -Wall -Wextra -Werror					\

CPPFLAGS			=	-I ./include							\

NAME				=	dispme
NAME_TESTS			=	unit_tests

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

tests_run:	CPPFLAGS += --coverage
tests_run:	LDLIBS += -lcriterion
tests_run:
	@find -name "*.gc*" -delete
	$(CC) -o $(NAME_TESTS) $(SRC) $(TESTS_DIR_PATH)*.c $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	@find -name "*.gc*" -delete
	-./$(NAME_TESTS)
	$(RM) $(NAME_TESTS) test*.gc*
	mkdir -p $(COVERAGE_DIR_PATH)
	mv *.gc* $(COVERAGE_DIR_PATH)

debug:	CPPFLAGS += -g
debug:	re

clean:
	$(RM) $(OBJ)
	$(RM) $(TESTS_DIR_PATH)*.gc*
	$(RM) -r $(COVERAGE_DIR_PATH)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all tests_run coverage debug clean fclean re
