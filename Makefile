TARGET = minishell
SRC = main.c ./Parser/*.c
HEADER = -I ./Header/
FLAG = -Wall -Werror -Wextra
LIB = -L./Lib -lft

all : $(TARGET)

$(TARGET) : $(SRC)
	gcc -o $(TARGET) $(SRC) $(HEADER) $(LIB)