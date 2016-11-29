//
// GameOver.cpp for  in /home/landai_n/rendu/nibbler
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sat Apr  4 23:26:28 2015 Nathanael Landais
// Last update Sat Apr  4 23:26:28 2015 Nathanael Landais
//

#include	<iostream>
#include	"GameOver.hpp"

GameOver::GameOver(IWindow *p_window) : m_window(p_window)
{

}

GameState::e_state	GameOver::exec()
{
  m_state = GameState::GAMEOVER;
  this->control();
  this->display();
  return (m_state);
}

void			GameOver::control()
{
  if (m_window->isKeyPressed(Keyboard::ESC))
    m_window->close();
  if (m_window->isKeyPressed(Keyboard::ENTER))
    m_state = GameState::PLAY;
}

void			GameOver::display()
{
  m_window->clear();
  m_window->writeText(m_window->getWidth() / 2 - 50 * 4,
		      m_window->getHeight() / 2 - 50,
		      50, Color(255, 0, 0), "Game Over");
  m_window->flush();
}
