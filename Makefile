TARGET = minishell
HEADER = -I ./Header/
SRC = 	./srcs/library/Lib/ft_alloc.c \
		./srcs/library/Lib/ft_free.c \
		./srcs/library/Lib/ft_itoa.c \
		./srcs/library/Lib/ft_split.c \
		./srcs/library/Lib/ft_strcmp.c \
		./srcs/library/Lib/ft_strcpy.c \
		./srcs/library/Lib/ft_strdup.c \
		./srcs/library/Lib/ft_strjoin.c \
		./srcs/library/Lib/ft_strlen.c \
		./srcs/library/Lib/ft_strncmp.c \
		./srcs/library/Lib/ft_strndup.c \
		./srcs/library/Lib/ft_strnstr.c \
		./srcs/library/Lib/ft_strslen.c \
		./srcs/library/Lib/ft_strtrim.c \
		./srcs/library/Lib/ft_write.c \
		./srcs/library/Lib/ft_write_n.c \
		\
		./srcs/library/Envlib/env.c \
		./srcs/library/Envlib/env_utils.c \
		\
		./srcs/builtin/Cd/cd.c \
		./srcs/builtin/Export/export.c \
		./srcs/builtin/Unset/unset.c \
		\
		./srcs/external/Echo/echo.c \
		./srcs/external/Env/env.c \
		./srcs/external/Pwd/pwd.c \
		\
		./srcs/gnl/get_next_line.c \
		\
		./srcs/Parser/argv_parsing.c \
		./srcs/Parser/parsing.c \
		./srcs/Parser/parsing_utils.c \
		./srcs/Parser/parsing_utils2.c \
		\
		./srcs/Shell/multi/multi.c \
		./srcs/Shell/multi/multi_utils.c \
		./srcs/Shell/multi/work.c \
		./srcs/Shell/exit.c \
		./srcs/Shell/piping.c \
		./srcs/Shell/prompt.c \
		./srcs/Shell/signal.c \
		./srcs/Shell/single.c \
		\
		./srcs/Redirection/redi_utils.c \
		./srcs/Redirection/redirection.c \
		./main.c

OBJS 		=	$(SRC:.c=.o)
FLAG = -Wall -Werror -Wextra

all : $(TARGET)

$(TARGET) : $(OBJS)
	gcc $(FLAG) -o $(TARGET) $(OBJS) $(HEADER)

$(OBJS) : %.o : %.c
	gcc $(FLAG) -c $< -o $@ $(HEADER)

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(TARGET)

re : fclean all