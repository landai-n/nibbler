//
// Key.hpp for  in /home/couill_b/Dropbox/cpp_nibbler/libs/sfmltest
// 
// Made by Benjamin COUILLAUD
// Login   <couill_b@epitech.net>
// 
// Started on  Sat Apr  4 15:05:42 2015 Benjamin COUILLAUD
// Last update Sat Apr  4 15:08:23 2015 Benjamin COUILLAUD
//

#ifndef			KEY_HPP
# define		KEY_HPP

#include		<SFML/Graphics.hpp>
#include		"Keyboard.hpp"

typedef struct		s_keyMap
{
  sf::Keyboard::Key	sfmlKey;
  Keyboard::Key		libKey;
}			t_keyMap;

#endif
