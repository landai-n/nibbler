//
// Wall.hpp for  in /home/landai_n/rendu/nibbler
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sat Apr  4 14:40:45 2015 Nathanael Landais
// Last update Sat Apr  4 14:40:45 2015 Nathanael Landais
//

#include	"Wall.hpp"
#include	"Config.hpp"

Wall::Wall(size_t p_x, size_t p_y) :
  Entity(p_x, p_y, Entity::WALL, Color(0, 100, 255), true, 0)
{

}
