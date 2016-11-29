//
// Lemon.hpp for  in /home/landai_n/rendu/nibbler
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sat Apr  4 14:40:45 2015 Nathanael Landais
// Last update Sat Apr  4 14:40:45 2015 Nathanael Landais
//

#include	"Lemon.hpp"
#include	"Config.hpp"

Lemon::Lemon(size_t p_x, size_t p_y) :
  Entity(p_x, p_y, Entity::LEMON, Color(255, 255, 0), false, LEMON_VALUE)
{

}
