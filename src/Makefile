NAME    := rot13
SRC     := rot13.c
HEADERS := rot13.h

CFLAGS      := -Wall -Werror -Wpedantic -g
OBJ         := $(SRC:.c=.o)
LINUX_LINKS := -lbsd

all: $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LINUX_LINKS) $(CFLAGS)

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.core

fclean:	clean
	-$(RM) $(NAME)


re: fclean all
