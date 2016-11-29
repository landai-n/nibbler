#include	<sstream>
#include	<unistd.h>
#include	<iostream>
#include	"Play.hpp"
#include	"Config.hpp"

Play::Play(IWindow *p_window, int p_width, int p_height) : m_window(p_window)
{
  this->m_width = p_width;
  this->m_height = p_height;
  this->init();
}

Play::~Play()
{
  delete (m_map);
  delete (m_snake);
}

void		Play::init()
{
  m_score = 0;
  m_map = new Map(this->m_width,this->m_height);
  m_snake = new Snake(*m_map, m_map->getSizeX() / 2, m_map->getSizeY() / 2);
  m_map->generateFood(NULL, Entity::APPLE);
  m_map->generateBorders();
}

void		Play::reset()
{
  delete (m_map);
  delete (m_snake);
  this->init();
}

GameState::e_state	Play::exec()
{
  m_state = GameState::PLAY;
  this->control();
  m_score += m_snake->triggerEntities();
  if (m_snake->collid() == false)
    {
      if (m_snake->crossBorder() == false)
	m_snake->move();
      this->display();
    }
  else
    {
      m_state = GameState::GAMEOVER;
      this->reset();
    }
  return (m_state);
}

void		Play::control()
{
  if (m_window->isKeyPressed(Keyboard::ESC))
    m_state = GameState::PAUSE;
  if (m_window->isKeyPressed(Keyboard::LEFT))
    m_snake->changeDirection(BodyPart::LEFT);
  else if (m_window->isKeyPressed(Keyboard::RIGHT))
    m_snake->changeDirection(BodyPart::RIGHT);
  else if (m_window->isKeyPressed(Keyboard::UP))
    m_snake->changeDirection(BodyPart::TOP);
  else if (m_window->isKeyPressed(Keyboard::DOWN))
    m_snake->changeDirection(BodyPart::BOTTOM);
}

void		Play::display()
{
  std::stringstream     ss;

  ss << m_score;
  m_window->clear();
  m_map->display(*m_window);
  m_snake->display(*m_window);
  m_window->writeText(0, 0, 22, Color(255, 0, 0), "Score: " + ss.str());
  m_window->flush();
  usleep(1000000 / SNAKE_SPEED);
}
