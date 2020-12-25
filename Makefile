TARGET = minishell
SRC = main.c ./Parser/*.c ./Shell/*.c ./Cd/*.c ./Echo/*.c ./Export/*.c ./Env/*.c ./Pwd/*.c
HEADER = -I ./Header/
FLAG = -Wall -Werror -Wextra
LIB = -L./Envlib -lenv -L./Lib -lft

all : $(TARGET)

$(TARGET) : $(SRC)
	gcc -o $(TARGET) $(SRC) $(HEADER) $(LIB)

fclean :
	rm -rf $(TARGET)

re : fclean all