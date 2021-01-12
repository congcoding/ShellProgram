TARGET = minishell
HEADER = -I ./Header/
SRC = ./main.c	\
		./srcs/Redirection/*.c	\
		./srcs/builtin/*/*.c \
		./srcs/Parser/*.c \
		./srcs/Shell/*.c \
		./srcs/Shell/multi/*.c \
		./srcs/external/Echo/echo.c \
		./srcs/external/Env/env.c \
		./srcs/external/Pwd/pwd.c
FLAG = -Wall -Werror -Wextra
LIB = -L./srcs/library/Envlib -lenv \
		-L./srcs/library/Lib -lft

all : $(TARGET)

$(TARGET) : $(SRC)
	gcc -o $(TARGET) $(SRC) $(HEADER) $(LIB)

fclean :
	rm -rf $(TARGET)

re : fclean all