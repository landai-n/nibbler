//
// BodyPart.cpp for  in /home/couill_b/Dropbox/cpp_nibbler/sources
// 
// Made by Benjamin COUILLAUD
// Login   <couill_b@epitech.net>
// 
// Started on  Sat Apr  4 13:34:34 2015 Benjamin COUILLAUD
// Last update Sat Apr  4 15:49:31 2015 Benjamin COUILLAUD
//

#include		"BodyPart.hpp"

BodyPart::BodyPart(size_t p_x, size_t p_y) :
  Entity(p_x, p_y, SNAKE, Color(10, 190, 40), true)
{
}

BodyPart::~BodyPart()
{

}

void		BodyPart::move(BodyPart::e_direction p_dir, size_t p_x, size_t p_y)
{
  size_t	dirX = (p_dir == RIGHT) ? 1 : (p_dir == LEFT) ? -1 : 0;
  size_t	dirY = (p_dir == TOP) ? -1 : (p_dir == BOTTOM) ? 1 : 0;

  m_x = p_x + dirX;
  m_y = p_y + dirY;
}
