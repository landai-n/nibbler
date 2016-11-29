//
// DrawNcurses.cpp for  in /home/poupon_d/rendu/cpp_nibbler/libs/ncursestest/srcs
// 
// Made by delphine poupon
// Login   <poupon_d@epitech.net>
// 
// Started on  Sat Apr  4 15:47:22 2015 delphine poupon
// Last update Sat Apr  4 15:47:22 2015 delphine poupon
//

#include		<iostream>

#include		"DrawNcurses.hpp"
#include		"Key.hpp"

DrawNcurses::DrawNcurses(size_t p_width, size_t p_height,		\
			 const std::string &p_name, size_t p_ratio)
{
  (void)p_name;
  this->m_ratio = p_ratio;
  this->m_width = p_width / p_ratio;
  this->m_height = p_height / p_ratio;
  this->map = NULL;
  initscr();
  start_color();
  init_pair(1, COLOR_RED, COLOR_RED);
  init_pair(2, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(3, COLOR_GREEN, COLOR_GREEN);
  init_pair(4, COLOR_BLUE, COLOR_BLUE);
  keypad(stdscr, TRUE);
  cbreak();
  noecho();
  curs_set(0);
}

void			DrawNcurses::open()
{
  this->map = newwin(this->m_height, this->m_width, 0, 0);
}

void			DrawNcurses::close()
{
  if (!map)
    return;
  endwin();
  delwin(this->map);
  this->map = NULL;
}

void			DrawNcurses::flush()
{
  if (!map)
    return;
  wrefresh(this->map);
  refresh();
}

void			DrawNcurses::clear()
{
  if (!map)
    return;
  wclear(this->map);
  wrefresh(this->map);
}

bool			DrawNcurses::isOpen()
{
  nodelay(stdscr, TRUE);
  this->m_ch = getch();
  if (this->map)
    return (true);
  return (false);
}

bool			DrawNcurses::isKeyPressed(Keyboard::Key p_key)
{
  static t_keyMap       keyTab[] =
    {
      { KEY_UP, Keyboard::UP },
      { KEY_DOWN, Keyboard::DOWN },
      { KEY_RIGHT, Keyboard::RIGHT },
      { KEY_LEFT , Keyboard::LEFT },
      { QUIT, Keyboard::ESC },
      { ENT, Keyboard::ENTER },
      { USELESS, Keyboard::UNDEFINED }
    };

  for (int i = 0; keyTab[i].libKey != Keyboard::UNDEFINED; ++i)
    if (this->m_ch != ERR)
      {
	if (keyTab[i].libKey == p_key)
	  if (this->m_ch == keyTab[i].curseKey)
	    return (true);
      }
  return (false);
}

size_t			DrawNcurses::getWidth() const
{
  return (this->m_width);
}

size_t			DrawNcurses::getHeight() const
{
  return (this->m_height);
}

void			DrawNcurses::drawSquare(size_t p_x, size_t p_y,				\
						__attribute__((__unused__))size_t p_size,	\
						const Color& color)
{
  if (!map)
    return;
  switch(color.g)
    {
    case RED:
      wattron(this->map, COLOR_PAIR(1));
      mvwprintw(this->map, p_y, p_x, "o");
      wattroff(this->map, COLOR_PAIR(1)); 
      break;
    case YELLOW:
      wattron(this->map, COLOR_PAIR(2));
      mvwprintw(this->map, p_y, p_x, "o");
      wattroff(this->map, COLOR_PAIR(2));
      break;
    case GREEN:
      wattron(this->map, COLOR_PAIR(3));
      mvwprintw(this->map, p_y, p_x, "o");
      wattroff(this->map, COLOR_PAIR(3));
      break;
    case BLUE:
      wattron(this->map, COLOR_PAIR(4));
      mvwprintw(this->map, p_y, p_x, "o");
      wattroff(this->map, COLOR_PAIR(4));
      break;
    }
}

void			DrawNcurses:: writeText(size_t p_x, size_t p_y,				\
						size_t p_size,		\
						 __attribute__((__unused__))const Color& color, \
						 const std::string & msg)
{
  (void) p_x;
  (void) p_y;
  (void) p_size;

  if (!map)
    return;
  if (msg == "Multi")
    mvprintw(2, 1, msg.c_str());
  else
    mvprintw(1, 1, msg.c_str());
}

DrawNcurses::~DrawNcurses()
{
}


extern "C"
{

  IWindow               *createWindow(size_t p_width, size_t p_height, const std::string &p_name, \
				      size_t p_ratio)
  {
    return (new DrawNcurses(p_width, p_height, p_name, p_ratio));
  }

}
