##
## Makefile for  in /home/poupon_d/rendu/cpp_nibbler/libs/ncursestest
## 
## Made by delphine poupon
## Login   <poupon_d@epitech.net>
## 
## Started on  Sat Apr  4 15:35:41 2015 delphine poupon
##

NAME		=	lib_nibbler_ncurses.so

SRCS		=	srcs/DrawNcurses.cpp
OBJS		=	$(SRCS:.cpp=.o)

INCLUDES	=	-I ../includes/						\
			-I includes/

LIBS		=	-lncurses

CPPFLAGS	=	-W -Wextra -Wall -Wshadow $(INCLUDES)
CPPFLAGS	+=	-fPIC

all:		$(NAME)

$(NAME):
		g++ -shared $(SRCS) $(LIBS) -o $(NAME) $(INCLUDES) $(CPPFLAGS)
		cp $(NAME) ../

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)
		rm -f ../$(NAME)

re:		fclean all

dbg:		CPPFLAGS += -g
dbg:		fclean all
