//
// Apple.hpp for  in /home/landai_n/rendu/nibbler
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sat Apr  4 14:40:45 2015 Nathanael Landais
// Last update Sat Apr  4 14:40:45 2015 Nathanael Landais
//

#include	"Config.hpp"
#include	"Apple.hpp"

Apple::Apple(size_t p_x, size_t p_y) :
  Entity(p_x, p_y, Entity::APPLE, Color(255, 0, 0), false, APPLE_VALUE)
{

}
