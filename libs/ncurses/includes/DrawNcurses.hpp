//
// DrawNcurses.hpp for  in /home/poupon_d/rendu/cpp_nibbler/libs/ncursestest/includes
// 
// Made by delphine poupon
// Login   <poupon_d@epitech.net>
// 
// Started on  Sat Apr  4 15:41:37 2015 delphine poupon
// Last update Sat Apr  4 15:41:37 2015 delphine poupon
//

#ifndef		_DRAWNCURSES_HPP_
#define		_DRAWNCURSES_HPP_

#include	<ncurses.h>
#include	"IWindow.hpp"

#define		RED	0
#define		YELLOW	255
#define		GREEN	190
#define		BLUE	100

class	DrawNcurses : public IWindow
{
public :
  DrawNcurses(size_t p_width, size_t p_height, const std::string &p_name, size_t ratio);
  virtual		~DrawNcurses();
  virtual void		open();
  virtual void		close();
  virtual void		flush();
  virtual void		clear();
  virtual bool		isOpen();
  virtual bool		isKeyPressed(Keyboard::Key p_key);
  virtual size_t	getWidth() const;
  virtual size_t	getHeight() const;
  virtual void		drawSquare(size_t p_x, size_t p_y, size_t p_size, const Color& \
				   color);
  virtual void          writeText(size_t p_x, size_t p_y, size_t p_size, const Color&	\
                                  , const std::string &);

private :
  size_t		m_width;
  size_t		m_height;
  size_t		m_ratio;
  int			m_ch;
  WINDOW		*map;
};

#endif
