//
// Key.hpp for  in /home/landai_n/rendu/nibbler/libs/qtlib
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sat Apr  4 12:46:08 2015 Nathanael Landais
// Last update Sat Apr  4 12:46:08 2015 Nathanael Landais
//

#ifndef		KEY_HPP
# define	KEY_HPP

#include	<Qt>
#include	"Keyboard.hpp"

typedef struct	s_keyMap
{
  Qt::Key	qtKey;
  Keyboard::Key	libKey;
}		t_keyMap;

#endif
