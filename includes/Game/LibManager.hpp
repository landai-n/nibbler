//
// LibManager.hpp for  in /home/landai_n/rendu/nibbler
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Wed Apr  1 17:12:51 2015 Nathanael Landais
// Last update Wed Apr  1 17:12:51 2015 Nathanael Landais
//

#ifndef		LIBMANAGER_HPP
# define	LIBMANAGER_HPP

# include	<dlfcn.h>
# include	<string>
# include	"IWindow.hpp"

class		LibManager
{
public:
  LibManager(const std::string &);
  ~LibManager();
  IWindow	*createWindow(size_t, size_t, const std::string &, size_t);

  class		Error : public std::exception
  {
  public:
    Error(const std::string &p_message) throw() : m_message(p_message) {}
    ~Error() throw() {}
    const char *what() const throw() { return (m_message.c_str()); }
  private:
    const std::string &m_message;
  };

private:
  void		*m_lib;
  IWindow       *(*m_window_creator)(size_t, size_t, const std::string&, size_t);
};

#endif
