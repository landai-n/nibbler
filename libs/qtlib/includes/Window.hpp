//
// Window.hpp for nibbler in /home/landai_n/rendu/nibbler/libs/qtlib
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Wed Apr  1 15:04:26 2015 Nathanael Landais
// Last update Wed Apr  1 15:04:26 2015 Nathanael Landais
//

#ifndef			WINDOW_HPP
# define		WINDOW_HPP

# include		<list>
# include		"IWindow.hpp"
# include		"Keyboard.hpp"
# include		"Color.hpp"

class			GraphicsView;
class			QWidget;
class			QGraphicsScene;
class			QGraphicsView;

typedef			std::list<QGraphicsItem *> GraphicsRectList;

class			Window : public IWindow
{
public:
  Window(size_t, size_t, const std::string&);
  virtual		~Window();
  virtual void		open();
  virtual void		close();
  virtual void		flush();
  virtual void		clear();
  virtual bool		isOpen();
  virtual bool		isKeyPressed(Keyboard::Key);
  virtual size_t	getWidth() const;
  virtual size_t	getHeight() const;
  virtual bool		pollEvents();
  virtual void		drawSquare(size_t, size_t, size_t, const Color &);
  virtual void		writeText(size_t, size_t, size_t, const Color &, const std::string &);
private:
  QApplication		*m_app;
  GraphicsView		*m_view;
  QGraphicsScene	*m_scene;
  bool			m_run;
  GraphicsRectList	m_itemList;
};

extern "C"
{
IWindow			*createWindow(size_t, size_t, const std::string&);
}

#endif
