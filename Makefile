CC = gcc
EXEC = contacts
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all : $(EXEC)

%.o : %.c headerfile.h
	$(CC) -o $@ -c $<

$(EXEC) : $(OBJ)
	$(CC) -Wall -Wextra -Werror -o $@ $^ -lncurses

clean :
	rm -rf *.o

fclean : clean
	rm -f $(EXEC)

mrproper : clean
	rm -rf rush-01

re : fclean all

# $@ nom cible
# $< nom premiere dependance
# $^ liste dependances
# $? liste dependance plus recentes que la cible
# $* nom fichier, sans son extension