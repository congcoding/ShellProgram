TARGET = libft.a
SRC = *.c
OBJ = *.o
HEADER = -I ../../../Header
FLAG = -Wall -Werror -Wextra

all : $(TARGET)

$(TARGET) : $(OBJ)
	ar rc $(TARGET) $(OBJ)

$(OBJ) : $(SRC)
	gcc -c $(SRC) $(HEADER)

clean :
	rm -rf $(OBJ)

fclean :
	rm -rf $(TARGET)

re : fclean all