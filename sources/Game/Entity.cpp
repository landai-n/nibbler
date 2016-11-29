//
// Entity.cpp for  in /home/couill_b/Dropbox/cpp_nibbler/sources
// 
// Made by Benjamin COUILLAUD
// Login   <couill_b@epitech.net>
// 
// Started on  Sat Apr  4 13:26:04 2015 Benjamin COUILLAUD
// Last update Sat Apr  4 13:29:30 2015 Benjamin COUILLAUD
//

#include	"Entity.hpp"

Entity::Entity(int p_x, int p_y, e_type p_type, Color p_color, bool p_solid, int p_value)
  : m_color(p_color)
{
  this->m_x = p_x;
  this->m_y = p_y;
  this->m_type = p_type;
  this->m_solid = p_solid;
  this->m_value = p_value;
}

Entity::~Entity()
{

}

int		Entity::getX() const
{
  return (m_x);
}

int		Entity::getY() const
{
  return (m_y);
}

const Color	&Entity::getColor() const
{
  return (m_color);
}

bool		Entity::isSolid() const
{
  return (m_solid);
}

Entity::e_type	Entity::getType() const
{
  return (m_type);
}

int		Entity::getValue() const
{
  return (m_value);
}
