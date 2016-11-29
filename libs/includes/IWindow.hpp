//
// IWindow.hpp for  in /home/couill_b/Dropbox/yo
// 
// Made by Benjamin COUILLAUD
// Login   <couill_b@epitech.net>
// 
// Started on  Mon Mar 30 17:12:31 2015 Benjamin COUILLAUD
// Last update Sat Apr  4 15:58:57 2015 Benjamin COUILLAUD
//

#ifndef		        _IWINDOW_HPP_
# define		_IWINDOW_HPP_

# include		<string>
# include		"Keyboard.hpp"
# include		"Color.hpp"

class			IWindow
{
public:
  virtual ~IWindow() {};
  virtual void		open() = 0;
  virtual void		close() = 0;
  virtual void		flush() = 0;
  virtual void		clear() = 0;
  virtual bool		isOpen() = 0;
  virtual bool		isKeyPressed(Keyboard::Key) = 0;
  virtual size_t	getWidth() const = 0;
  virtual size_t	getHeight() const = 0;
  virtual void		drawSquare(size_t p_x, size_t p_y, size_t p_size, const Color&) = 0;
  virtual void		writeText(size_t p_x, size_t p_y, size_t p_size, const Color& \
  				  , const std::string &) = 0;
};

#endif
