//
// Snake.cpp for  in /home/landai_n/rendu/nibbler/sources
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sat Apr  4 15:07:13 2015 Nathanael Landais
// Last update Sat Apr  4 15:07:13 2015 Nathanael Landais
//

#include	<iostream>
#include	<cstdlib>
#include	"IWindow.hpp"
#include	"Color.hpp"
#include	"Snake.hpp"
#include	"Apple.hpp"
#include	"Config.hpp"

Snake::Snake(Map &p_map, size_t p_posX, size_t p_posY) :
  Entity(p_posX, p_posY, Entity::SNAKE, Color(0,0,0), true), m_map(p_map)
{
  for (int i = 0; i < SNAKE_BEGIN_SIZE; i++)
    {
      BodyPart	*part = new BodyPart(p_posX + i, p_posY);

      m_body.push_back(part);
    }
  m_dir = BodyPart::LEFT;
}

Snake::~Snake()
{
  for (std::list<BodyPart *>::iterator it = m_body.begin(); it != m_body.end(); it++)
    delete (*it);
  m_body.clear();
}

void		Snake::move()
{
  BodyPart *part = m_body.back();

  part->move(m_dir, m_body.front()->getX(), m_body.front()->getY());
  m_body.pop_back();
  m_body.push_front(part);
}

void		Snake::changeDirection(BodyPart::e_direction p_dir)
{
  if (p_dir - m_dir != 2 && p_dir - m_dir != -2)
    m_dir = p_dir;
}

bool					Snake::collid()
{
  BodyPart				*head = m_body.front();
  std::list<BodyPart *>::iterator	it = m_body.begin();

  ++it;
  for (; it != m_body.end(); ++it)
    {
      if ((*it)->getX() == head->getX() &&
	  (*it)->getY() == head->getY())
	return (true);
    }
  return (m_map.collid(*head));
}

bool		Snake::crossBorder()
{
  BodyPart				*head = m_body.front();
  BodyPart				*part = m_body.back();

  if (head->getX() < 0)
    part->move(m_dir, m_map.getSizeX(), m_body.front()->getY());
  else if (head->getX() > (int)m_map.getSizeX())
    part->move(m_dir, -1, m_body.front()->getY());
  else if (head->getY() < 0)
    part->move(m_dir, m_body.front()->getX(), m_map.getSizeY());
  else if (head->getY() > (int)m_map.getSizeY())
    part->move(m_dir, m_body.front()->getX(), -1);
  else
    return (false);
  m_body.pop_back();
  m_body.push_front(part);
  return (true);
}

int		Snake::triggerEntities()
{
  Entity	*triggered;

  if ((triggered = m_map.triggerEntities(*m_body.front())) == NULL)
    return (0);
  if (triggered->getType() == Entity::APPLE || triggered->getType() == Entity::LEMON)
    return (eat(triggered));
  return (0);
}

int		Snake::eat(Entity *p_entity)
{
  int		value = p_entity->getValue();

  m_map.deleteTriggeredEntity(*p_entity);
  m_map.eatFood();
  if (m_map.getNbFood() <= 0)
    {
      m_map.generateFood(m_body.front(), Entity::APPLE);
      if (rand() % LEMON_RATE == LEMON_RATE -1)
	m_map.generateFood(m_body.front(), Entity::LEMON);
    }
  growUp();
  return (value);
}

void		Snake::growUp()
{
  BodyPart	*part = new BodyPart(m_body.back()->getX() - 1,
				     m_body.back()->getY());

  m_body.push_back(part);
}

void		Snake::display(IWindow &p_window)
{
  size_t	partSizeX = p_window.getWidth() / m_map.getSizeX();
  size_t	partSizeY = p_window.getHeight() / m_map.getSizeY();

  for (std::list<BodyPart *>::iterator it = m_body.begin(); it != m_body.end(); it++)
    {
      p_window.drawSquare((*it)->getX() * partSizeX,
			  (*it)->getY() * partSizeY,
			  partSizeX,
			  (*it)->getColor());
    }
}
