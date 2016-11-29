##
## Makefile for nibbler in /home/landai_n/rendu/nibbler/src
## 
## Made by Nathanael Landais
## Login   <landai_n@epitech.net>
## 
## Started on  Wed Apr  1 14:52:13 2015 Nathanael Landais
##

NAME		=	lib_nibbler_qt5.so					\

SRCS		=	srcs/Window.cpp						\
			srcs/Event.cpp						\
			srcs/GraphicsView.cpp					\

OBJS		=	$(SRCS:.cpp=.o)

INCLUDES	=	-I ../includes/						\
			-I includes/
INCLUDES	+=	-I ~/Qt/5.2.1/gcc_64/mkspecs/linux-g++-64		\
			-I ~/Qt/5.2.1/gcc_64/include/				\
			-I ~/Qt/5.2.1/gcc_64/include/QtWidgets			\
			-I ~/Qt/5.2.1/gcc_64/include/QtGui			\
			-I ~/Qt/5.2.1/gcc_64/include/QtCore

DEFINES		=	-DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB

LIBS		=	-lQt5Widgets -lQt5Gui -lQt5Core -lGL -L ~/Qt/5.2.1/gcc_64/lib

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
