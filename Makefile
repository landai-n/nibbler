##
## Makefile for snake in /home/poupon_d/rendu/nibbler
## 
## Made by delphine poupon
## Login   <poupon_d@epitech.net>
## 
## Started on  Tue Mar 24 12:17:26 2015 delphine poupon
##

NAME	=	nibbler

CC	=	g++

RM	=	rm -f

SRCS	=	sources/Game/main.cpp		\
		sources/Game/Start.cpp		\
		sources/Game/Game.cpp		\
		sources/Game/LibManager.cpp	\
		sources/Game/Apple.cpp		\
		sources/Game/Lemon.cpp		\
		sources/Game/Wall.cpp		\
		sources/Game/BodyPart.cpp	\
		sources/Game/Entity.cpp		\
		sources/Game/Map.cpp		\
		sources/Game/Snake.cpp		\
		sources/Game/Play.cpp		\
		sources/Game/Pause.cpp		\
		sources/Game/GameOver.cpp	\
		sources/Game/PlayMulti.cpp	\
		sources/Server/Select.cpp	\
		sources/Server/Socket.cpp	\
		sources/Server/ByteBuffer.cpp	\
		sources/Server/Console.cpp	\
		sources/Server/Server.cpp	\

OBJS	=	$(SRCS:.cpp=.o)

HEADER	=	-I ./includes/Game/	\
		-I ./includes/Server/	\
		-I ./includes/		\
		-I libs/includes/	\
		-I libs/qtlib/includes	\

CPPFLAGS=	-Wall -Wextra $(HEADER)

LDFLAGS =	-ldl
LDFLAGS	+=	-lQt5Core -lQt5Widgets -lQt5Gui
LDFLAGS +=	-lncurses -lpthread

LIBS	=	-L libs/utils -L ~/Qt/5.7/gcc_64/lib

all:		$(NAME)

$(NAME):	$(OBJS)
		make re -C libs/sfmltest
		make re -C libs/qtlib
		make re -C libs/ncurses
		$(CC) $(OBJS) -o $(NAME) $(LIBS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)
	make clean -C libs/qtlib
	make clean -C libs/sfmltest
	make clean -C libs/ncurses

fclean: clean
	$(RM) $(NAME)
	make fclean -C libs/qtlib
	make fclean -C libs/sfmltest
	make fclean -C libs/ncurses

dbg:	CPPFLAGS += -g
dbg:	re

re:	fclean all
