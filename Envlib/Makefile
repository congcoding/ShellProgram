TARGET = libenv.a
SRC = *.c
OBJ = *.o
HEADER = -I ../Header
FLAG = -Wall -Werror -Wextra
LIB = -L../Lib -lft

all : $(TARGET)

$(TARGET) : $(OBJ)
	ar rc $(TARGET) $(OBJ)

$(OBJ) : $(SRC)
	gcc -c $(SRC) $(HEADER) $(LIB)

clean :
	rm -rf $(OBJ)

fclean :
	rm -rf $(TARGET)

re : fclean all