//
// Console.cpp for  in /home/poupon_d/rendu/cpp_nibbler
// 
// Made by delphine poupon
// Login   <poupon_d@epitech.net>
// 
// Started on  Sun Apr  5 21:59:10 2015 delphine poupon
// Last update Sun Apr  5 21:59:10 2015 delphine poupon
//

#include	<cstdlib>
#include	<cstring>
#include	<iostream>
#include	"Console.hpp"

Console::Console()
{
  initscr();
  start_color();
  init_pair(RED_COLOR, 1, 0);
  init_pair(GREEN_COLOR, 2, 0);
  init_pair(BLUE_COLOR, 6, 0);
  init_pair(WHITE_COLOR, 7, 0);
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &m_sz);
  m_win_aff = newwin(m_sz.ws_row - 2, m_sz.ws_col, 0, 0);
  m_win_read = newwin(2, m_sz.ws_col, m_sz.ws_row - 2, 0);
  m_x_aff = 0;
  m_y_aff = 0;
  m_x_read = 0;
  m_y_read = 1;
  wmove(m_win_read, m_sz.ws_row, 0);
  whline(m_win_read, ACS_HLINE, m_sz.ws_col);
  wmove(m_win_aff, m_y_aff, m_x_aff);
  wmove(m_win_read, m_y_read, m_x_read);
  keypad(m_win_read, TRUE);
  scrollok(m_win_aff, TRUE);
  nodelay(m_win_read, TRUE);
  noecho();
  m_is_writing = false;
  m_is_typing = false;
}

Console			*Console::getInstance()
{
  static Console	instance;

  return (&instance);
}

void    Console::aff(std::string &message)
{
  usleep(5000);
  waddstr(m_win_aff, message.c_str());
  wechochar(m_win_aff, '\n');
  wrefresh(m_win_aff);
}

bool    Console::aff_error(std::string message)
{
  while (m_is_writing);
  m_is_writing = true;
  wattron(m_win_aff, COLOR_PAIR(RED_COLOR));
  message = "[Error] " + message;
  aff(message);
  std::cerr << message << std::endl;
  m_is_writing = false;
  return (false);
}

bool    Console::aff_info(std::string message)
{
  while (m_is_writing);
  m_is_writing = true;
  wattron(m_win_aff, COLOR_PAIR(WHITE_COLOR));
  message = "[Info] " + message;
  aff(message);
  m_is_writing = false;
  return (true);
}

bool    Console::aff_success(std::string message)
{
  while (m_is_writing);
  m_is_writing = true;
  wattron(m_win_aff, COLOR_PAIR(GREEN_COLOR));
  message = "[Success] " + message;
  aff(message);
  m_is_writing = false;
  return (true);
}

std::string     Console::ask(std::string message, bool hidden)
{
  char          buffer[255];
  int           i(0);
  int           sz;

  while (m_is_typing);
  m_is_typing = true;
  memset(buffer, 1, 255);
  wattron(m_win_read, COLOR_PAIR(BLUE_COLOR));
  message = message + ">";
  waddstr(m_win_read, message.c_str());
  sz = message.size();
  m_x_read = sz + 1;
  wmove(m_win_read, m_y_read, m_x_read);
  for (i = 0; i < 255; i++)
    {
      usleep(42);
      while ((buffer[i] = wgetch(m_win_read)) == '\n')
        if (i > 0)
          break ;
      if (buffer[i] == '\n')
        break ;
      if (buffer[i] == ERR)
        {
          i--;
          continue ;
        }
      if (special_key(buffer, i))
        continue ;
      if (hidden)
        wechochar(m_win_read, '*');
      else
        wechochar(m_win_read, buffer[i]);
      buffer[i + 1] = 0;
      m_x_read++;
    }
  m_x_read = 0;
  buffer[i] = 0;
  clear_line(m_win_read, m_y_read);
  clear_line(m_win_read, m_y_read + 1);
  wrefresh(m_win_read);
  wmove(m_win_read, m_y_read, m_x_read);
  m_is_typing = false;
  return ((std::string) buffer);
}

void    Console::clear_line(WINDOW *window, int y)
{
  int   x(0);

  wmove(window, y, 0);
  while (x < m_sz.ws_col)
    {
      wechochar(window, ' ');
      x++;
    }
}

void    Console::clear()
{
  wclear(m_win_aff);
  wrefresh(m_win_aff);
}

void    Console::close()
{
  delwin(m_win_aff);
  delwin(m_win_read);
  endwin();
}

void    Console::erase_char(char *buffer, int &i)
{
  if (i > 0)
    {
      buffer[i] = 0;
      i--;
      wechochar(m_win_read, '\b');
      wechochar(m_win_read, ' ');
      wechochar(m_win_read, '\b');
    }
}

bool    Console::special_key(char *buffer, int &i)
{
  if (buffer[i] == 127 || buffer[i] == 74 || buffer[i] == 7)
    erase_char(buffer, i);
  else if (buffer[i] >= 2 && buffer[i] <= 5)
    return (true);
  else
    return (false);
  i--;
  return (true);
}
