//
// GraphicsView.cpp for  in /home/landai_n/rendu/nibbler/libs/qtlib
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sat Apr  4 12:25:24 2015 Nathanael Landais
// Last update Sat Apr  4 15:09:19 2015 Benjamin COUILLAUD
//

#include	<iostream>
#include	"GraphicsView.hpp"
#include	"Key.hpp"

GraphicsView::GraphicsView(QGraphicsScene *p_scene) : QGraphicsView(p_scene)
{

}

void		GraphicsView::keyPressEvent(QKeyEvent *p_event)
{
  static t_keyMap keyTab[] =
    {
      { Qt::Key_Left, Keyboard::LEFT },
      { Qt::Key_Right, Keyboard::RIGHT },
      { Qt::Key_Up, Keyboard::UP },
      { Qt::Key_Down, Keyboard::DOWN },
      { Qt::Key_Escape, Keyboard::ESC },
      { Qt::Key_Return, Keyboard::ENTER },
      { Qt::Key_A, Keyboard::UNDEFINED }
    };

  for (int i = 0; keyTab[i].libKey != Keyboard::UNDEFINED; ++i)
    if (p_event->key() == keyTab[i].qtKey)
      {
	m_keyList.push_back(keyTab[i].libKey);
	return ;
      }
}

void		GraphicsView::cleanKeys()
{
  m_keyList.clear();
}

bool		GraphicsView::isPressed(Keyboard::Key p_key)
{
  for (std::list<Keyboard::Key>::iterator it = m_keyList.begin(); it != m_keyList.end(); ++it)
    if (*it == p_key)
      return(true);
  return (false);
}
