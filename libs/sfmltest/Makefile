##
## Makefile for nibbler in /home/landai_n/rendu/nibbler/src
## 
## Made by Nathanael Landais
## Login   <landai_n@epitech.net>
## 
## Started on  Wed Apr  1 14:52:13 2015 Nathanael Landais
##

NAME		=	lib_nibbler_sfml.so

SRCS		=	srcs/DrawSfml.cpp

OBJS		=	$(SRCS:.cpp=.o)

INCLUDES	=	-I ../includes/						\
			-I includes/

LIBS		=	-lsfml-graphics -lsfml-system -lsfml-window -L ../utils

CPPFLAGS	=	-W -Wextra -Wall -Wshadow $(INCLUDES)
CPPFLAGS	+=	-fPIC

all:		$(NAME)

$(NAME):
		g++ -shared $(SRCS) $(LIBS) -o $(NAME) $(INCLUDES) $(CPPFLAGS)
		cp $(NAME) ..

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME) ../$(NAME)

re:		fclean all

dbg:		CPPFLAGS += -g
dbg:		fclean all
