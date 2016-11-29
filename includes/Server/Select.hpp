//
// Select.hpp for  in /home/landai_n/rendu/nibbler/includes/Server
// 
// Made by Nathanael Landais
// Login   <landai_n@epitech.net>
// 
// Started on  Sun Apr  5 15:03:36 2015 Nathanael Landais
// Last update Sun Apr  5 15:03:36 2015 Nathanael Landais
//

#ifndef			__SELECT_HPP__
# define		__SELECT_HPP__

# define		NB_FD		4

# include		"Socket.hpp"

class			Select
{
public:
  Select(bool wr = false, bool rd = true);
  void			add_fd(int fd);
  void			rm_fd(int fd);
  void			reset_fd();
  bool			isset(int fd);
  void			wait();
  void			set_timeout(int sec, int usec);
  void			clean_fd();
private:
  fd_set		m_fdlist;
  struct timeval	m_timeout;
  bool			m_read;
  bool			m_write;
  int			last_fd;
  int			m_nbfd;
  int			m_fd[NB_FD];
};

#endif
