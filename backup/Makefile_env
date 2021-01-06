TARGET = env
SRC = *.c
HEADER = -I ../../../Header/
FLAG = -Wall -Werror -Wextra
LIB = -L../../library/Envlib -lenv \
		-L../../library/Lib -lft

all : $(TARGET)

$(TARGET) : $(SRC)
	gcc -o $(TARGET) $(SRC) $(HEADER) $(LIB)

fclean :
	rm -rf $(TARGET)

re : fclean all