//
// Console.hpp for  in /home/landai_n/rendu/nibbler/includes/Server
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sun Apr  5 15:48:31 2015 Nathanael Landais
// Last update Sun Apr  5 15:48:31 2015 Nathanael Landais
//

#ifndef			__CONSOLE_HPP__
# define		__CONSOLE_HPP__

# include		<ncurses.h>
# include		<unistd.h>
# include		<sys/ioctl.h>
# include		<string>

# define		RED_COLOR       0x1
# define		GREEN_COLOR     0x2
# define		WHITE_COLOR     0x3
# define		BLUE_COLOR	0x4
# define		MV_RIGHT	0x1
# define		MV_LEFT		0x2

class			Console
{
public:
  Console();
  bool			aff_info(std::string message);
  bool			aff_success(std::string message);
  bool			aff_error(std::string message);
  std::string		ask(std::string message, bool hidden = false);
  void			clear();
  void			close();
  static Console	*getInstance();
private:
  int			m_x_aff;
  int			m_y_aff;
  int			m_x_read;
  int			m_y_read;
  bool			m_is_writing;
  bool			m_is_typing;
  WINDOW		*m_win_aff;
  WINDOW		*m_win_read;
  struct winsize	m_sz;
  void			aff(std::string &message);
  void			clear_line(WINDOW *window, int y);
  void			erase_char(char *buffer, int &i);
  bool			special_key(char *buffer, int &i);
};

#endif
