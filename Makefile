TARGET = minishell
SRC = main.c ./Parser/*.c ./Shell/*.c
HEADER = -I ./Header/
FLAG = -Wall -Werror -Wextra
LIB = -L./Env -lenv -L./Lib -lft

all : $(TARGET)

$(TARGET) : $(SRC)
	gcc -o $(TARGET) $(SRC) $(HEADER) $(LIB)