#include	"Select.hpp"

Select::Select(bool wr, bool rd)
{
  m_timeout.tv_sec = 0;
  m_timeout.tv_usec = 0;
  m_read = rd;
  m_write = wr;
  m_nbfd = 0;
  for (int i(0); i < NB_FD; i++)
    m_fd[i] = -1;
  last_fd = -1;
  FD_ZERO(&m_fdlist);
}

void    Select::add_fd(int fd)
{
  int   i(0);

  while (m_fd[i] != -1)
    i++;
  FD_SET(fd, &m_fdlist);
  if (fd > last_fd)
    last_fd = fd;
  m_fd[i] = fd;
  m_nbfd++;
}

bool    Select::isset(int fd)
{
  if (FD_ISSET(fd, &m_fdlist))
    return (true);
  return (false);
}

void    Select::reset_fd()
{
  int   i(0);

  FD_ZERO(&m_fdlist);
  last_fd = 0;
  while (i < NB_FD)
    {
      if (m_fd[i] != -1)
        FD_SET(m_fd[i], &m_fdlist);
      if (m_fd[i] > last_fd)
        last_fd = m_fd[i];
      i++;
    }
}

void    Select::rm_fd(int fd)
{
  m_nbfd--;
  m_fd[fd + 1] = -1;
}

void	Select::clean_fd()
{
  FD_ZERO(&m_fdlist);
  m_nbfd = 0;
  last_fd = -1;
  for (int i(0); i < NB_FD; i++)
    m_fd[i] = -1;
}

void    Select::set_timeout(int sec, int usec)
{
  m_timeout.tv_sec = sec;
  m_timeout.tv_usec = usec;
}

void    Select::wait()
{
  if (m_read)
    select(last_fd + 1, &m_fdlist, NULL, NULL, &m_timeout);
  else if(m_write)
    select(last_fd + 1, NULL, &m_fdlist, NULL, &m_timeout);
}
