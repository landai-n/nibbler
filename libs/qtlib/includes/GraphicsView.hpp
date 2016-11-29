//
// GraphicsView.hpp for  in /home/landai_n/rendu/nibbler/libs/qtlib
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sat Apr  4 12:23:47 2015 Nathanael Landais
// Last update Sat Apr  4 12:23:47 2015 Nathanael Landais
//

#ifndef				GRAPHICSVIEW_HPP
# define			GRAPHICSVIEW_HPP

#include			<QGraphicsView>
#include			<QKeyEvent>
#include			<list>
#include			"Keyboard.hpp"

class				QGraphicsScene;

class				GraphicsView : public QGraphicsView
{
public:
  GraphicsView(QGraphicsScene *p_scene);
  virtual void			keyPressEvent(QKeyEvent *p_event);
  void				cleanKeys();
  bool				isPressed(Keyboard::Key p_key);
private:
  std::list<Keyboard::Key>	m_keyList;
};

#endif
