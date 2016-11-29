//
// DrawSfml.hpp for  in /home/couill_b/Dropbox/cpp_nibbler/libs/sfmltest
// 
// Made by Benjamin COUILLAUD
// Login   <couill_b@epitech.net>
// 
// Started on  Wed Apr  1 18:36:41 2015 Benjamin COUILLAUD
// Last update Sat Apr  4 21:35:44 2015 Benjamin COUILLAUD
//

#ifndef	_DRAWSFML_HPP_
#define	_DRAWSFML_HPP_

#include	"SFML/Graphics.hpp"
#include	"IWindow.hpp"
#include	"Key.hpp"
#include	"Color.hpp"

class	DrawSfml : public IWindow
{
public :
  DrawSfml(size_t p_x = 720, size_t p_y = 1280, const std::string &p_name = "Nibbler (SFML)");
  virtual		~DrawSfml();
  virtual void		open();
  virtual void		close();
  virtual void		flush();
  virtual void		clear();
  virtual bool		isOpen();
  virtual bool		isKeyPressed(Keyboard::Key);
  virtual size_t	getWidth() const;
  virtual size_t	getHeight() const;
  virtual void		drawSquare(size_t p_x, size_t p_y, size_t p_size, const Color &p_color);
  virtual void		writeText(size_t p_x, size_t p_y, size_t p_size, const Color &p_color \
				  , const std::string &p_text);
  class			Error : public std::exception
  {
  public:
    Error(const std::string &p_message) throw() : m_message(p_message) {}
    ~Error() throw() {}
    const char *what() const throw() { return (m_message.c_str()); }
  private:
    const std::string	&m_message;
  };
private :
  sf::RenderWindow	*m_window;
  std::string		m_name;
  sf::Font		m_font;
  size_t		m_x;
  size_t		m_y;
};

#endif
