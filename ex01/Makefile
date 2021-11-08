NAME		:= phonebook
SRCS		:= main.cpp \
				Contact.cpp \
				Phonebook.cpp
OBJDIR		:= ./objs/
OBJS		:= $(addprefix $(OBJDIR), $(SRCS:.cpp=.o))
DEPENDS		:= $(addprefix $(OBJDIR), $(SRCS:.cpp=.d))

CXX			:= clang++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -MP

RM			:= rm -f
C_GREEN		:= "\033[32m"
C_DEFAULT	:= "\033[39m"
C_RESET		:= "\033[m"

$(OBJDIR)%.o:	%.cpp
			@if [ ! -d $(OBJDIR) ]; then \
				echo ";; mkdir $(OBJDIR)"; mkdir $(OBJDIR); \
			fi
			$(CXX) $(CXXFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $@
			@echo $(C_GREEN)"=== Make Done ==="$(C_DEFAULT)$(C_REST)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

leaks:
			$(MAKE) CXXFLAGS="$(CXXFLAGS) -g -D LEAKS=1"

-include	$(DEPENDS)

.PHONY:		all clean fclean re
.PHONY:		leaks
