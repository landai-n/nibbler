//
// Pause.cpp for  in /home/landai_n/rendu/nibbler
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sat Apr  4 22:40:29 2015 Nathanael Landais
// Last update Sun Apr  5 20:04:12 2015 Benjamin COUILLAUD
//

#include	<unistd.h>
#include	"Pause.hpp"

Pause::Pause(IWindow *p_window) : m_window(p_window)
{
}

GameState::e_state	Pause::exec()
{
  m_state = GameState::PAUSE;
  this->control();
  this->display();
  return (m_state);
}

void		Pause::control()
{
  if (m_window->isKeyPressed(Keyboard::ESC))
    m_state = GameState::PLAY;
}

void		Pause::display()
{
  m_window->clear();
  m_window->writeText(m_window->getWidth() / 2 - 50 * 2.0f,
		      m_window->getHeight() / 2 - 50,
		      50, Color(255, 0, 0), "Pause");
  m_window->flush();
  usleep(100000);
}
