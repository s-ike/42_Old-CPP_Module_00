NAME		:= megaphone
SRC			:= megaphone.cpp

CXX			:= clang++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98 -pedantic

all:		$(NAME)

$(NAME):	$(SRC)
			$(CXX) $(CXXFLAGS) $(SRC) -o $@

clean:

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
