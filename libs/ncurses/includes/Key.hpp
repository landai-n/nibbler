//
// Key.hpp for  in /home/poupon_d/rendu/cpp_nibbler/libs/ncursestest/includes
// 
// Made by delphine poupon
// Login   <poupon_d@epitech.net>
// 
// Started on  Sat Apr  4 22:13:03 2015 delphine poupon
// Last update Sat Apr  4 22:13:03 2015 delphine poupon
//

#ifndef			KEY_HPP
# define		KEY_HPP

# include		<ncurses.h>
# include		"Keyboard.hpp"

# define		QUIT		113
# define		ENT		10
# define		USELESS		104

typedef struct		s_keyMap
{
  int		        curseKey;
  Keyboard::Key		libKey;
}			t_keyMap;

#endif
