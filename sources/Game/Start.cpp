//
// Start.cpp for  in /home/landai_n/rendu/nibbler
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sat Apr  4 22:40:29 2015 Nathanael Landais
// Last update Sat Apr  4 22:40:29 2015 Nathanael Landais
//

#include	"Start.hpp"

Start::Start(IWindow *p_window) : m_window(p_window)
{
}

GameState::e_state	Start::exec()
{
  m_state = GameState::START;
  this->control();
  this->display();
  return (m_state);
}

void		Start::control()
{
  if (m_window->isKeyPressed(Keyboard::UP))
    m_state = GameState::PLAY;
  if (m_window->isKeyPressed(Keyboard::DOWN))
    m_state = GameState::PLAYMULTI;
}

void		Start::display()
{
  m_window->clear();
  m_window->writeText(m_window->getWidth() / 2 - 50 * 2.0f,
		      m_window->getHeight() / 2 - 50,
		      50, Color(255, 0, 0), "Solo");
  m_window->writeText(m_window->getWidth() / 2 - 50 * 2.0f,
		      m_window->getHeight() / 2 + 50,
		      50, Color(255, 0, 0), "Multi");
  m_window->flush();
}
